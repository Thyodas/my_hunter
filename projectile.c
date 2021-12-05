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
    sfVector2f *vector = &(projectile->norm_vector);
    sfFloatRect rect = sfSprite_getGlobalBounds(projectile->sprite);

    if (rect.top + vector->y * projectile->speed < 0)
        vector->y = 0;
    sfSprite_move(projectile->sprite,
    (sfVector2f){vector->x * projectile->speed, vector->y * projectile->speed});
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

sprite_data_t *create_projectile(game_data_t *g_data)
{
    static int projectile_id = 0;

    sprite_data_t *projectile = malloc(sizeof(sprite_data_t));
    projectile->image = sfImage_createFromFile("resources/projectile.png");
    projectile->texture = sfTexture_createFromImage(projectile->image, NULL);
    projectile->sprite = sfSprite_create();
    sfSprite_setTexture(projectile->sprite, projectile->texture, sfTrue);
    sfIntRect rect_ship = {6, 18, 5, 13};
    sfSprite_setTextureRect(projectile->sprite, rect_ship);
    sfSprite_setScale(projectile->sprite, (sfVector2f){5, 5});
    projectile->id = projectile_id++;
    projectile->animation_counter = 0;
    my_add_node(projectile, &(g_data->projectile_list));
    setup_projectile(g_data, projectile);
    return (projectile);
}

void render_all_projectile(game_data_t *g_data)
{
    linked_list_t *head = g_data->projectile_list;
    sprite_data_t *current_sprite = NULL;

    for (int i = 0 ; head != NULL ; ++i) {
        current_sprite = head->data;
        sfRenderWindow_drawSprite(g_data->window, current_sprite->sprite, NULL);
        head = head->next;
    }
}