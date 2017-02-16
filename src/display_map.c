/*
** display_map.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:08:51 2017 Brice Lang-Nguyen
** Last update Thu Feb 16 20:09:21 2017 Brice Lang-Nguyen
*/

#include "matchstick.h"

void	display_map(char **map, arg argument)
{
  int	i;
  int	j;

  draw_line(argument);
  i = 0;
  while (i < argument.line)
    {
      j = 0;
      my_putchar('*');
      while (j < argument.base)
	my_putchar(map[i][j++]);
      my_putstr("*\n");
      i++;
    }
  draw_line(argument);
  return ;
}
