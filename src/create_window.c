/*
** EPITECH PROJECT, 2021
** create_window
** File description:
** Create window
*/

#include "defender.h"
#include "my.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "My Window",
    sfTitlebar | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}