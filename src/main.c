/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"
#include "defender.h"
#include <stdlib.h>

void defender_central(game_t *game)
{
    menu(game);
    htp(game);
    game_central(game);
    update_time(game->timer);
    pause_menu(game);
    loose_menu(game);
}

int defender(void)
{
    game_t *game = malloc(sizeof(game_t));

    initialisation(game);
    game->window = create_window(1920, 1080);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    while (sfRenderWindow_isOpen(game->window)
    && game->game_status != exit_status) {
        defender_central(game);
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            event_central(game);
    }
    free_all(game);
    sfRenderWindow_destroy(game->window);
    free(game);
    return 0;
}

int main(int ac, char **av)
{
    if (ac > 1)
        return 84;
    if (defender() == 84)
        return 84;
    return 0;
}
