/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** Reproduce the behavior of thestrstrfunction.
*/

int my_strlen(char const *str);

char *cpmy_strstr(char *str, char const *to_find) {
    for (int i  = 0, j = 0, n = my_strlen(to_find); str[i] != '\0'; i++) {
        for (; to_find[j] != '\0' && str[i] == to_find[j]; j++, i++) {
            if (to_find[j] == '\0')
                return (&str[i - n]);
        }
    }
    return "";
}
