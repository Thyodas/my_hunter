/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** events
*/

#include "my.h"
#include "game_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/System/Time.h>
#include <SFML/System/Export.h>

void window_events(game_data_t *g_data)
{
    if (g_data->event.type == sfEvtClosed)
        sfRenderWindow_close(g_data->window);
}

void zqsd_events(game_data_t *g_data)
{
    g_data->ship->norm_vector.x = 0;
    g_data->ship->norm_vector.y = 0;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        g_data->ship->norm_vector.y = -1;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        g_data->ship->norm_vector.x = -1;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        g_data->ship->norm_vector.y = 1;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        g_data->ship->norm_vector.x = 1;
}

void click_events(game_data_t *g_data)
{
    if (g_data->event.type == sfEvtMouseButtonPressed
    && g_data->event.mouseButton.button == sfMouseLeft)
        create_projectile(g_data);
}

void event_handler(game_data_t *g_data)
{
    while (sfRenderWindow_pollEvent(g_data->window, &g_data->event)) {
        window_events(g_data);
        zqsd_events(g_data);
        click_events(g_data);
    }
}