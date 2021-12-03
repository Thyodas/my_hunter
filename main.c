/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "game_data.h"
#include <math.h>
#include <stdlib.h>

int move_all(game_data_t *g_data)
{
    my_apply_on_nodes(g_data->projectile_list, &move_projectile);
    move_ship(g_data->ship);
    move_background(g_data->background);
    return (0);
}

int animate_all(game_data_t *g_data)
{
    my_apply_on_nodes(g_data->projectile_list, &animate_projectile);
    my_apply_on_nodes(g_data->planet_list, &animate_planet);
    animate_ship(g_data->ship);
    return (0);
}

int render_all(game_data_t *g_data)
{
    sfRenderWindow_clear(g_data->window, sfWhite);
    sfRenderWindow_drawSprite(g_data->window, g_data->background->sprite, NULL);
    render_all_projectile(g_data);
    render_all_planet(g_data);
    sfRenderWindow_drawSprite(g_data->window, g_data->ship->sprite, NULL);
    sfRenderWindow_display(g_data->window);
    return (0);
}

int my_hunter(void)
{
    game_data_t *g_data = malloc(sizeof(game_data_t));
    sfVideoMode mode = {1920, 1080, 32};
    g_data->window = sfRenderWindow_create(mode, "my_hunter", sfClose, NULL);

    g_data->clock = sfClock_create();
    int fps = 60;
    float ms_per_second = 1 / (float)fps;

    create_background(g_data);
    create_ship(g_data);
    create_planet(g_data);
    while (sfRenderWindow_isOpen(g_data->window)) {
        event_handler(g_data);
        if (sfTime_asSeconds(sfClock_getElapsedTime(g_data->clock)) > ms_per_second) {
            move_all(g_data);
            animate_all(g_data);
            render_all(g_data);
            sfClock_restart(g_data->clock);
        }
    }
    sfRenderWindow_destroy(g_data->window);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc > 1) {
        if (my_strcmp(argv[1], "-h") == 0) {
            print_help();
            return (0);
        }
        return (84);
    }
    my_hunter();
}
