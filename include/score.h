/*
** EPITECH PROJECT, 2021
** score
** File description:
** Score structure
*/

#ifndef SCORE_H_
#define SCORE_H_

#include <SFML/Graphics.h>

typedef struct score_s {
    int max_score;
    int score;
    sfText *text_score;
}score_t;

#endif /* !SCORE_H_ */