# get_next_line

Buffered line reader for file descriptors. Reads one line at a time using static per-fd buffers.

## API

**`char *get_next_line(int fd)`**
- Returns next line (including `\n`), or `NULL` on EOF/error
- Caller must `free()` returned strings
- Maintains independent buffers for each fd

**`void get_next_line_flush(int fd)`**
- Clears buffer for fd (pass `-1` to flush all)
- Use after `close(fd)` to avoid collision with reused fd numbers

## Usage

```c
#include "get_next_line.h"

char *line;
int fd = open("file.txt", O_RDONLY);
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s\n", line);
    free(line);
}
close(fd);
get_next_line_flush(fd);
```

## Build

```
make        # Build libgnl.a
make clean  # Remove .o files
make fclean # Remove library
make re     # Rebuild
```

## Configuration

Define `BUFFER_SIZE` at compile time (default: 42 bytes):
```
cc -DBUFFER_SIZE=4096 ...
```

## Known Limitation: FD Collision

When OS reuses a closed fd number for a new file, `get_next_line` returns stale buffered data from the old file. **Always call `get_next_line_flush(fd)` after closing** to prevent this.
