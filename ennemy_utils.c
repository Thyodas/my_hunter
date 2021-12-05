/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** projectile_utils
*/

#include "my.h"
#include "game_data.h"
#include "math.h"
#include <stdlib.h>
#include <time.h>

void setup_ennemy(sprite_data_t *ennemy)
{
    static unsigned previous = 0;
    time_t t;
    srand((unsigned) time(&t) + previous);
    float x = rand() % 1920;
    float y = -300;
    previous = x;

    ennemy->speed = 6;
    ennemy->norm_vector = (sfVector2f){0, 1};
    sfSprite_setPosition(ennemy->sprite, (sfVector2f){x, y});
}

void spawn_ennemy(game_data_t *g_data)
{
    static int counter = 0;

    if (counter > 100) {
        create_ennemy(g_data);
        counter = 0;
    } else
        ++counter;
}
