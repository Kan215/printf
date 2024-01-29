#include "main.h"

/**
 * get_f - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_f(const char *format, int *i, va_list list)
{
	int bar_i = *i + 1;
	int precision = -1;

	if (format[bar_i] != '.')
		return (precision);

	precision = 0;

	for (bar_i += 1; format[bar_i] != '\0'; bar_i++)
	{
		if (is_digit(format[bar_i]))
		{
			precision *= 10;
			precision += format[bar_i] - '0';
		}
		else if (format[bar_i] == '*')
		{
			bar_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = bar_i - 1;

	return (precision);
}
