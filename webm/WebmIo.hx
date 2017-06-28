package webm;

import cpp.Lib;
import haxe.io.BytesData;

class WebmIo 
{
	public var io:Dynamic;
	
	public function new() 
	{}
	
	function create()
	{
		io = hx_create_io(read, seek, tell);
	}
	
	function read(count:Int):BytesData 
	{
		return null;
	}
	
	function seek(offset:Float, whence:Int):Int 
	{
		return 0;
	}
	
	function tell():Float 
	{
		return 0;
	}
	
	static var hx_create_io = Lib.load("extension-webm", "hx_create_io", 3);
}