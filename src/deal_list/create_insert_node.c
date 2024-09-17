/*
** EPITECH PROJECT, 2021
** create_insert_node
** File description:
** Create or insert node into the list
*/

#include "defender.h"
#include <stdlib.h>

mobs_s *type_of_mob(game_t *game, mobs_s* new_mobs)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    int value = mouse_pos.x * mouse_pos.y + game->random_seed++;

    if (value < 0)
        value = value * -1;
    srand(value);
    value = rand() % 10;
    change_info_mobs(new_mobs, value);
    return new_mobs;
}

sfText *init_hp_mob(mobs_s *new_mobs)
{
    sfFont *font = sfFont_createFromFile("image/Font.ttf");

    new_mobs->txt = sfText_create();
    sfText_setFont((new_mobs->txt), font);
    sfText_setColor((new_mobs->txt), sfBlack);
    sfText_setCharacterSize((new_mobs->txt), 25);
    sfText_setPosition(new_mobs->txt,
    get_position((new_mobs->pos_x * 60) + 10, (new_mobs->pos_y * 60) - 20));
    return new_mobs->txt;
}

mobs_s *create_node(sfTexture *texture, sfVector2f pos, game_t *game)
{
    mobs_s *new_mobs = malloc(sizeof(mobs_s));

    new_mobs->s_mobs = create_sprite(texture, pos);
    new_mobs->pos_x = pos.x / 60;
    new_mobs->pos_y = pos.y / 60;
    new_mobs->next = NULL;
    new_mobs->step = 0;
    new_mobs = type_of_mob(game, new_mobs);
    new_mobs->txt = init_hp_mob(new_mobs);
    new_mobs->rect.top = 240;
    new_mobs->rect.width = 60;
    new_mobs->rect.height = 60;
    new_mobs->timeout = TIMEOUT_RESET;
    new_mobs->attack_speed = AS;
    sfSprite_setTextureRect(new_mobs->s_mobs, new_mobs->rect);
    return new_mobs;
}

void insert_node(mobs_s **head, mobs_s *to_insert)
{
    mobs_s *tmp = (*head);

    to_insert->next = NULL;
    if (*head == NULL) {
        *head = to_insert;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = to_insert;
}
