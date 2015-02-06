package webm;

import haxe.io.BytesData;
import openfl.utils.ByteArray;

class WebmIoByteArray extends WebmIo 
{
	var data:ByteArray;

	public function new(data:ByteArray) 
	{
		super();
		
		this.data = data;
		create();
	}
	
	override function read(count:Int):BytesData 
	{
		var out:ByteArray = new ByteArray();
		data.readBytes(out, 0, count);
		return out.getData();
	}
	
	override function seek(offset:Float, whence:Int):Int 
	{
		switch (whence) 
		{
			case 0: data.position = Std.int(offset);
			case 1: data.position = Std.int(data.position + offset);
			case 2: data.position = Std.int(data.length + offset);
		}
		return 0;
	}
	
	override function tell():Float 
	{
		return data.position;
	}
}