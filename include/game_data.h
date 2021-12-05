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

    #include "my_list.h"

    /*typedef struct {
        int
    } texture_state_t;*/

    #define SHIP_SPEED 10
    #define PROJECTILE_SPEED 6
    #define BACKGROUND_SPEED 3

    #define ABS(value) (value < 0 ? (value) * (-1) : (value))
    #define MAX(a, b) ((a) > (b) ? (a) : (b))
    #define MIN(a, b) ((a) < (b) ? (a) : (b))

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
        sfVector2f norm_vector;
        sfIntRect *state_list;
        int speed;
        int animation_counter;
        int animation_state;
        int id;
    } sprite_data_t;

    typedef struct {
        int score;
        int hp;
        sfRenderWindow *window;
        sfEvent event;
        sfClock *clock;
        sprite_data_t *ship;
        sprite_data_t *background;
        linked_list_t *projectile_list;
        linked_list_t *planet_list;
        linked_list_t *ennemy_list;
    } game_data_t;

    // main.c
    int my_hunter(game_data_t *g_data);
    int main(int argc, char **argv);

    // all_loop.c
    int move_all(game_data_t *g_data);
    int animate_all(game_data_t *g_data);
    int render_all(game_data_t *g_data);
    void check_all(game_data_t *g_data);

    // projectile.c
    void move_projectile(sprite_data_t *projectile);
    void animate_projectile(sprite_data_t *projectile);
    sprite_data_t *create_projectile(game_data_t *g_data);
    void render_all_projectile(game_data_t *g_data);

    // projectile.c
    void move_planet(sprite_data_t *planet);
    void animate_planet(sprite_data_t *planet);
    sprite_data_t *create_planet(game_data_t *g_data);
    void render_all_planet(game_data_t *g_data);

    // projectile_utils.c
    sfVector2f calc_projectile_vector(game_data_t *g_data, float x, float y);
    void check_shoot_angle(float *angle, sfVector2f *norm_vector);
    void setup_projectile(game_data_t *g_data, sprite_data_t *projectile);

    // ennemy.c
    void move_ennemy(sprite_data_t *ennemy);
    void animate_ennemy(sprite_data_t *ennemy);
    sprite_data_t *create_ennemy(game_data_t *g_data);
    void render_all_ennemy(game_data_t *g_data);

    // ennemy_utils.c
    void setup_ennemy(sprite_data_t *ennemy);
    void spawn_ennemy(game_data_t *g_data);

    // ship.c
    void move_ship(sprite_data_t *ship);
    void animate_ship(sprite_data_t *ship);
    void create_ship(game_data_t *g_data);

    // background.c
    void move_background(sprite_data_t *background);
    void create_background(game_data_t *g_data);

    // events.c
    void window_events(game_data_t *g_data);
    void zqsd_events(game_data_t *g_data);
    void event_handler(game_data_t *g_data);

    // utils.c
    void print_help(void);
    sfVector2f normalize_vector(sfVector2f vector);

    // check.c
    void check_btw_ennemy_projectile(game_data_t *g_data);

#endif /* !GAME_DATA_H_ */
