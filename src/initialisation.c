/*
** EPITECH PROJECT, 2021
** initialisation
** File description:
** Initiate everything
*/

#include "my.h"
#include "defender.h"
#include <stdlib.h>

void initiate_drag(game_t *game)
{
    sfTexture *texture = sfTexture_createFromFile("image/map.png", NULL);
    sfVector2f pos = {0, 0};

    game->map->map_bg = create_sprite(texture, pos);
    game->drag = malloc(sizeof(drag_t));
    game->drag->nbr_turret = 0;
    game->drag->drag_status = 123;
    game->drag->over = 0;
}

void initialise_map(game_t *game)
{
    int nbr_elem = 0;
    int k = 0;

    game->map->map_x = 0;
    game->map->map_y = 0;
    create_map(game->map, "map_boucle.txt");
    initiate_drag(game);
    nbr_elem = get_nbr_elem(game->map->map);
    game->s_map = malloc(sizeof(bg_t *) * (nbr_elem + 1));
    for (int i = 0; game->map->map[i] != NULL; i++)
        for (int j = 0; game->map->map[i][j] != '\0'; j++)
            add_bg_elem(game, i, j, &k);
    game->s_map[k] = NULL;
    set_turret_point(game);
    create_turret(game);
}

void init_menu(game_t *game)
{
    initialise_menu(game);
}

void init_game(game_t *game)
{
    game->map = malloc(sizeof(map_t));
    initialise_map(game);
    initialise_spawn_point(game);
    initialise_cursor(game);
    init_shop(game);
    initialise_coin(&game->coin, &game->coin_text);
    game->timer = malloc(sizeof(time_handle_t));
    game->game_status = start_menu;
    start_timer(game->timer);
    initialise_base(game);
    game->random_seed = 0;
}

void initialisation(game_t *game)
{
    init_menu(game);
    init_game(game);
    initialise_pause(game);
    initialise_loose(game);
    initiate_score(game);
    game->mobs = NULL;
    game->bg_music = sfMusic_createFromFile("sound/bg_sound.ogg");
    sfMusic_setVolume(game->bg_music, 40);
    sfMusic_play(game->bg_music);
    sfMusic_setLoop(game->bg_music, sfTrue);
}
