#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf -This is the  Printf function
 * @format: format of the function
 * Return: Printed charsacters.
 */
int _printf(const char *format, ...)
{
	int a, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = extract_flags(format, &a);
			width = get_width(format, &a, list);
			precision = get_f(format, &a, list);
			size = get_size(format, &a);
			++a;
			printed = h_print(format, &a, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - function that Prints the contents of the buffer if it exists.
 * @buffer: Array of characters
 * @buff_ind: Index at which next char is to be added,
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
