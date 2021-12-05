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

void my_hunter(game_data_t *g_data)
{
    int fps = 60;
    float ms_per_second = 1 / (float)fps;
    float time_delta = 0;
    float clock_seconds = 0;

    while (sfRenderWindow_isOpen(g_data->window)) {
        event_handler(g_data);
        clock_seconds = sfTime_asSeconds(sfClock_getElapsedTime(g_data->clock));
        if (clock_seconds - time_delta > ms_per_second) {
            spawn_ennemy(g_data);
            move_all(g_data);
            check_all(g_data);
            animate_all(g_data);
            render_all(g_data);
            time_delta = sfTime_asSeconds(sfClock_getElapsedTime(g_data->clock))
                - clock_seconds;
            sfClock_restart(g_data->clock);
        }
    }
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
    sfVideoMode mode = {1920, 1080, 32};
    game_data_t *g_data = malloc(sizeof(game_data_t));
    load_resources(g_data);
    create_background(g_data);
    create_ship(g_data);
    g_data->hp = 3;
    g_data->score = 0;
    g_data->projectile_list = NULL;
    g_data->planet_list = NULL;
    g_data->ennemy_list = NULL;
    g_data->window = sfRenderWindow_create(mode, "my_hunter", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(g_data->window, 60);
    g_data->clock = sfClock_create();
    my_hunter(g_data);
    free_all(g_data);
}
