/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** music
*/

#include "my.h"
#include "game_data.h"

void import_music(game_data_t *g_data)
{
    g_data->music = sfMusic_createFromFile("resources/music.ogg");
    sfMusic_setLoop(g_data->music, sfTrue);
    sfMusic_play(g_data->music);
}