# Terminal Width Detection in Linux using C
This repository demonstrates how to determine the width of a terminal window on Linux systems using the C programming language. The program utilizes the ```ioctl()``` function along with the ```winsize``` structure from the ```<sys/ioctl.h>``` header file.
___
## Overview
The goal is to retrieve the number of columns (width) that are available for text output within the current terminal session. This can be useful when developing console applications or utilities that need to adapt their layout dynamically based on the size of the user's terminal.
___
## Prerequisites
* A Unix-like system (Linux)
* GCC compiler (or any other compatible C compiler)
___
## How it works
The process involves the following steps:

1. **Include necessary headers**:
```C
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
```

2. **Use the winsize structure**: This structure holds information about the dimensions of the terminal window.

3. **Call ```ioctl()```**: Pass the standard input file descriptor (```STDIN_FILENO```) and the operation code ```TIOCGWINSZ``` to request the current window sizes.

4. **Access the column count**: Once the data has been retrieved, you can access the width via the ```ws_col``` field of the ```winsize``` structure.

Here's an example implementation:
```C
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main() {
    struct winsize w;

    // Request terminal window size info
    if (ioctl(STDIN_FILENO, TIOCGWINSZ, &w)) {
        perror("Error getting window size");
        return 1;
    }

    printf("Terminal width in characters: %d\n", w.ws_col);
    return 0;
}
```
___
## Building & Running
To compile and run this simple utility, follow these commands:
```Bash
gcc main.c -o app
./app
```
Output will display the width of your terminal in characters.
___

## License
This project is licensed under the MIT License. See the LICENSE file for details.

---
*Feel free to modify or extend this template as needed!*
