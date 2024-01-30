#include "main.h"

/**
 * calc_size - the function calculates the size to cast the argument
 * @format: The formatted string in arguments are to be printed
 * @a: List of arguments to be printed.
 *
 * Return: Precision.
 */
int calc_size(const char *format, int *a)
{
	int bar_a = *a + 1;
	int size = 0;

	if (format[bar_a] == 'l')
		size = S_LONG;
	else if (format[bar_a] == 'h')
		size = S_SHORT;

	if (size == 0)
		*a = bar_a - 1;
	else
		*a = bar_a;

	return (size);
}
