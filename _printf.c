#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf -this is the  Printf function
 * @format: format.
 * Return: Printed characters
 */
int _printf(const char *format, ...)
{
	int a, printed = 0, printed_chars = 0;
	int i, j, precision, size, buff_ind = 0;
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
			i = extract_flags(format, &a);
			j = get_width(format, &a, list);
			precision = get_f(format, &a, list);
			size = get_size(format, &a);
			++a;
			printed = h_print(format, &i, list, buffer,
				i, j, precision, size);
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
 * print_buffer - function Prints the contents of the buffer if it exist
 * @buffer:an array of characters
 * @ind_buff: Index at which next char is added.
 */
void print_buffer(char buffer[], int *ind_buff)
{
	if (*ind_buff > 0)
		write(1, &buffer[0], *ind_buff);

	*ind_buff = 0;
}
