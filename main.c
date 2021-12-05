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
        clock_seconds = sfTime_asSeconds(sfClock_getElapsedTime(g_data->clock));
        if (clock_seconds - time_delta > ms_per_second) {
            event_handler(g_data);
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
    game_data_t *g_data = malloc(sizeof(game_data_t));

    init_game(g_data);
    my_hunter(g_data);
    free_all(g_data);
}
