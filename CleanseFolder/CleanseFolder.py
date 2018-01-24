#!/usr/bin/python

import os
from stat import S_ISDIR

'''
Created on January 22nd, 2018
by Mark Kaiser
'''

def inputFolder():
	#take in folder
	print('Hello, please enter the folder to cleanse.')
	folder = input('Enter your folder destination: ')

	#then return it
	return folder

def inputExtensions():
	#take in folder
	print('\nNow, please any file extensions you want to cleanse, comma-seperated.')
	print('Example: .jpg, .gif, .png\n')

	fileExtensions = input('Enter your extensions: ')

	#clear whitespace and convert to a tuple
	fileExtensions = tuple(fileExtensions.replace(" ", ""))

	#then return it
	return fileExtensions

def validateFolder(folder):
	fullpath = os.path.join(folder)
	try:
		st = os.stat(fullpath)
		mode = st.st_mode
	except:
		print('That directory was not found!')
		return False

	if S_ISDIR(mode):
		return True
	else:
		return False

def deleteFiles(folder, fileExtensions):	
	for file in os.listdir(folder):
		filePath = os.path.join(folder,file)
		try:
			if (os.path.isfile(filePath)) and (file.endswith(fileExtensions)):
				print("Deleting: " + filePath)
				os.unlink(filePath)
			elif os.path.isdir(filePath): 
				deleteFiles(filePath, fileExtensions)
		except Exception as e:
 			print(e)	

def main():
	
	folder = inputFolder()
	
	#validate if the given folder is valid
	if validateFolder(folder):
		fileExtensions = inputExtensions()
		deleteFiles(folder, fileExtensions)
		print("Done!")
	#take in file extensions

main()