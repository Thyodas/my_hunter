/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** crosshair
*/

#include "my.h"
#include "game_data.h"
#include <stdlib.h>
#include <stdlib.h>

void move_crosshair(game_data_t *g_data)
{
    sprite_data_t *sprite_crosshair = g_data->crosshair;

    sfVector2i pos = sfMouse_getPositionRenderWindow(g_data->window);
    sfSprite_setPosition(sprite_crosshair->sprite,
        (sfVector2f){pos.x - 49, pos.y - 49});
}

void create_crosshair(game_data_t *g_data)
{
    sprite_data_t *sprite_crosshair = malloc(sizeof(sprite_data_t));
    sprite_crosshair->image = sfImage_createFromFile("resources/crosshair.png");
    sprite_crosshair->texture = sfTexture_createFromImage(
        sprite_crosshair->image, NULL);
    sprite_crosshair->sprite = sfSprite_create();
    sfSprite_setTexture(sprite_crosshair->sprite, sprite_crosshair->texture, 
        sfTrue);
    sfIntRect rect_crosshair = {20, 30, 13, 13};
    sfSprite_setTextureRect(sprite_crosshair->sprite, rect_crosshair);
    sfSprite_setScale(sprite_crosshair->sprite, (sfVector2f){7, 7});
    g_data->crosshair = sprite_crosshair;
}
