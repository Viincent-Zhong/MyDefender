/*
** EPITECH PROJECT, 2021
** create_background
** File description:
** Create the backgrounds
*/

#include "defender.h"
#include "my.h"
#include <stdlib.h>
#include "background_path.h"
#include <stdio.h>
#include <time.h>

int get_nbr_elem(char **map)
{
    int nbr_elem = 0;

    for (int y = 0, x = 0; map[y] != NULL; x++) {
        if (map[y][x] != ' ')
            nbr_elem++;
        if (map[y][x] == '\n' || map[y][x] == '\0') {
            y++;
            x = 0;
        }
    }
    return nbr_elem;
}

sfTexture *create_decor(char to_check)
{
    sfTexture *texture = NULL;

    switch (to_check) {
        case 'A':
            texture = sfTexture_createFromFile("image/tree.png", NULL);
            break;
        case 'F':
            texture = sfTexture_createFromFile(flower_path[rand() % 4], NULL);
            break;
        case 'R':
            texture = sfTexture_createFromFile("image/rock.png", NULL);
            break;
        case 'E':
            texture = sfTexture_createFromFile("image/base.png", NULL);
    }
    return texture;
}

sfTexture *get_bg_texture(char to_check, game_t *game)
{
    sfTexture *texture;

    texture = create_decor(to_check);
    if (to_check == 'T') {
        game->drag->nbr_turret++;
        texture = sfTexture_createFromFile("image/turret.png", NULL);
    }
    if (to_check == 'D' || to_check == 'S' || to_check == 'Q'
    || to_check == 'Z')
        texture = sfTexture_createFromFile("image/road.png", NULL);
    return texture;
}

void add_bg_elem(game_t *game, int i, int j, int *k)
{
    char to_check = game->map->map[i][j];
    sfTexture *texture;
    sfVector2f pos;

    texture = get_bg_texture(to_check, game);
    if (to_check != ' ') {
        srand(i);
        game->s_map[*k] = malloc(sizeof(bg_t));
        pos.x = j * 60;
        pos.y = i * 60;
        game->s_map[*k]->bg_elem = create_sprite(texture, pos);
        (*k)++;
    }
}
