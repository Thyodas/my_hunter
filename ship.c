/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** ship.c
*/

#include "my.h"
#include "game_data.h"
#include <stdlib.h>

void move_ship(sprite_data_t *ship)
{
    sfVector2f *speed = &(ship->speed_vector);
    sfFloatRect rect = sfSprite_getGlobalBounds(ship->sprite);
    if (rect.left + speed->x < 0 || rect.left + rect.width + speed->x > 1920)
        speed->x = 0;
    if (rect.top + speed->y < 0 || rect.top + rect.height + speed->y > 1150)
        speed->y = 0;
    sfSprite_move(ship->sprite, ship->speed_vector);
}

void animate_ship(sprite_data_t *ship)
{
    sfIntRect ship_rect = sfSprite_getTextureRect(ship->sprite);

    if (ship->speed_vector.x == -SHIP_SPEED)
        ship_rect.left = 0;
    if (ship->speed_vector.x == SHIP_SPEED)
        ship_rect.left = 64;
    if (ship->speed_vector.x == 0)
        ship_rect.left = 16;
    if (ship->animation_counter > 5) {
        ship_rect.top = ship_rect.top == 0 ? 24 : 0;
        ship->animation_counter = 0;
    } else
        ++ship->animation_counter;
    sfSprite_setTextureRect(ship->sprite, ship_rect);
}
