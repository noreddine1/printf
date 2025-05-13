# ft_printf

`ft_printf` is a custom implementation of the standard `printf` function in C. It supports formatted output for various data types and is designed to mimic the behavior of the standard library function.

## Features

- Supports the following format specifiers:
  - `%c` - Print a single character.
  - `%s` - Print a string.
  - `%d` or `%i` - Print a signed integer.
  - `%u` - Print an unsigned integer.
  - `%x` or `%X` - Print an unsigned integer in hexadecimal (lowercase or uppercase).
  - `%p` - Print a pointer address.
  - `%%` - Print a literal `%` character.
- Handles `NULL` strings gracefully by printing `(null)`.

## Files

- **ft_printf.c**: Contains the main implementation of the `ft_printf` function.
- **lib_print.c**: Contains helper functions for printing characters, strings, numbers, and hexadecimal values.
- **ft_printf.h**: Header file with function prototypes and necessary includes.
- **Makefile**: Automates the build process for creating the `libftprintf.a` library.

## Usage

1. Compile the library using the provided `Makefile`:
   ```bash
   make
   ```
2. Include the library in your project by adding the following line to your source files:
    ```c
    #include "ft_printf.h"
    ```

3. Compile your project with the `libftprintf.a` library:
    ```bash
    gcc -Wall -Wextra -Werror your_source_file.c -L. -lftprintf -o your_program
    ```

4. Run your program:
    ```bash
    ./your_program
    ```

## Example

Here is a simple example of using `ft_printf`:

```c
#include "ft_printf.h"

int main(void)
{
     ft_printf("Hello, %s!\n", "world");
     ft_printf("The number is: %d\n", 42);
     ft_printf("Pointer address: %p\n", &main);
     return 0;
}
```
<!-- ## Testing

You can test the functionality of `ft_printf` by comparing its output with the standard `printf` function. Create test cases to ensure it behaves as expected for all supported format specifiers.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details. -->
