#!/usr/bin/env python

# Screen Grab utility
# by Mark Kaiser
# A simple script created to archive decklists from the game Hearthstone,
# since it has no built in export feature.

import os
import sys
import time  #might not be needed, could add as timestamp feature later
import ctypes
from ctypes import wintypes
import win32con
from PIL import Image
from PIL import ImageGrab

byref = ctypes.byref
user32 = ctypes.windll.user32

#settings
SAVE_DIR = r'C:\Users\Mark\Desktop'   #r implies raw string text, allows slashes
EDTIOR_PATH = r'C:\WINDOWS\system32\mspaint.exe'  

HOTKEYS = {
	1 : (win32con.VK_F3, win32con.MOD_WIN),
	2 : (win32con.VK_F4, win32con.MOD_WIN)
}


def crop(image):
	boxDims = (1348, 0, 1621, 970)
	image.crop(boxDims)
	return image

def screenshot():
	boxDims = (1348, 0, 1621, 970)
	im = ImageGrab.grab(boxDims)
#	print('Cropping...')
#	cropped = crop(im)
	return im

def save(im):
	saveas=os.path.join(SAVE_DIR,'Screenshot.png')
	im.save(saveas)
	print('Saving screenshot to: ', SAVE_DIR)
	return saveas

def handle_win_F3 ():
	print('Grabbing Screenshot')
	image = screenshot()
	savePath = save(image)
	#editorString='""%s" "%s"'% (EDITOR_PATH,savePath) #Just for Windows right now?
	#Notice the first leading " above? This is the bug in python that no one will admit...
	#os.system(editorString)

def handle_win_F4 ():
	print('Exiting...')
	user32.PostQuitMessage (0)

HOTKEY_ACTIONS = {
  1 : handle_win_F3,
  2 : handle_win_F4
}

def startListener():
	for id, (vk, modifiers) in HOTKEYS.items ():
	#	print("Registering id", id, "for key", vk) #Debug
		if not user32.RegisterHotKey (None, id, modifiers, vk):
			print("Unable to register id", id) 

	try:
		msg = wintypes.MSG ()
		while user32.GetMessageA (byref (msg), None, 0, 0) != 0:
			if msg.message == win32con.WM_HOTKEY:
				action_to_take = HOTKEY_ACTIONS.get (msg.wParam)
				if action_to_take:
					action_to_take ()

			user32.TranslateMessage (byref (msg))
			user32.DispatchMessageA (byref (msg))

	finally:
		for id in HOTKEYS.keys ():
			user32.UnregisterHotKey (None, id)

def main():
	startListener()

main()
