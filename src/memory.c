/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** memory
*/

#include "my.h"
#include "game_data.h"

void load_resources(game_data_t *g_data)
{
    g_data->projectile_image = sfImage_createFromFile(
        "resources/projectile.png");
    g_data->ennemy_image = sfImage_createFromFile("resources/ennemy.png");
    g_data->projectile_texture = sfTexture_createFromImage(
        g_data->projectile_image, NULL);
    g_data->ennemy_texture = sfTexture_createFromImage(
        g_data->ennemy_image, NULL);
}

void free_sprite(sprite_data_t *sprite)
{
    sfImage_destroy(sprite->image);
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
    free(sprite);
}

void free_all(game_data_t *g_data)
{
    sfRenderWindow_destroy(g_data->window);
    sfImage_destroy(g_data->projectile_image);
    sfImage_destroy(g_data->ennemy_image);
    sfTexture_destroy(g_data->projectile_texture);
    sfTexture_destroy(g_data->ennemy_texture);
    sfClock_destroy(g_data->clock);
    sfMusic_destroy(g_data->music);
    free_sprite(g_data->background);
    free_sprite(g_data->ship);
    free(g_data);
}

void init_game(game_data_t *g_data)
{
    sfVideoMode mode = {1920, 1080, 32};
    load_resources(g_data);
    import_music(g_data);
    create_background(g_data);
    create_ship(g_data);
    create_score(g_data);
    create_crosshair(g_data);
    g_data->hp = 3;
    g_data->score = 0;
    g_data->projectile_list = NULL;
    g_data->planet_list = NULL;
    g_data->ennemy_list = NULL;
    g_data->window = sfRenderWindow_create(mode, "my_hunter", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(g_data->window, 60);
    g_data->clock = sfClock_create();
    sfRenderWindow_setMouseCursorVisible(g_data->window, sfFalse);
}