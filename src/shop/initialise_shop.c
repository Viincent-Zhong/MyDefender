/*
** EPITECH PROJECT, 2021
** initialise shop
** File description:
** Initialise the shop
*/

#include "filepath.h"
#include "defender.h"

void create_tower_button(sfVector2f *pos,
sfVector2f *incre, int *increx, int *increy)
{
    (*pos) = shop_button_pos(250, 867);
    (*increx) = 153;
    (*increy) = 0;
    (*incre) = shop_button_pos(127, 129);
}

void define_button_pos(int i,
sfVector2f *pos, sfVector2f *incre)
{
    if (i == 2) {
        (*pos) = shop_button_pos(1535, 855);
        (*incre) = shop_button_pos(150, 152);
    }
}

void create_shop(game_t *game)
{
    sfTexture *texture =
    sfTexture_createFromFile("image/Bouton_shop/sell.png", NULL);
    sfVector2f incre = {250, 70};
    sfVector2f pos = {880, 781};
    int i = 0;

    game->shop->shop_but = malloc(sizeof(but_shop *) * (7 + 1));
    for (int increy = 77, increx = 0; i < 7; i++) {
        game->shop->shop_but[i] = malloc(sizeof(but_shop));
        pos.y += increy;
        pos.x += increx;
        define_button_pos(i, &pos, &incre);
        if (i == 3)
            create_tower_button(&pos, &incre, &increx, &increy);
        texture = sfTexture_createFromFile(button_path[i], NULL);
        game->shop->shop_but[i] =
        create_shop_button(create_sprite(texture, pos), incre, pos);
    }
    game->shop->shop_but[i] = NULL;
}

void init_shop(game_t *game)
{
    sfTexture *texture;
    sfVector2f pos = {0, -45};

    game->shop = malloc(sizeof(shop_t));
    texture = sfTexture_createFromFile("image/Bouton_shop/planche.png", NULL);
    game->shop->board = create_sprite(texture, pos);
    texture = sfTexture_createFromFile("image/Bouton_shop/piece.png", NULL);
    game->shop->piece = create_sprite(texture, shop_button_pos(1150, 875));
    create_shop(game);
    game->shop->over = 0;
    game->shop->last_sprite = 0;
}