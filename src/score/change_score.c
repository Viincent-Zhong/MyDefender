/*
** EPITECH PROJECT, 2021
** change_score
** File description:
** Change the score
*/

#include "defender.h"
#include "my.h"

void change_max_score(int max_score, int score)
{
    FILE *fd;
    char *max;

    if (score <= max_score)
        return;
    fd = fopen("score.txt", "w");
    max = int_to_str(score);
    fwrite(max, 1, sizeof(char) *  my_strlen(max), fd);
    fclose(fd);
}

void change_score(int score, sfText *text)
{
    char *t_score = int_to_str(score);
    char *tmp = malloc(sizeof(char) *
    (my_strlen("Score : ") + my_strlen(t_score) + 1));

    tmp[0] = '\0';
    my_strcat(tmp, "Score : ");
    my_strcat(tmp, t_score);
    sfText_setString(text, tmp);
}