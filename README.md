## Introduction
--------------------
<img src = http://imgur.com/dccjWQu>
* Rooster allows you to sleep longer.  
Rooster determines when you should wake up according to traffic.  
For instance, if there is an accident along your route, Rooster wakes you up earlier.  
No matter the situation, Rooster wakes you up exactly on time.  

* In this way, **Rooster is smart.**
* This is an alpha release of Rooster to the open source community. I welcome your help and support. If you are a common user, I apologize for my verbosity.

## PhantomJS Praise and Mobile Platforms
----------------------------------------

* Rooster is built in Qt.  
Rooster uses PhantomJS.  
PhantomJS uses Qt's QtWebKit.  

* This makes Rooster redundant. However, a look PhantomJS' source code shows absolute mastery of both Qt and QtWebKit. My use of PhantomJS is equivalent to using a sledgehammer to drive a nail; I believe it's best to streamline PhantomJS (and of course still give them credit) rather than write my own scraper from scratch.

* With all that said, my use of PhantomJS, and therefore my non-use of Android WebKit/iOS WebKit is what is keeping Rooster from mobile platforms. So believe me, writing, or finding, a scraper for both Android and iOS is in the works. Perhaps the community could help.

## Windows
-------------------
* Rooster has been tested on various versions of Windows 7. It *should* work fine on Windows 8.

##OS X
--------------
* As soon as I get in front of a Mac, you guys get Rooster, too.

##Linux
-----------
* Currently, Rooster is distributed for Linux using git and source tarballs. With that said, getting Rooster to work on Linux is still relatively easy:

**Linux Requirements:**
*****
* **GCC**  
On Ubuntu:  
     `sudo apt-get install gcc`  
* **OpenGL**  
For some strange reason, when I tested $make on my Ubuntu 13.10 testbox, I got an error related to the absence of an OpenGL lib:  
    `/usr/bin/ld: cannot find -lGL.`  
I’m still investigating why this lib is needed.  
Anyhow, on Ubuntu, this fixes it:  
`sudo apt-get install libglu1-mesa-dev -y`
* **PhantomJS**  
On Ubuntu:  
    `sudo apt-get install phantomjs`  
Rooster has only been tested using PhantomJS 1.9.0.  
To alpha testers: If you’re using a different version, please search:  
 1. A route that takes less than an hour.  
 2. A route that takes more than an hour.  
… and report back with your PhantomJS version, and whether or not it worked. If it didn’t, please run Rooster in a terminal (./rooster) and provide to me your output.

* **Qt**  
Rooster is built and tested using Qt 5.2.1. It requires at least Qt 5.
Installing Qt is easy, however it is important to note where you install it, because you’re going to be using that path later. Download Qt 5.2.1 from [here](http://qt-project.org/downloads) and run the installer. Again, note where you install Qt.

## Build for Linux
-------------------------------

* Assuming you only have one version of Qt installed, build instructions are (I hope) the same for both 32-bit and 64-bit:

* `cd` to the directory that contains rooster.tar.gz  
 1. `tar xzvf rooster.tar.gz` (if you've downloaded the tarball)  
 2. `cd rooster-0.1`  
 3. `/path/to/Qt5.2.1/5.2.1/gcc<whatever is there>/bin/qmake rooster.pro -r -spec linux-g++`  
 4. `make`
 5. Enjoy! You may either double-click rooster or ./rooster

## To Do
----------------


* **Support for common audio codecs**  
Currently, I’m using QSoundEffect to play the sound file. The reason for this is it reduces the latency between the end of the sound loop and the beginning to microseconds. The downside of this is QSoundEffect only uses .wav files. QMediaPlayer takes many common codecs, however QMediaPlayer seems to dump its buffer, creating undesirable delay. I’m open to ideas.

* **Implement System Volume control.**  
Currently, Rooster depends on you the user to appropriately set your system volume.

* **Fix Linux Icon**  
Currently, I don't see a way to apply Rooster's icon without a make install script.  
Also, the icon could use an upgrade.  

* **Multiple Routes**  
Currently, Rooster relies on Google to choose the best route. Just a bit more code and a menu and a button will allow multiple routes.

* **Public Transit**  
Currently, Rooster only uses driving directions (I’m looking at you, NYC).

* **Presets**  
One for work, one for when the kid has to be driven to school, et cetera.

* **Clean up the Windows UI**  
On some boxes, it’s perfect. On others, everything is small and vertical alignment is off.

* **A Better UI**  
The current program could be an alarm creation dialog, which closes into a more aesthetically pleasing widget. For instance: a Rooster that sleeps, has its eyes half-open when he’s checking traffic, and gets freakishly wide-eyed and wide-mouthed when he’s blaring it’s alarm. But I’m not sure if I want to get all Mr. Paperclip (Clippy) on you guys. Skins would be nice, though.

* **Mobile platforms**  
As I said, writing, or finding, a PhantomJS-like solution for mobile is the highest hurdle.

* **Code refinement**  
This is my first C++ program. It is also my first Qt program. I am sure I could at least use more pointers. Some of you might find swaths of bad practice. I welcome your constructive criticism and scrutiny, for it is best to cut bad habits at the nub.

* **Windows Libs Cleanup**
I'm seeing reports that windeployqt includes more libs than it should. Furthermore, because of the way I set up my Windows dev box, two microsoft c++ libs could go as well. Also, it would be nice to stick all the libs into one folder.

* **Add --version**
Because it's not official unless it's --version official

* **Autodeploy**
Not checking and rechecking that everything has been included would be nice.

* **Math**  
*Perhaps* something like an [exponential growth/decay formula](http://en.wikipedia.org/wiki/Exponential_growth) could be used to predict traffic, which would result in less traffic pings.

## Bugs
---------------
* Honestly, I’ve spent so much time on Rooster that if you found an unlisted functional bug, I’d be pleasantly surprised and very interested.  
* If PhantomJS isn’t found by Rooster, it could segfault or the alarm could set itself to a random value. In Windows, creating this scenario would require you to move phantomjs.exe out of the app’s directory. In Linux, it’s something similar. In essence you the user would know you’d be causing a problem; the same goes for any of the app directory’s files, with the exception of the sound file. In that case, Rooster will kindly prompt you to locate the a sound file.  
* Another possibility is: If you run the program while your RAM is maxxed, the program might close.  

## Snooze
----------
* Here's the way I see it: A snooze button defeats the purpose of Rooster. Personally, I keep my alarm clock across the room, forcing me to wake up before I turn the alarm off. With that said, I don't mind having snooze as an option. But barring the case of a severe traffic jam, I don't see how Rooster can both have Snooze and not be almost equal to the dumb alarm clocks we use daily. Again, I welcome other perspectives on this subject.  

## Future Insight  
------------------
* I'm in a computer engineering university program right now. Wouldn't it be neat if I made this a physical alarm clock as a final project and posted the schematics online?  

## Special Thanks  
-----------------
* Construction workers on I-95.  
[Time Library Coders](https://www.youtube.com/watch?v=-5wpm-gesOY)  
All my parents  
Sarah Autumn  
Mr. S.  
The PhantomJS team  
The Google Maps team  

