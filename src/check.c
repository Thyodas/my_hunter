/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** check.c
*/

#include "my.h"
#include "game_data.h"

int cmp_nb(sprite_data_t *sprite, int *nb) {
    return (sprite->id == *nb ? 0 : -1);
}

int check_collision(game_data_t *g_data, sprite_data_t *projectile,
sprite_data_t *ennemy)
{
    sfFloatRect projectile_box = sfSprite_getGlobalBounds(projectile->sprite);
    sfFloatRect ennemy_box = sfSprite_getGlobalBounds(ennemy->sprite);

    if (sfFloatRect_intersects(&ennemy_box, &projectile_box, NULL)) {
        sfSprite_destroy(projectile->sprite);
        sfSprite_destroy(ennemy->sprite);
        my_delete_nodes(&g_data->ennemy_list, &ennemy->id, &cmp_nb);
        my_delete_nodes(&g_data->projectile_list, &projectile->id, &cmp_nb);
        ++g_data->score;
        return (1);
    }
    return (0);
}

void check_btw_ennemy_projectile(game_data_t *g_data)
{
    linked_list_t *head_projectile = g_data->projectile_list;
    linked_list_t *head_ennemy = g_data->ennemy_list;
    linked_list_t *tmp_ennemy = NULL;
    linked_list_t *tmp_projectile = NULL;
    int collided = 0;

    for (int i = 0 ; head_projectile != NULL ; ++i) {
        tmp_projectile = head_projectile;
        head_projectile = head_projectile->next;
        for (int j = 0 ; head_ennemy != NULL && !collided ; ++j) {
            tmp_ennemy = head_ennemy;
            head_ennemy = head_ennemy->next;
            collided = check_collision(g_data, tmp_projectile->data,
                tmp_ennemy->data);
        }
        head_ennemy = g_data->ennemy_list;
        collided = 0;
    }
}
