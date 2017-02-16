/*
** draw_line.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:07:55 2017 Brice Lang-Nguyen
** Last update Thu Feb 16 20:08:20 2017 Brice Lang-Nguyen
*/

#include "matchstick.h"

void	draw_line(arg argument)
{
  int	i;

  i = 0;
  while (i < argument.base + 2)
    {
      my_putchar('*');
      i++;
    }
  my_putchar('\n');
  return ;
}
