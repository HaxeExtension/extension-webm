package webm;

import openfl.events.Event;

class WebmEvent extends Event
{
	public static inline var PLAY = "play";
	public static inline var STOP = "stop";
	public static inline var COMPLETE = "complete";
	public static inline var RESTART = "restart";
	
	public function new(type:String, bubbles:Bool=false, cancelable:Bool=false) 
	{
		super(type, bubbles, cancelable);
	}
}