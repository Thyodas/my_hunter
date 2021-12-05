/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** projectile_utils
*/

#include "my.h"
#include "game_data.h"
#include "math.h"

sfVector2f calc_projectile_vector(game_data_t *g_data, float x, float y)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(g_data->window);
    sfVector2f vector = {mouse_pos.x - x, mouse_pos.y - y};
    sfVector2f normalized = normalize_vector(vector);

    return (normalized);
}

void check_shoot_angle(float *angle, sfVector2f *norm_vector)
{
    if (*angle < -90 || *angle > 180) {
        *angle = -90;
        norm_vector->x = -1;
        norm_vector->y = 0;
    } else if (*angle > 90) {
        *angle = 90;
        norm_vector->x = 1;
        norm_vector->y = 0;
    }
}

void setup_projectile(game_data_t *g_data, sprite_data_t *projectile)
{
    sfVector2f ship_pos = sfSprite_getPosition(g_data->ship->sprite);
    sfFloatRect ship_rect = sfSprite_getGlobalBounds(g_data->ship->sprite);
    sfFloatRect projectile_rect = sfSprite_getGlobalBounds(projectile->sprite);
    float middle_ship_x = ship_pos.x + ship_rect.width / 2;
    float middle_ship_y = ship_pos.y + ship_rect.width / 2;
    float x = middle_ship_x - projectile_rect.width / 2;
    float y = middle_ship_y - projectile_rect.height / 2;

    projectile->speed = PROJECTILE_SPEED;
    projectile->norm_vector = calc_projectile_vector(g_data, middle_ship_x,
        middle_ship_y);
    float angle = atan2(projectile->norm_vector.y, projectile->norm_vector.x)
        * (180.0 / M_PI) + 90;
    check_shoot_angle(&angle, &projectile->norm_vector);
    sfSprite_setRotation(projectile->sprite, angle);
    sfSprite_setPosition(projectile->sprite, (sfVector2f){x, y});
}
