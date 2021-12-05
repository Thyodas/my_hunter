/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** projectile_utils
*/

#include "my.h"
#include "game_data.h"
#include "stage.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

void setup_ennemy(game_data_t *g_data, sprite_data_t *ennemy)
{
    static unsigned previous = 0;
    time_t t;
    srand((unsigned) time(&t) + previous);
    float x = rand() % 1820;
    float y = -300;
    previous = x + 233;

    ennemy->speed = 6 + g_data->stage;
    ennemy->norm_vector = (sfVector2f){0, 1};
    sfSprite_setPosition(ennemy->sprite, (sfVector2f){x, y});
}

void spawn_ennemy(game_data_t *g_data)
{
    static unsigned int counter = 0;

    if (counter > 100 - g_data->stage * 10) {
        create_ennemy(g_data);
        counter = 0;
    } else
        ++counter;
}

void check_stage(game_data_t *g_data)
{
    for (int i = 0 ; i < MAX_STAGE ; ++i) {
        if (g_data->score < stage_by_score[i]) {
            g_data->stage = i + 1;
            break;
        } else
            g_data->stage = MAX_STAGE;
    }
}
