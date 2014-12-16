Simple event

	mousedown
		Triggered by an element when a mouse button is pressed down over it
	mouseup
		Triggered by an element when a mouse button is released over it
	mouseover
		Triggered by an element when the mouse comes over it
	mouseout
		Triggered by an element when the mouse goes out of it
	mousemove
		Triggered by an element on every mouse move over it.

Complexe event

	click
		Triggered by a mouse click: mousedown and then mouseup over an element
	contextmenu
		Triggered by a right-button mouse click over an element.
	dblclick
		Triggered by two clicks within a short time over an element
		
		
Mouse Event contains:
The mouse button: which
Trigger elements: target/relatedTarget
Coordinates relative to the window: clientX/clientY
Coordinates relative to the document: pageX/pageY
		
return false in event handler to prevent the browser to do default behavior

To attach an event:
    addEventListener / attachEvent
    
    
pixi.js
    mousedown = touchstart
    mouseup = touchend
    mouseupoutside = touchendoutside
    mousemove = touchmove