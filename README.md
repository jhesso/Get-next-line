# Get-next-line

The 42 school's get_next_line project is where we learn to read from a file descriptor, as well as the use of static variables.

The goal of this project is to return the "next line" from a given file descriptor.
(the first time it's called, the next line will be actually the first line)

The only difference between the mandatory and the bonus is that the bonus can handle multiple file descriptors at the same time

## Status
Finished: 2022-12-8. Grade: 125/100.

This has been added to my libft project after completion.

## Usage
This function is not a stand-alone program, its files must be included and compiled within another project.

Example ``main.c``:
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}
```
Compilation:
```bash
gcc main.c get_next_line.c get_next_line_utils.c
```
``BUFFER_SIZE`` can be specified at compilation to override the default ``BUFFER_SIZE``:
```bash
gcc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```
Execution:
```bash
./a.out [file]
```
Output should show the entire contents of the given file.

Execution with stdin:
```bash
./a.out /dev/tty
```
Program will wait for input, then once the enter key is pressed, print out the input as well as get_next_line's output. The process can be killed with ``ctrl-c``.

---
Made by jhesso: jhesso@student.hive.fi | LinkedIn: [jhesso](https://www.linkedin.com/in/juho-hesso-a75993171/)
