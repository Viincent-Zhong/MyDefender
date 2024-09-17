/*
** EPITECH PROJECT, 2021
** create_map
** File description:
** Create the map
*/

#include "defender.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void get_max_x(map_t *map, int k)
{
    if (map->map_x < k)
        map->map_x = k;
}

int get_arr_size(char *buffer, map_t *map)
{
    int size = 0;

    for (int i = 0, k = 0; buffer[i] != '\0'; i++, k++) {
        if (buffer[i] == '\n') {
            size++;
            get_max_x(map, k);
            k = 0;
        }
    }
    map->map_y = size;
    return size;
}

char **change_to_array(char *buffer, map_t *map)
{
    char **arr = malloc(sizeof(char *) * (get_arr_size(buffer, map) + 2));
    int j = 0;

    for (int i = 0, x = 0; buffer[i] != '\0'; i++, j++) {
        arr[j] = malloc(sizeof(char) * (map->map_x));
        for (x = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++, x++)
            arr[j][x] = buffer[i];
        arr[j][x] = '\0';
    }
    arr[j] = NULL;
    return arr;
}

int create_map(map_t *map, char *map_filepath)
{
    int fd = open_file(map_filepath);
    struct stat caracnumber;
    char *buffer;

    if (fd == 84)
        return 84;
    stat(map_filepath, &caracnumber);
    buffer = malloc(sizeof(char) * (caracnumber.st_size + 2));
    if (buffer == NULL)
        return 84;
    buffer = get_buffer(buffer, caracnumber.st_size + 1, fd);
    if (buffer == NULL)
        return 84;
    map->map = change_to_array(buffer, map);
    return 0;
}