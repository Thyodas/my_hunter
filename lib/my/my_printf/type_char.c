/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** All functions to manage str type
*/

#include "include/my_printf.h"
#include "../my.h"
#include <stdarg.h>

char *type_string(va_list args, printf_data_t *data)
{
    char *value = va_arg(args, char *);
    char *new_str = value;

    if (data->precision != -1) {
        int new_size = MIN(my_strlen(value), data->precision);
        new_str = malloc(sizeof(char) * (new_size + 1));

        for (int i = 0 ; i < new_size ; ++i)
            new_str[i] = value[i];
    }
    return (new_str);
}

char *type_char(va_list args, printf_data_t *data)
{
    char value = va_arg(args, int);
    char *result = my_strdup("a");

    result[0] = value;
    return (result);
}

char *my_struint_n_base(unsigned int nbr, char *str, char const *base, int n)
{
    int len_base = my_strlen(base);
    unsigned int new_nbr = nbr;
    unsigned int remainder = 0;
    char *str_ptr = str;

    while (new_nbr != 0 || n > 0) {
        remainder = new_nbr % len_base;
        new_nbr /= len_base;
        str_ptr = my_addchar(str_ptr, base[remainder]);
        --n;
    }
    return (str_ptr);
}

char *type_printable(va_list args, printf_data_t *data)
{
    char *value = va_arg(args, char *);
    char *result = my_strdup("");

    for (int i = 0; value[i] != '\0' ; i++) {
        if (32 > value[i] || value[i] > 126) {
            result = my_addchar(result, '\\');
            result = my_struint_n_base(value[i], result, "01234567", 3);
            my_revstr(&result[my_strlen(result) - 3]);
        } else
            result = my_addchar(result, value[i]);
    }
    return (result);
}

char *type_modulo(va_list args, printf_data_t *data)
{
    char *result = my_strdup("%");

    data->min_field_width = 0;
    return (result);
}
