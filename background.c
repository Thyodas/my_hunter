/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** ship.c
*/

#include "my.h"
#include "game_data.h"
#include <stdlib.h>

void move_background(sprite_data_t *background)
{
    sfVector2f *speed = &(background->speed_vector);
    sfVector2f pos = sfSprite_getPosition(background->sprite);
    if (pos.y + speed->y > 0)
        sfSprite_setPosition(background->sprite, (sfVector2f){0, -3840});
    else
        sfSprite_move(background->sprite, background->speed_vector);
}
