/*
** EPITECH PROJECT, 2021
** initiate_base
** File description:
** Initiate base
*/

#include "defender.h"

sfVector2f get_base_pos(game_t *game)
{
    sfVector2f pos = {0, 0};

    for (int i = 0, j = 0; game->map->map[i] != NULL; j++) {
        if (game->map->map[i][j] == '\0') {
            i++;
            j = 0;
        }
        if (game->map->map[i][j] == 'E') {
            pos.x = j * 60 + 10;
            pos.y = i * 60 - 25;
            break;
        }
    }
    return pos;
}

void initialise_base(game_t *game)
{
    sfVector2f pos = get_base_pos(game);
    sfTexture *texture =
    sfTexture_createFromFile("image/health_bar.png", NULL);

    game->base = malloc(sizeof(base_t));
    game->base->health_bar_s = create_sprite(texture, pos);
    texture = sfTexture_createFromFile("image/health.png", NULL);
    pos.x += 17;
    pos.y += 9;
    game->base->health_bar_bs = create_sprite(texture, pos);
    game->base->health_bar.height = 11;
    game->base->health_bar.width = 77;
    game->base->health_bar.left = 0;
    game->base->health_bar.top = 0;
    sfSprite_setTextureRect(game->base->health_bar_bs, game->base->health_bar);
    game->base->health = 20;
    game->base->sound_attack = sfMusic_createFromFile("sound/oof.ogg");
}