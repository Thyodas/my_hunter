/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** planet
*/

#include "my.h"
#include "game_data.h"
#include <stdlib.h>

void move_planet(sprite_data_t *planet)
{
    sfVector2f *vector = &(planet->norm_vector);
    sfFloatRect rect = sfSprite_getGlobalBounds(planet->sprite);

    if (rect.top + vector->y * planet->speed < 0)
        vector->y = 0;
    sfSprite_move(planet->sprite,
    (sfVector2f){vector->x * planet->speed, vector->y * planet->speed});
}

void animate_planet(sprite_data_t *planet)
{
    sfIntRect planet_rect = sfSprite_getTextureRect(planet->sprite);

    if (planet->animation_counter > 5) {
        planet_rect.left = 210 * planet->animation_state;
        planet->animation_state = planet->animation_state >= 49 ? 0 : planet->animation_state + 1;
        planet->animation_counter = 0;
    } else
        ++planet->animation_counter;

    sfSprite_setTextureRect(planet->sprite, planet_rect);
}

sprite_data_t *create_planet(game_data_t *g_data)
{
    static int planet_id = 0;

    sprite_data_t *planet = malloc(sizeof(sprite_data_t));
    planet->image = sfImage_createFromFile("resources/gas_planet.png");
    planet->texture = sfTexture_createFromImage(planet->image, NULL);
    planet->sprite = sfSprite_create();
    sfSprite_setTexture(planet->sprite, planet->texture, sfTrue);
    sfIntRect rect_ship = {0, 0, 210, 210};
    sfSprite_setTextureRect(planet->sprite, rect_ship);
    sfSprite_setScale(planet->sprite, (sfVector2f){4, 4});
    planet->id = planet_id++;
    planet->animation_counter = 0;
    planet->animation_state = 0;
    my_add_node(planet, &(g_data->planet_list));
    return (planet);
}

void render_all_planet(game_data_t *g_data)
{
    linked_list_t *head = g_data->planet_list;
    sprite_data_t *current_sprite = NULL;

    for (int i = 0 ; head != NULL ; ++i) {
        current_sprite = head->data;
        sfRenderWindow_drawSprite(g_data->window, current_sprite->sprite, NULL);
        head = head->next;
    }
}