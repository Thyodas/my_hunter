/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** game_data
*/

#ifndef GAME_DATA_H_
#define GAME_DATA_H_

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window/Keyboard.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Export.h>
    #include <SFML/Graphics/Texture.h>

    /*typedef struct {
        int
    } texture_state_t;*/

    #define SHIP_SPEED 10
    #define BACKGROUND_SPEED 3

    static const sfIntRect SHIP_STATES[] = {
        {0, 0, 16, 24}, {16, 0, 16, 24}, {32, 0, 16, 24}, {48, 0, 16, 24},
        {64, 0, 16, 24},
        {0, 12, 16, 24}, {16, 12, 16, 24}, {32, 12, 16, 24}, {48, 12, 16, 24},
        {64, 12, 16, 24}
    };

    typedef struct {
        sfImage *image;
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f speed_vector;
        sfIntRect *state_list;
        int state_index;
        int id;
        int animation_counter;
    } sprite_data_t;

    typedef struct {
        sprite_data_t *ship;
    } game_data_t;

#endif /* !GAME_DATA_H_ */
