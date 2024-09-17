/*
** EPITECH PROJECT, 2021
** move_mobs
** File description:
** Move the mobs
*/

#include "defender.h"
#include "my.h"
#include "mobs.h"

void move_right(mobs_s *mobs, double off_x, double off_y, float speed)
{
    sfVector2f offset = {off_x, off_y};

    mobs->step += speed;
    if (mobs->step > 60) {
        mobs->step = 0;
        if (offset.x > 0.0)
            mobs->pos_x++;
        else if (offset.x < 0.0)
            mobs->pos_x--;
        if (offset.y > 0.0)
            mobs->pos_y++;
        else if (offset.y < 0.0)
            mobs->pos_y--;
    }
    sfSprite_setTextureRect(mobs->s_mobs, mobs->rect);
    sfSprite_move(mobs->s_mobs, offset);
    sfText_move(mobs->txt, offset);
}

void mobs_spritesheet(mobs_s *mobs, time_handle_t *timer)
{
    mobs->timeout -= timer->delta_time;
    if (mobs->timeout <= 0) {
        mobs->timeout = TIMEOUT_RESET;
        mobs->rect.left += 60;
        if (mobs->rect.left % 180 == 0)
            mobs->rect.left = mobs->rect.left - 180;
    }
}

void move_mobs(mobs_s *mobs, map_t *map, time_handle_t *timer)
{
    float speed = mobs->speed * timer->delta_time;

    switch (map->map[mobs->pos_y][mobs->pos_x]) {
        case 'D':
            mobs->rect.top = 360;
            move_right(mobs, speed, 0, speed);
            break;
        case 'Q':
            mobs->rect.top = 300;
            move_right(mobs, -speed, 0, speed);
            break;
        case 'Z':
            mobs->rect.top = 420;
            move_right(mobs, 0, -speed, speed);
            break;
        case 'S':
            mobs->rect.top = 240;
            move_right(mobs, 0, speed, speed);
            break;
    }
}

void move_every_mobs(game_t *game)
{
    mobs_s *tmp = game->mobs;

    while (tmp != NULL) {
        move_mobs(tmp, game->map, game->timer);
        mobs_spritesheet(tmp, game->timer);
        tmp = tmp->next;
    }
}
