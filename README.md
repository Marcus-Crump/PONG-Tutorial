# PONG-Tutorial

I followed the majority of [this](https://youtube.com/playlist?list=PL7Ej6SUky135IAAR3PFCFyiVwanauRqj3&si=SmZDuOmT1WZA-zBp)
tutorial series in order to make this game  
At the time I was following this tutorial, I wasn't using Git/GitHub very much  
Because of this I thought it would be beneficial to create a new file for each video in the tutorial  
so that I can better chart my progress and be able to go back and see how the project evolved from  
creating a basic window to a fully interactible game.  

With that being said, as of right now, I never finished the whole series.  
I got far enough to be able to take what I needed from it and start making other software with the  
tools tools and knowledge provided by the tutorial.  

The code seen in these source files lay the foundation to all of my other cpp programs I have  
created thus far.  

## Program Versions and Project Files

### CPP1WindowsandPointers (Video 1)

> This is the first file I created when following the tutorial. The only thing this does is draw  
a window to the screen with the typical functionality that comes with Windows windows.  
I also have some comments placed throughout the program for me to read later as a refresher  
on what I learned.  

### CPP2DrawingGraphics (Video 2)

> At this point in the tutorial we created a [util](#util) and [renderer](#renderer) source file to be included in the main file running our program.  
Utilizing the newly created util and renderer files, we can now draw things inside the window

### CPP3InputMovementandTime (Video 3)

> This version implimented a [game](#game) file that tracks and updates the game state, using  
the [util](#util) file to interpret keyboard inputs.  
The data passed into the game source file is collected in the main CPP3 file from the keyboard  
input. This is the data that the game file uses to detect collision and move sprites depending  
on which button was pressed.  


### util

> Simply, this is just a utility file that defines certain types to save space while writing the program  
as well as the clamp function to be used in the [renderer](#renderer) function  

```cpp
//Ensures val is within the range (min,max) and returns accordingly
inline int
clamp(int min, int val, int max) {
    if(val < min) return min;
    if (val > max) return max;
    return val;
}
```

### renderer

> This is a library of functions that does the actual drawing of objects to the screen

### platformCommon

> This file contains all the buttons and button states to help communicate to the program the state  
of a given button

### game

> This file handles the current game state and will take input passed from the main program file  
and update the window accordingly.  
In the case of pong, checks collision detection, and updates sprite placement based on which  
button states were changed and how they were changed.  
While writing out this file, I realized there are two versions of game.cpp I could have written,  
but I seemed to write over the video 3 version, meaning this version of the file has all the  
functionality of the video 4 version.  
I may change this if I go back to make a more concrete tutorial to make software using the Win23 API  

## How to use

For any given code version, you'll want to compile the CPP<ver#> file, using compiler of your choice,  
I used gpp with minGW. These souce files are the main program files that run will call all other  
files and functions.  
By compiling each version of the code, you will be able to visually see how the code evolved with  
each video in the tutoriall; going from a plain white window to a fully interactive game.
