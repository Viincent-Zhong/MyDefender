/*
** EPITECH PROJECT, 2021
** shop_mouseover
** File description:
** Shop mouseover
*/

#include "defender.h"
#include "filepath.h"

void unmouse_over_shop(shop_t **shop, int i)
{
    sfTexture *texture;

    if ((*shop)->over == 0) {
        (*shop)->over = 1;
        (*shop)->last_sprite = i;
        texture = sfTexture_createFromFile
        (button_over[(*shop)->last_sprite], NULL);
        sfSprite_setTexture((*shop)->shop_but[(*shop)->last_sprite]->shop,
        texture, sfTrue);
    }
}

int detect_shop(sfVector2i mouse_pos, shop_t **shop)
{
    sfVector2f pos = {0, 0};
    sfVector2f incre = {0, 0};

    for (int i = 0; (*shop)->shop_but[i] != NULL; i++) {
        pos.x = (*shop)->shop_but[i]->pos_x;
        pos.y = (*shop)->shop_but[i]->pos_y;
        incre.x = (*shop)->shop_but[i]->incre_x;
        incre.y = (*shop)->shop_but[i]->incre_y;
        if (detect_mouse(mouse_pos, pos, incre) == 1) {
            unmouse_over_shop(shop, i);
            return i;
        }
    }
    return -1;
}

int detect_shop_mouseover(sfVector2i mouse_pos, shop_t **shop)
{
    sfTexture *texture;
    int detect = detect_shop(mouse_pos, shop);

    if ((*shop)->over == 1 && detect == -1) {
        texture = sfTexture_createFromFile(button_path[(*shop)->last_sprite],
        NULL);
        sfSprite_setTexture((*shop)->shop_but[(*shop)->last_sprite]->shop,
        texture, sfTrue);
        (*shop)->over = 0;
        return detect;
    }
    return detect;
}