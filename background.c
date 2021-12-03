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

void create_background(game_data_t *g_data)
{
    sprite_data_t *background = malloc(sizeof(sprite_data_t));
    background->image = sfImage_createFromFile("resources/background.png");
    sfIntRect area_state = {0, 0, 64, 64};
    background->texture = sfTexture_createFromImage(background->image, &area_state);
    sfTexture_setRepeated(background->texture, sfTrue);
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    sfSprite_setTextureRect(background->sprite, (sfIntRect){0, 0, 3840, 1080});
    sfSprite_setScale(background->sprite, (sfVector2f){10, 10});
    sfSprite_setPosition(background->sprite, (sfVector2f){0, -3840});
    background->speed_vector = (sfVector2f){0, BACKGROUND_SPEED};
    g_data->background = background;
}
