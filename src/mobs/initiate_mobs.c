/*
** EPITECH PROJECT, 2021
** initiate_mobs
** File description:
** Initiate the mobs
*/

#include "defender.h"

void set_spawn(game_t *game, char carac, int k)
{
    for (int x = 0; game->map->map[0][x] != '\0'; x++) {
        carac = game->map->map[0][x];
        if (carac == 'Q' || carac == 'Z' || carac == 'S' || carac == 'D') {
            game->spawner->spawn[k] = malloc(sizeof(int *) * 2);
            game->spawner->spawn[k][0] = x;
            game->spawner->spawn[k][1] = 0;
            k++;
        }
    }
    for (int y = 0; game->map->map[y] != NULL; y++) {
        carac = game->map->map[y][0];
        if (carac == 'Q' || carac == 'Z' || carac == 'S' || carac == 'D') {
            game->spawner->spawn[k] = malloc(sizeof(int *) * 2);
            game->spawner->spawn[k][0] = 0;
            game->spawner->spawn[k][1] = y;
            k++;
        }
    }
}

void initialise_spawn_point(game_t *game)
{
    game->spawner = malloc(sizeof(spawn_t));
    game->spawner->spawn = malloc(sizeof(char *) * 3);
    for (int i = 0; i < 3; i++)
        game->spawner->spawn[i] = NULL;
    set_spawn(game, '\0', 0);
}

void initialise_mobs(game_t *game)
{
    sfTexture *texture = sfTexture_createFromFile("image/monster.png", NULL);
    sfVector2f pos = {game->spawner->spawn[0][0] * 60,
    game->spawner->spawn[0][1] * 60};

    insert_node(&game->mobs, create_node(texture, pos, game));
}
