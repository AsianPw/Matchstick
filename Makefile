##
## Makefile for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
## 
## Made by Brice Lang-Nguyen
## Login   <brice.lang-nguyen@epitech.eu>
## 
## Started on  Wed Feb 15 13:55:59 2017 Brice Lang-Nguyen
## Last update Wed Feb 15 18:38:21 2017 Brice Lang-Nguyen
##

NAME	= matchstick

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
	  ./src/my_getnbr.c \
	  ./src/get_next_line.c \
	  ./src/my_put_nbr.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I./inc/
CFLAGS += -g -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 @$(CC) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
