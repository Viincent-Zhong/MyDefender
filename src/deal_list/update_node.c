/*
** EPITECH PROJECT, 2021
** update_node
** File description:
** Update a node at a given position
*/

#include "defender.h"

void update_node_x(mobs_s **head, int i)
{
    mobs_s *update = *head;

    for (int x = 0; x < i; x++)
        update = update->next;
    update->pos_x = 123;
}