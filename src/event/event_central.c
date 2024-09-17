/*
** EPITECH PROJECT, 2021
** event_central
** File description:
** Central event
*/

#include "defender.h"
#include "cursor_path.h"

void event_game_central(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    int detect = -1;

    if (game->event.type == sfEvtMouseMoved)
        turret_mouseover(mouse_pos, game);
    if (game->event.type == sfEvtMouseButtonPressed &&
    sfMouse_isButtonPressed(sfMouseLeft))
        drop_turret(mouse_pos, game);
    detect = detect_shop_mouseover(mouse_pos, &game->shop);
    if (game->event.type == sfEvtMouseButtonPressed &&
    sfMouse_isButtonPressed(sfMouseLeft) && detect != -1) {
        change_cursor(game, detect);
        if (detect == 2)
            game->game_status = menu_pause;
    }
}

int event_central(game_t *game)
{
    if (game->game_status == start_game)
        event_game_central(game);
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    return 0;
}
