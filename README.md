## Prerequisites:

* Android NDK (tested with r9d)
* Android SDK **OR** Eclipse ADT Bundle
* Android AVD target installed
* Cocos2d-x 3.2

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

2. https://developer.android.com/tools/support-library/setup.html

3. Configuration CitronGIS
   	1. CitronGIS->Properties->Android->Library
	   Set the path to the previous project if it is not set.

## Install via the shell

Once the project has been generated.
You can install the apk with the following line:
``` shell
$ adb install $(PATH_TO_PROJECT)/bin/CitronGIS.apk
```