/*
** EPITECH PROJECT, 2021
** remove_node
** File description:
** Remove node of a list
*/

#include "defender.h"
#include <stdlib.h>

void remove_first(mobs_s **head)
{
    mobs_s *to_remove = *head;

    if (*head == to_remove) {
        *head = to_remove->next;
    }
    to_remove->next = NULL;
}

void remove_last(mobs_s **head)
{
    mobs_s *to_remove = *head;

    while (to_remove->next->next != NULL)
        to_remove = to_remove->next;
    if (*head == to_remove) {
        *head = to_remove->next;
    }
    to_remove->next = NULL;
}

void remove_x(mobs_s **head, int i)
{
    mobs_s *to_remove = *head;

    if (i == 0) {
        remove_first(head);
        return;
    }
    to_remove = *head;
    for (int x = 1; x < i; x++)
        to_remove = to_remove->next;
    to_remove->next = to_remove->next->next;
}