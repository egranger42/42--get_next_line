# get_next_line

Reads lines from a file descriptor one at a time, with buffered I/O.

## Features

- Reads entire lines from any file descriptor
- Handles multiple file descriptors independently
- Configurable buffer size (default: 4096 bytes)
- Memory management with automatic state tracking

## Usage

```c
#include "get_next_line.h"

char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s\n", line);
    free(line);
}
```

Returns the next line including the newline, or NULL on EOF/error.

## Build

```bash
make          # Build library
make clean    # Remove object files
make fclean   # Remove all generated files
make re       # Rebuild everything
```

## Configuration

Modify `GNL_BUFFER_SIZE` in `get_next_line.h` to change the read buffer size.

## Implementation Details

Uses static state management to maintain buffer and position across multiple calls, allowing reading without re-buffering entire files.
