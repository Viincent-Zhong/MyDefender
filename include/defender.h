/*
** EPITECH PROJECT, 2021
** defender
** File description:
** Defender header file
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include "struct_defender.h"

mobs_s *create_node(sfTexture *texture, sfVector2f pos, game_t *game);
void insert_node(mobs_s **head, mobs_s *to_insert);
void remove_first(mobs_s **head);
void remove_last(mobs_s **head);
void printlist(mobs_s *head, sfRenderWindow *window);
void free_list(mobs_s *head);
int create_map(map_t *map, char *map_filepath);
char *get_buffer(char *buffer, int size, int fd);
int open_file(char const *filepath);
void initialisation(game_t *game);
sfRenderWindow *create_window(unsigned int width, unsigned int height);
void add_bg_elem(game_t *game, int i, int j, int *k);
int get_nbr_elem(char **map);
sfSprite *create_sprite(sfTexture *texture, sfVector2f pos);
sfRenderWindow *create_window(unsigned int width, unsigned int height);
void move_mobs(mobs_s *mobs, map_t *map, time_handle_t *timer);
void initialise_mobs(game_t *game);
void initialise_spawn_point(game_t *game);
void set_spawn(game_t *game, char carac, int k);
void set_turret_point(game_t *game);
void free_all(game_t *game);
void create_turret(game_t *game);
int detect_collision(sfVector2i mouse_pos, int x, int y);
void init_shop(game_t *game);
int detect_shop(sfVector2i mouse_pos, shop_t **shop);
int detect_shop_mouseover(sfVector2i mouse_pos, shop_t **shop);
int detect_mouse(sfVector2i mouse_pos, sfVector2f pos, sfVector2f incre);
void unmouse_over_shop(shop_t **shop, int i);
int event_central(game_t *game);
void initialise_cursor(game_t *game);
void change_cursor(game_t *game, int detect);
void set_default_cursor(game_t *game);
void drop_turret(sfVector2i mouse_pos, game_t *game);
void turret_mouseover(sfVector2i mouse_pos, game_t *game);
void change_cursor_texture(game_t *game, int detect, char *path);
void upgrade_turret(game_t *game, int i);
void initialise_menu(game_t *game);
sfVector2f get_position(int pos_x, int pos_y);
void menu(game_t *game);
void sell_turret(game_t *game, int i);
void initialise_coin(int *coin, sfText **text);
void update_coin(int coin, sfText **coin_text);
void define_turret(game_t *game, sfVector2f pos, int i);
void game_central(game_t *game);
void turret_attack(game_t *game);
void mobs_in_range(game_t *game);
void remove_x(mobs_s **head, int i);
void update_node_x(mobs_s **head, int i);
void move_every_mobs(game_t *game);
void spawn_mobs(game_t *game);
void initialise_base(game_t *game);
void attack_base(game_t *game);
void initialise_pause(game_t *game);
void pause_menu(game_t *game);
void free_sprite(sfSprite **sprite);
but_shop *create_shop_button(sfSprite *sprite,
sfVector2f incre, sfVector2f pos);
sfVector2f shop_button_pos(int posx, int posy);
char *read_file(char *filepath);
void initiate_score(game_t *game);
void change_max_score(int max_score, int score);
char *int_to_str(int nb);
void change_score(int score, sfText *text);
void htp(game_t *game);
void loose_menu(game_t *game);
void initialise_loose(game_t *game);
void free_music(sfMusic **music);
void free_five(game_t *game);
void change_info_mobs(mobs_s *new_mobs, int value);

#endif /* !DEFENDER_H_ */
