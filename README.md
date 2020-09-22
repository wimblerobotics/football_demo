# football_demo

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
echoing characters. To fix the terminal enter the comment:
    ```
    &lt;tab>reset&lt;tab>
    ```
Where &lt;tab> are actual tab characters.