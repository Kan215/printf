#include "main.h"
/**
 * h_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @d: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int h_print(const char *fmt, int *d, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', p_char}, {'s', p_string}, {'%', p_percent},
		{'i', p_int}, {'d', p_int}, {'b', p_binary},
		{'u', p_unsigned}, {'o', p_octal}, {'x', p_hexadecimal},
		{'X', p_hexa_upper}, {'p', p_pointer}, {'S', p_non_printable},
		{'r', p_reverse}, {'R', p_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*d] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*d] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*d - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*d);
			while (fmt[*d] != ' ' && fmt[*d] != '%')
				--(*d);
			if (fmt[*d] == ' ')
				--(*d);
			return (1);
		}
		unknow_len += write(1, &fmt[*d], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
