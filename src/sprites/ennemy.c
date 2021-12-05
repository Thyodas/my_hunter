/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** ennemy
*/

#include "my.h"
#include "game_data.h"
#include <stdlib.h>
#include <stdlib.h>

void move_ennemy(sprite_data_t *ennemy)
{
    sfVector2f *vector = &(ennemy->norm_vector);

    sfSprite_move(ennemy->sprite,
    (sfVector2f){vector->x * ennemy->speed, vector->y * ennemy->speed});
}

void animate_ennemy(sprite_data_t *ennemy)
{
    sfIntRect ennemy_rect = sfSprite_getTextureRect(ennemy->sprite);

    if (ennemy->animation_counter > 5) {
        ennemy_rect.left = 32 * ennemy->animation_state;
        ennemy->animation_state = ennemy->animation_state != 1;
        ennemy->animation_counter = 0;
    } else
        ++ennemy->animation_counter;

    sfSprite_setTextureRect(ennemy->sprite, ennemy_rect);
}

sprite_data_t *create_ennemy(game_data_t *g_data)
{
    static int ennemy_id = 0;

    sprite_data_t *ennemy = malloc(sizeof(sprite_data_t));
    ennemy->image = g_data->ennemy_image;
    ennemy->texture = g_data->ennemy_texture;
    ennemy->sprite = sfSprite_create();
    sfSprite_setTexture(ennemy->sprite, ennemy->texture, sfTrue);
    sfIntRect rect_ship = {0, 0, 32, 32};
    sfSprite_setTextureRect(ennemy->sprite, rect_ship);
    sfSprite_setScale(ennemy->sprite, (sfVector2f){6, 6});
    ennemy->id = ennemy_id++;
    ennemy->animation_counter = 0;
    ennemy->animation_state = 0;
    my_add_node(ennemy, &(g_data->ennemy_list));
    setup_ennemy(g_data, ennemy);
    return (ennemy);
}

void render_all_ennemy(game_data_t *g_data)
{
    linked_list_t *head = g_data->ennemy_list;
    sprite_data_t *current_sprite = NULL;

    for (int i = 0 ; head != NULL ; ++i) {
        current_sprite = head->data;
        sfRenderWindow_drawSprite(g_data->window, current_sprite->sprite, NULL);
        head = head->next;
    }
}