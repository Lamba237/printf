#include "main.h"
/**
 *_printf -  function that produces output according to a format
 *@format: character string
 *
 *Return: number of characters printed
 */

int _printf(const char *format, ...)
{
        va_list slist;
        int numchar = 0, l = 0;

        va_start(slist, format);

        if (format == NULL)
                exit(1);
        while (format[l] != '\0')
        {
                if (format[l] != '%')
                {
                        write(1, &format[l], 1);
                        numchar++;
                }
                else
                {
                        format++;
                        if (format[l] == '\0')
                        {
                                return (-1);
                        }
                        if (format[l] == '%')
                        {
                                write(1, &format[l], 1);
                                numchar++;
                        }
                        else if (format[l] == 'c')
                        {
                                char w = va_arg(slist, int);

                                write(1, &w, 1);
                                numchar++;
                        }
                        else if (format[l] == 's')
                        {
                                char *y = va_arg(slist, char*);
                                int i = 0;

                                while (y[i] != '\0')
                                {
                                        i++;
                                }
                                write(1, y, i);
                                numchar++;
                        }
                }
                format++;
        }
        va_end(slist);
        return (numchar);
}
