# ft_printf

The ft_printf function is a custom implementation of the standard printf function found in the C standard library. This function is designed to replicate the behavior of printf with a specific set of formatting options, allowing you to print formatted output to the standard output.

## Prototype

* int ft_printf(const char *, ...);

## Requirements and Features
### Buffer Management: Unlike the original printf, this implementation does not manage buffers.
### Supported Conversions: The function handles the following conversion specifiers:
* %c: Prints a single character.
* %s: Prints a string.
* %p: Prints a pointer in hexadecimal format.
* %d: Prints a decimal (base 10) number.
* %i: Prints an integer in base 10.
* %u: Prints an unsigned decimal (base 10) number.
* %x: Prints a number in lowercase hexadecimal (base 16) format.
* %X: Prints a number in uppercase hexadecimal (base 16) format.
* %%: Prints a percent sign.

## Comparison with Original printf
Your ft_printf function will be compared against the original printf function to ensure correctness and performance. This includes verifying the accuracy of output for each supported conversion specifier.

## Compilation and Library Creation
Command Restrictions: You must use the ar command to create your library. The use of the libtool command is forbidden.
Library Creation: The library libftprintf.a should be created at the root of your repository.

## Integration
To integrate ft_printf into your project, follow these steps:

1. Add the Files to Your Project:
Ensure that the ft_printf implementation files (such as ft_printf.c, ft_printf.h, and any utility files) are included in your project directory.

2. Compile Your Project with the Library:
Use the following commands to compile your project and create the library:


gcc -Wall -Wextra -Werror -c ft_printf.c
ar rcs libftprintf.a ft_printf.o
gcc -o my_program my_program.c -L. -lftprintf

## Notes
* Error Handling: Ensure that your implementation properly handles errors, such as invalid format specifiers or null pointers.
* Testing: Thoroughly test your ft_printf function to ensure it matches the behavior of the original printf for all supported conversions.
