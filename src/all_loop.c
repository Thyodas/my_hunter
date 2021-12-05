/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** all_loop
*/

#include "my.h"
#include "game_data.h"
#include <math.h>
#include <stdlib.h>

int move_all(game_data_t *g_data)
{
    my_apply_on_nodes(g_data->projectile_list, &move_projectile);
    my_apply_on_nodes(g_data->ennemy_list, &move_ennemy);
    move_ship(g_data->ship);
    move_background(g_data->background);
    return (0);
}

int animate_all(game_data_t *g_data)
{
    my_apply_on_nodes(g_data->projectile_list, &animate_projectile);
    my_apply_on_nodes(g_data->planet_list, &animate_planet);
    my_apply_on_nodes(g_data->ennemy_list, &animate_ennemy);
    animate_ship(g_data->ship);
    return (0);
}

int render_all(game_data_t *g_data)
{
    sfRenderWindow_clear(g_data->window, sfWhite);
    sfRenderWindow_drawSprite(g_data->window, g_data->background->sprite, NULL);
    render_all_projectile(g_data);
    render_all_planet(g_data);
    render_all_ennemy(g_data);
    sfRenderWindow_drawSprite(g_data->window, g_data->ship->sprite, NULL);
    update_score(g_data);
    sfRenderWindow_drawText(g_data->window, g_data->text_score, NULL);
    move_crosshair(g_data);
    sfRenderWindow_drawSprite(g_data->window, g_data->crosshair->sprite, NULL);
    sfRenderWindow_display(g_data->window);
    return (0);
}

void check_all(game_data_t *g_data)
{
    check_btw_ennemy_projectile(g_data);
}
