# 📝 get_next_line

A C function that reads a single line from a file descriptor.

## Description

`get_next_line()` returns one line at a time from a given file descriptor.
Repeated calls allow reading a file line by line. Returns `NULL` when there
is nothing left to read or an error occurs.
Makefile is not an official part of the project, I added it for convenience.
Neither are the main.c file and the .txt files.

## Function prototype

char *get_next_line(int fd);

## External functions:
read, malloc, free

## Key concepts

- Uses a static variable to retain data between calls
- Buffer size is set at compile time via `-D BUFFER_SIZE=n`
- Works with both files and standard input
- Returned line includes the `\n` character (except at end of file)

## Files

| File | Description |
|------|-------------|
| `get_next_line.c` | Main function |
| `get_next_line_utils.c` | Helper functions |
| `get_next_line.h` | Header file |

## Usage

Run the program: ./gnl
Selecting a text file is possible by modifying main.c.

To test with a custom buffer size, recompile with:
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

## Bonus

- Single static variable implementation
- Handles multiple file descriptors simultaneously

## How it works

```text
get_next_line()
│
├── buffer empty? → read_buf() → read data from file
│
├── find_newline()
│   ├── \n found → complete_line() → return line
│   └── no \n → add_chunk() → append buffer → read more
│
└── EOF/error → return NULL
```

## 🛠️ To be compliant with Norm 42, install Norminette:
python3 -m venv venv && source venv/bin/activate && pip install -U norminette
