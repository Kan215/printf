#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct operation
 *
 * @fmt: The format of the struct
 * @fn: The function associated with the struct
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct operation
 *
 * @fmt: The format of the struct
 * @fm_t: The function associated withh struct.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int h_print(const char *fmt, int *a,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/*Header file for Funtions to print chars and strings */
int p_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Header for Functions to print numbers */
int p_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int p_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/*Header file for Function to print non printable characters */
int p_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/*Header for Funcion to print memory address */
int p_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Header for  Functions to handle other specifiers */
int extract_flags(const char *format, int *i);
int find_width(const char *format, int *a, va_list list);
int get_f(const char *format, int *i, va_list list);
int calc_size(const char *format, int *a);

/*Header file Function to print string in reverse*/
int p_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Header for Function to print a string in rot 13*/
int p_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Header for  width handler */
int _write_char(char e, char buffer[],
	int f, int w, int precision, int size);
int _number(int is_positive, int ind, char buffer[],
	int f, int, int precision, int size);
int _num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int _pointer(char buffer[], int ind, int length,
	int w, int f, char padd, char extra_c, int padd_start);

int _unsgnd(int _negative, int ind,
char buffer[],
	int f, int w, int precision, int size);

/****************** UTILS HEADER FILE ******************/
int my_print(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
