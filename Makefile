##
## EPITECH PROJECT, 2020
## mk
## File description:
## mk
##

SRCS	=	src/main.c	\
			src/deal_list/create_insert_node.c	\
			src/deal_list/remove_node.c	\
			src/deal_list/free_print_list.c	\
			src/background/create_map.c	\
			src/background/read_file.c	\
			src/initialisation.c	\
			src/background/create_background.c	\
			src/create_sprite.c	\
			src/create_window.c	\
			src/mobs/move_mobs.c	\
			src/mobs/initiate_mobs.c	\
			src/turret/set_turret_spawn.c	\
			src/free_all.c	\
			src/turret/drag_and_drop.c	\
			src/event/mouse_collision.c	\
			src/shop/initialise_shop.c	\
			src/shop/shop_mouseover.c	\
			src/time/handle_time.c	\
			src/event/event_central.c	\
			src/cursor/initialise_cursor.c	\
			src/cursor/change_cursor.c	\
			src/turret/upgrade_turret.c	\
			src/menu/initialise_menu.c	\
			src/menu/menu.c	\
			src/turret/sell_turret.c	\
			src/coin/initialise_coin.c	\
			src/coin/update_coin.c	\
			src/coin/int_to_str.c	\
			src/turret/drop_turret.c	\
			src/loop/gameloop.c	\
			src/turret/turret_detect_mobs.c	\
			src/deal_list/update_node.c	\
			src/mobs/spawn_mobs.c	\
			src/base/initiate_base.c	\
			src/mobs/attack_base.c	\
			src/pause_menu/init_pause.c	\
			src/pause_menu/pause_menu.c	\
			src/free_sprite.c	\
			src/shop/initialise_button_shop.c	\
			src/score/initiate_score.c	\
			src/score/change_score.c	\
			src/menu/htp.c	\
			src/loose/init_loose.c	\
			src/loose/loose_menu.c	\
			src/free_all_two.c	\
			src/mobs/define_mobs_stat.c

SRCS_UNIT =     tests/test_pushswap.c		\

OBJS	=	$(SRCS:.c=.o)

NAME	=	defender

RM	=		rm -f

INC	=		-I./include

LIB	=		-L./lib/my -lmy

CC	=		gcc

CFLAGS	=	$(INC) -W -Wall -Wextra -g3

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C lib/my/
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIB) -l csfml-graphics -l csfml-audio -l csfml-system -lcsfml-window

clean:
			make clean -C ./lib/my/
			$(RM) $(OBJS)

fclean: 	clean
		rm -f $(NAME)
		rm -f -r *~

re:			fclean all

tests_run:	fclean
			clear
			gcc -o unit_tests $(SRCS_UNIT) $(INC) --coverage -lcriterion
			./unit_tests
			gcovr
