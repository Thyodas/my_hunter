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
    sfVector2f *vector = &(ship->norm_vector);
    sfFloatRect rect = sfSprite_getGlobalBounds(ship->sprite);

    if (rect.left + vector->x * ship->speed < 0
    || rect.left + rect.width + vector->x * ship->speed > 1920)
        vector->x = 0;
    if (rect.top + vector->y * ship->speed < 0
    || rect.top + rect.height + vector->y * ship->speed > 1150)
        vector->y = 0;
    sfSprite_move(ship->sprite, (sfVector2f){vector->x * ship->speed,
        vector->y * ship->speed});
}

void animate_ship(sprite_data_t *ship)
{
    static int animation_counter = 0;
    sfIntRect ship_rect = sfSprite_getTextureRect(ship->sprite);

    if (ship->norm_vector.x == -1)
        ship_rect.left = 0;
    if (ship->norm_vector.x == 1)
        ship_rect.left = 64;
    if (ship->norm_vector.x == 0)
        ship_rect.left = 16;
    if (animation_counter > 5) {
        ship_rect.top = ship_rect.top == 0 ? 24 : 0;
        animation_counter = 0;
    } else
        ++animation_counter;
    sfSprite_setTextureRect(ship->sprite, ship_rect);
}

void create_ship(game_data_t *g_data)
{
    sprite_data_t *sprite_ship = malloc(sizeof(sprite_data_t));
    sprite_ship->image = sfImage_createFromFile("resources/ship.png");
    sprite_ship->texture = sfTexture_createFromImage(sprite_ship->image, NULL);
    sprite_ship->sprite = sfSprite_create();
    sfSprite_setTexture(sprite_ship->sprite, sprite_ship->texture, sfTrue);
    sfIntRect rect_ship = {32, 0, 16, 24};
    sfSprite_setTextureRect(sprite_ship->sprite, rect_ship);
    sfSprite_setScale(sprite_ship->sprite, (sfVector2f){10, 10});
    sfSprite_setPosition(sprite_ship->sprite, (sfVector2f){960 - 8 * 8, 800});
    sprite_ship->speed = SHIP_SPEED;
    sprite_ship->norm_vector = (sfVector2f){0, 0};
    g_data->ship = sprite_ship;
}
