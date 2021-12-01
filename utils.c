/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** utils
*/

#include "my.h"

void print_help(void)
{
    my_printf("USAGE\n\
    \t./my_hunter [-h]\n\
    OPTIONS\n\
    \t-h print the usage and quit.\n\
    USER INTERACTIONS\n\
    \tZ move ship forward.\n\
    \tQ move ship to the left.\n\
    \tS move ship backward.\n\
    \tD move ship to the right.\n\
    \tLEFT_CLICK launch projectile from ship to cursor position.\n");
}