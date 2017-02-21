NAME	= matchstick

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
	  ./src/check_map.c \
	  ./src/check_nb_stick.c \
	  ./src/create_map.c \
	  ./src/display_map.c \
	  ./src/display_result.c \
	  ./src/draw_line.c \
	  ./src/filled_map.c \
	  ./src/get_next_line.c \
	  ./src/ia_turn.c \
	  ./src/ia_turn2.c \
	  ./src/my_getnbr.c \
	  ./src/my_put_nbr.c \
	  ./src/my_putchar.c \
	  ./src/my_putstr.c \
	  ./src/my_strlen.c \
	  ./src/rm_matches.c \
	  ./src/verif.c \
	  ./src/your_turn.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I./inc/
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
