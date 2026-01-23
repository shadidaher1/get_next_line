This project has been created as part of the 42 curriculum by sdaher

NAME
    get_next_line

LIBRARY
    # include <stdlib.h>
    # include <unistd.h>
    # include <fcntl.h>

DESCRIPTION
    get_next_line is a function that reads and returns a single line from a file descriptor. This project teaches the concept of static variables in C and efficient file reading techniques.
    The function handles:
        Reading from files and standard input
        Multiple buffer sizes (including edge cases like 1 and 10000000)
        Lines with and without newline characters
        End-of-file conditions
        Multiple file descriptors simultaneously (bonus)
Compilation
    Compile the mandatory part:
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
    Compile the bonus part (multiple file descriptors):
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c

Reading Strategy
    Reads BUFFER_SIZE bytes at a time
    Stops reading as soon as a newline is encountered
    Stores leftovers in static variable for next call

Resources
    man read
    https://www.geeksforgeeks.org/static-variables-in-c/

AI Usage
    Understanding: Clarifying static variable behavior and scope
    Testing strategy: Suggestions for comprehensive test cases with different buffer sizes

RETURN VALUES
    The return is the line that it reads or NULL if an error occurs or if there is nothing to read.
