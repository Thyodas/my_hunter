/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** score
*/

#include "my.h"
#include "game_data.h"

char *my_struint_base(int nbr, char *str, char const *base, int precision);

void create_score(game_data_t *g_data)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("resources/font.ttf");

    sfText_setFont(text, font);
    sfText_setPosition(text, (sfVector2f){30, -30});
    sfText_setString(text, "score 0");
    sfText_setCharacterSize(text, 100);
    g_data->text_score = text;
}

void update_score(game_data_t *g_data)
{
    char *result = my_strdup("score ");

    result = my_struint_base(g_data->score, result, "0123456789", -1);
    my_revstr(result + 6);
    sfText_setString(g_data->text_score, result);
    free(result);
}
