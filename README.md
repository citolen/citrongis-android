## Prerequisites:

* Android NDK (tested with r10d)
* Android SDK (android-21 and android-10)
* Cocos2d-x 3.3

## Installation

   1. In cocos directory
``` shell
$ python download-deps.py
$ python setup.py
```
   2. Set one more env variable
``` shell
$ export COCOS2DX=`pwd`
```
**or**
``` shell
$ echo "export COCOS2DX=`pwd`" >> ~/.bashrc
```

## Building project
		
1. Import libcocos2dx library project:
	1. File->New->Project->Android Project From Existing Code.
	2. Click **Browse** button and open `cocos2d-x/cocos2dx/cocos/platform/android/java` directory.
	3. Click **Finish** to add project.

Right click on the project -> Properties -> Android.
The project build target should be plateform 2.3.3.

2. Download the Support Libraries
	1. here -> https://developer.android.com/tools/support-library/setup.html
	2. import project : <sdk>/extras/android/support/v7/appcompat

## Install via the shell

Once the project has been generated.
You can install the apk with the following line:
``` shell
$ adb install $(PATH_TO_PROJECT)/bin/CitronGIS.apk
```