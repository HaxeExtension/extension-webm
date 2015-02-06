package webm;

import haxe.io.BytesData;
import sys.io.File;
import sys.io.FileInput;

class WebmIoFile extends WebmIo 
{
	var fileInput:FileInput;

	public function new(filePath:String) 
	{
		super();
		
		fileInput = File.read(filePath, true);
		create();
	}
	
	override function read(count:Int):BytesData 
	{
		return fileInput.read(count).getData();
	}
	
	override function seek(offset:Float, whence:Int):Int 
	{
		fileInput.seek(Std.int(offset), switch (whence) 
		{
			case 0: SeekBegin;
			case 1: SeekCur;
			case 2: SeekEnd;
			default: SeekCur;
		});
		return 0;
	}
	
	override function tell():Float 
	{
		return fileInput.tell();
	}
}