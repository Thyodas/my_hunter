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

void window_events(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void zqsd_events(sfEvent *event, game_data_t *game_data)
{
    game_data->ship->speed_vector.x = 0;
    game_data->ship->speed_vector.y = 0;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        game_data->ship->speed_vector.y = -SHIP_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        game_data->ship->speed_vector.x = -SHIP_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        game_data->ship->speed_vector.y = SHIP_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        game_data->ship->speed_vector.x = SHIP_SPEED;
}

void event_handler(sfRenderWindow *window, sfEvent *event,
game_data_t *game_data)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        window_events(window, event);
        zqsd_events(event, game_data);
    }
}