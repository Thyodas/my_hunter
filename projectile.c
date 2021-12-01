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

void animate_projectile(sprite_data_t *projectile)
{
    sfIntRect projectile_rect = sfSprite_getTextureRect(projectile->sprite);

    if (projectile->animation_counter > 5) {
        projectile_rect.left = projectile_rect.left == 6 ? 20 : 6;
        projectile->animation_counter = 0;
    } else
        ++projectile->animation_counter;

    sfSprite_setTextureRect(projectile->sprite, projectile_rect);
}