/*
** EPITECH PROJECT, 2021
** initiate_score.c
** File description:
** Initiate the score
*/

#include "defender.h"
#include "my.h"

void initiate_score(game_t *game)
{
    char *str_score = read_file("score.txt");
    sfFont *font = sfFont_createFromFile("image/Font.ttf");
    sfVector2f pos = {800, 100};

    game->score = malloc(sizeof(score_t));
    if (str_score)
        game->score->max_score = my_getnbr(str_score);
    game->score->score = 0;
    game->score->text_score = sfText_create();
    sfText_setFont(game->score->text_score, font);
    sfText_setColor(game->score->text_score, sfBlack);
    sfText_setCharacterSize(game->score->text_score, 70);
    sfText_setPosition(game->score->text_score, pos);
    change_score(game->score->score, game->score->text_score);
    return;
}