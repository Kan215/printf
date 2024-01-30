#include "main.h"

/**
 * get_f -The function calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @m: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_f(const char *format, int *m, va_list list)
{
	int bar_m = *m + 1;
	int precision = -1;

	if (format[bar_m] != '.')
		return (precision);

	precision = 0;

	for (bar_m += 1; format[bar_m] != '\0'; bar_m++)
	{
		if (is_digit(format[bar_m]))
		{
			precision *= 10;
			precision += format[bar_m] - '0';
		}
		else if (format[bar_m] == '*')
		{
			bar_m++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*m = bar_m - 1;

	return (precision);
}
