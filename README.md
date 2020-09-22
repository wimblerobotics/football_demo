# football_demo

A sampling of code for creating a football came which is visualized
using a terminal window that supports VT-100 emulation.

![Sample output](https://github.com/wimblerobotics/football_demo/tree/master/images/shot1.png)

Requirements
------------
- CMake version >= 2.8.12
- ncurses
    - Can be installed via `sudo apt install ncurses-*`
- pthreads library

Installation
------------
1. Clone the repository
    ```
    git clone git@github.com:wimblerobotics/football_demo.git
    ```

1. Move to the source directory:
    ```
    cd football_demo
    ```

1. Make a build directory and move there
    ```
    mkdir build
    cd build
    ```

1. Execute cmake.
    ```
    cmake ..
    ```

1. Build the code
    ```
    make
    ```

1. Run the code.
    ```
    ./wimble_ball
    ```

After running the demo, it's quite possible that the terminal window no longer is
echoing characters. To fix the terminal enter the command:
    ```
    &lt;tab>reset&lt;tab>
    ```
Where &lt;tab> are actual tab characters.

# Looking at the code
## CMakeLists.txt
This is a simple way to create a required Makefile to build the sample code. 
When you are in the build directory and CmakeLists.txt is in the outer
directory and you execute `cmake ..`, the system will find the required
libraries (e.g., pthread, ncurses) and compile all the required sources 
and then link everything together to create an executable file called `wimble_ball`.

You can look at a tutorial on CMake to see how the elements of the file work, 
and you can probably guess how to add more source files to the list if you
create more code.

## src/main.cpp
This is a simple demo of the classes which could be the beginning of a football
game that is text based and visualized in a terminal window that supports
VT100-style command emulation. 

The demo creates a Football object, which encapsulates the game. It then sets the scores for both teams to 20 and then begins to modify the visual elements every second for 20 seconds.

After every second, the away team score is decremented and the home team score is incremented.

After every second, the home team takes a timeout, reducing the number of underline symbols showing in the home team score window.

From the 5th second through the 10th second, the game clock is allowed to decrement.

Every 5th second, the quarter number is bumped up. When the quarter reaches the 4th quarter, further bumping has no effect.

Every 4th second, the down is advanced. WHen the down reaches the 4th down, further advancing has no effect.

Every 3rd second, the yards to go for the down is incremented by one.

Beginning at the 7th second, the play clock begins to count down.

All of this is just to demonstrate visual behavior for a football game using VT100 emulation in a terminal window.

Of particular interest is that the game clock and the play clock are decremented in real time on their own threads, and the artifact of those close cause the values to be updated in the terminal display.

## src/football.cpp
This encapsulates all the elements of the game. For this demo, it only includes
two scoring objects for the home and away teams and a scoreboard for the game.
There are methods in the class to control the game. As a side effect, the visual
elements of the game are managed, and the will show up in the terminal when the
redraw method is called. Until redraw is called, changes to the game since the last redraw call don't show up visually in the terminal window.

## src/score.cpp
The Score class encapsulates scoring for a team, including visualization. The HOME/AWAY parameter in the constructor call determines where the score will appear in the terminal window. The available functions should be obvious from include/score.h. 

As with the Football class, changes to the scoring state don't show until redraw is called. You shouldn't do that yourself--rather you call redraw on the Football class instance and it will call all the required redraw methods for all the windows used for the game in the terminal window.

## src/clock.cpp
The Clock class encapsulates the quarter name, the game clock, the play clock, the down and the yards to go for the down. The methods for manipulating these values should be obvious from the include/clock.h file, but you should use methods in the Football class to actually manipulate the game as that class will dole out method class to the Clock class as needed.

## src/pauseable_timer.cpp
The PauseableTimer class is used to encapsulate a countdown timer which will stop decrementing when the remaining time reaches zero. This is used for both the game clock and the play clock. The timer can be stopped and started and the remaining time can be reset.


