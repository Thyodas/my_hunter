/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** utils
*/

#include "my.h"
#include "game_data.h"
#include "math.h"

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

sfVector2f normalize_vector(sfVector2f vector)
{
    float norm = sqrtf(vector.x * vector.x + vector.y * vector.y);

    vector.x = vector.x / norm;
    vector.y = vector.y / norm;
    return (vector);
}
