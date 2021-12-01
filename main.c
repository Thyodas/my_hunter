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

void print_help(void);

void event_handler(sfRenderWindow *window, sfEvent *event,
game_data_t *game_data);

void move_ship(sprite_data_t *ship);
void animate_ship(sprite_data_t *ship);

void move_background(sprite_data_t *background);

void move_projectile(sprite_data_t *projectile);
void animate_projectile(sprite_data_t *projectile);

sprite_data_t *create_background(void)
{
    sprite_data_t *background = malloc(sizeof(sprite_data_t));
    background->image = sfImage_createFromFile("resources/background.png");
    sfIntRect area_state = {0, 0, 64, 64};
    background->texture = sfTexture_createFromImage(background->image, &area_state);
    sfTexture_setRepeated(background->texture, sfTrue);
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    sfSprite_setTextureRect(background->sprite, (sfIntRect){0, 0, 3840, 1080});
    sfSprite_setScale(background->sprite, (sfVector2f){10, 10});
    sfSprite_setPosition(background->sprite, (sfVector2f){0, -3840});
    background->speed_vector = (sfVector2f){0, BACKGROUND_SPEED};
    background->animation_counter = 0;
    return (background);
}

sprite_data_t *create_ship(void)
{
    sprite_data_t *sprite_ship = malloc(sizeof(sprite_data_t));
    sprite_ship->image = sfImage_createFromFile("resources/ship.png");
    sprite_ship->texture = sfTexture_createFromImage(sprite_ship->image, NULL);
    sprite_ship->sprite = sfSprite_create();
    sfSprite_setTexture(sprite_ship->sprite, sprite_ship->texture, sfTrue);
    sfIntRect rect_ship = {32, 0, 16, 24};
    sfSprite_setTextureRect(sprite_ship->sprite, rect_ship);
    sfSprite_setScale(sprite_ship->sprite, (sfVector2f){8, 8});
    sfSprite_setPosition(sprite_ship->sprite, (sfVector2f){960 - 8 * 8, 800});
    sprite_ship->animation_counter = 0;
    return (sprite_ship);
}

sprite_data_t *create_projectile(void)
{
    sprite_data_t *projectile = malloc(sizeof(sprite_data_t));
    projectile->image = sfImage_createFromFile("resources/projectile.png");
    projectile->texture = sfTexture_createFromImage(projectile->image, NULL);
    projectile->sprite = sfSprite_create();
    sfSprite_setTexture(projectile->sprite, projectile->texture, sfTrue);
    sfIntRect rect_ship = {6, 18, 5, 13};
    sfSprite_setTextureRect(projectile->sprite, rect_ship);
    projectile->speed_vector = (sfVector2f){0, -(SHIP_SPEED - 2)};
    sfSprite_setScale(projectile->sprite, (sfVector2f){8, 8});
    sfSprite_setPosition(projectile->sprite, (sfVector2f){960 - 8 * 8, 700});
    projectile->animation_counter = 0;
    return (projectile);
}

int my_hunter(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "window", sfClose, NULL);
    sfEvent event;

    sfClock *clock = sfClock_create();
    int fps = 60;
    float ms_per_second = 1 / (float)fps;

    game_data_t game_data;

    sprite_data_t *background = create_background();
    sprite_data_t *projectile = create_projectile();
    game_data.ship = create_ship();
    while (sfRenderWindow_isOpen(window)) {
        event_handler(window, &event, &game_data);
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > ms_per_second) {
            move_ship(game_data.ship);
            move_background(background);
            move_projectile(projectile);
            animate_ship(game_data.ship);
            animate_projectile(projectile);
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawSprite(window, background->sprite, NULL);
            sfRenderWindow_drawSprite(window, game_data.ship->sprite, NULL);
            sfRenderWindow_drawSprite(window, projectile->sprite, NULL);
            sfRenderWindow_display(window);
            sfClock_restart(clock);
        }
    }
    sfRenderWindow_destroy(window);
    return (0);
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
    my_hunter();
}
