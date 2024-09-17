/*
** EPITECH PROJECT, 2021
** free_print_list
** File description:
** Free or print list
*/

#include "defender.h"
#include "my.h"
#include <stdlib.h>

void print_hp(mobs_s *tmp, sfRenderWindow *window)
{
    int pour;
    char *hp_act;
    char *fini;

    pour = (tmp->health * 100) / tmp->max_health;
    hp_act = int_to_str(pour);
    fini = malloc(sizeof(char) * (my_strlen(hp_act) + 2));
    fini = my_strcpy(fini, hp_act);
    fini = my_strcat(fini, "%");
    sfText_setString((tmp->txt), fini);
    sfRenderWindow_drawText(window, tmp->txt, NULL);
    free(hp_act);
    free(fini);
}

void printlist(mobs_s *head, sfRenderWindow *window)
{
    mobs_s *tmp = head;

    while (tmp != NULL) {
        if (tmp->s_mobs) {
            sfRenderWindow_drawSprite(window, tmp->s_mobs, NULL);
            print_hp(tmp, window);
        }
        tmp = tmp->next;
    }
}

void free_list(mobs_s *head)
{
    mobs_s *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        if (tmp->s_mobs)
            sfSprite_destroy(tmp->s_mobs);
        free(tmp);
    }
}
