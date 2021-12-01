/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** projectile
*/

#include "my.h"
#include "game_data.h"
#include <stdlib.h>

void move_projectile(sprite_data_t *projectile)
{
    sfVector2f *speed = &(projectile->speed_vector);
    sfFloatRect rect = sfSprite_getGlobalBounds(projectile->sprite);
    if (rect.top + speed->y < 0)
        speed->y = 0;
    sfSprite_move(projectile->sprite, projectile->speed_vector);
}