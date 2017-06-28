package webm;

import cpp.Lib;
import haxe.io.Bytes;
import haxe.io.BytesData;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.PixelSnapping;
import openfl.events.Event;
import openfl.events.SampleDataEvent;
import openfl.media.Sound;
import openfl.media.SoundChannel;
import openfl.utils.ByteArray;
import openfl.utils.Endian;

using Std;

class WebmPlayer extends Bitmap
{
	static inline var BYTES_PER_SAMPLE = 4 * 8192;
	static var BLANK_BYTES:ByteArray;
	static var SKIP_STEP_LIMIT = 0;

	public var frameRate(default, null):Float;
	public var duration(default, null):Float;

	var vpxDecoder:VpxDecoder;
	var webmDecoder:Dynamic;
	var outputSound:ByteArray;
	var soundChannel:SoundChannel;
	var sound:Sound;
	var soundEnabled:Bool;
	var skippedSteps = 0;
	
	var startTime = 0.0;
	var lastDecodedVideoFrame = 0.0;
	var lastRequestedVideoFrame = 0.0;
	var playing = false;
	var renderedCount = 0;

	public function new(io:WebmIo, soundEnabled:Bool = true)
	{
		super(null);
		
		this.soundEnabled = soundEnabled;

		if (BLANK_BYTES == null)
		{
			BLANK_BYTES = new ByteArray();
			for (i in 0...BYTES_PER_SAMPLE)
				BLANK_BYTES.writeByte(0);
		}

		pixelSnapping = PixelSnapping.AUTO;
		smoothing = true;

		vpxDecoder = new VpxDecoder();

		webmDecoder = hx_webm_decoder_create(io.io, soundEnabled);
		
		var info = hx_webm_decoder_get_info(webmDecoder);
		bitmapData = new BitmapData(info[0].int(), info[1].int(), false, 0);
		frameRate = info[2];
		duration = info[3];

		if (soundEnabled)
		{
			outputSound = new ByteArray();
			outputSound.endian = Endian.LITTLE_ENDIAN;
		}
	}

	public function generateSound(e:SampleDataEvent)
	{
		if (e.data == null)
			e.data = new ByteArray();

		var totalOutputLength = outputSound.length;
		var outputBytesToWrite = Math.min(totalOutputLength, BYTES_PER_SAMPLE).int();
		var blankBytesToWrite = BYTES_PER_SAMPLE - outputBytesToWrite;

		if (blankBytesToWrite > 0)
			e.data.writeBytes(BLANK_BYTES, 0, blankBytesToWrite);

		if (outputBytesToWrite > 0)
		{
			e.data.writeBytes(outputSound, 0, outputBytesToWrite);

			if (outputBytesToWrite < totalOutputLength)
			{
				var remainingBytes = new ByteArray();
				remainingBytes.writeBytes(outputSound, outputBytesToWrite);
				outputSound = remainingBytes;
			}
			else
			{
				outputSound.clear();
			}
		}
	}
	
	public function getElapsedTime():Float
	{
		return haxe.Timer.stamp() - startTime;
	}
	
	public function restart()
	{
		stop(true);
		renderedCount = 0;
		lastDecodedVideoFrame = 0;
		hx_webm_decoder_restart(webmDecoder);
		this.dispatchEvent(new Event(WebmEvent.RESTART));
		play();
	}
	
	public function play()
	{
		if (!playing)
		{
			startTime = haxe.Timer.stamp();

			if (soundEnabled)
			{
				sound = new Sound();
				sound.addEventListener(SampleDataEvent.SAMPLE_DATA, generateSound);
				soundChannel = sound.play();
			}
		
			addEventListener(Event.ENTER_FRAME, onSpriteEnterFrame);
			playing = true;
			dispatchEvent(new WebmEvent(WebmEvent.PLAY));
		}
	}

	public function stop(?pRestart:Bool = false)
	{
		if (playing)
		{
			if (soundEnabled)
			{
				this.sound.removeEventListener(SampleDataEvent.SAMPLE_DATA, generateSound);
				this.sound.close();
			}
			playing = false;
			if (!pRestart) dispatchEvent(new WebmEvent(WebmEvent.STOP));
			dispose();
		}
	}
	
	function onSpriteEnterFrame(e:Event)
	{
		skippedSteps = 0;
		stepVideoFrame();
	}
	
	function stepVideoFrame()
	{
		var startRenderedCount = renderedCount;
		var elapsedTime = getElapsedTime ();

		while (hx_webm_decoder_has_more(webmDecoder) && lastDecodedVideoFrame < elapsedTime)
		{
			lastRequestedVideoFrame = elapsedTime;
			hx_webm_decoder_step(webmDecoder, decodeVideoFrame, outputAudioFrame);
			if (renderedCount > startRenderedCount) break;
		}
		
		if (!hx_webm_decoder_has_more(webmDecoder))
		{
			dispatchEvent(new WebmEvent(WebmEvent.COMPLETE));
			stop();
		}
	}

	function decodeVideoFrame(time:Float, data:BytesData)
	{
		lastDecodedVideoFrame = time;
		++renderedCount;
		
		vpxDecoder.decode(data);
		
		if (skippedSteps < SKIP_STEP_LIMIT && playing && lastDecodedVideoFrame < lastRequestedVideoFrame)
		{
			skippedSteps++;
			stepVideoFrame();
		}
		else
		{
			vpxDecoder.getAndRenderFrame(bitmapData);
		}
	}
	
	function outputAudioFrame(time:Float, data:BytesData)
	{
		if (!soundEnabled) return;
		outputSound.position = outputSound.length;
		outputSound.writeBytes(ByteArray.fromBytes(Bytes.ofData(data)));
		outputSound.position = 0;
	}
	
	function dispose()
	{
		removeEventListener(Event.ENTER_FRAME, onSpriteEnterFrame);
		
		if (sound != null)
		{
			sound.removeEventListener(SampleDataEvent.SAMPLE_DATA, generateSound);
			sound = null;
		}
		
		if (soundChannel != null)
		{
			soundChannel.stop();
			soundChannel = null;
		}
		
		if (bitmapData != null)
		{
			bitmapData.dispose();
			bitmapData = null;
		}
	}
	
	static var hx_webm_decoder_create:Dynamic -> Bool -> Dynamic = Lib.load("extension-webm", "hx_webm_decoder_create", 2);
	static var hx_webm_decoder_get_info:Dynamic -> Array<Float> = Lib.load("extension-webm", "hx_webm_decoder_get_info", 1);
	static var hx_webm_decoder_has_more:Dynamic -> Bool = Lib.load("extension-webm", "hx_webm_decoder_has_more", 1);
	static var hx_webm_decoder_step = Lib.load("extension-webm", "hx_webm_decoder_step", 3);
	static var hx_webm_decoder_restart = Lib.load("extension-webm", "hx_webm_decoder_restart", 1);
}