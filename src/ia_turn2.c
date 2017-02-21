/*
** ia_turn2.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Mon Feb 20 16:08:34 2017 Brice Lang-Nguyen
** Last update Tue Feb 21 16:39:41 2017 Brice Lang-Nguyen
*/

#include <stdlib.h>
#include "matchstick.h"

int	how_many_stick(char **map, arg argument)
{
  int	x;
  int	y;
  int	stick;

  x = 0;
  y = 0;
  stick = 0;
  while (map[y][x] != '\0')
    {
      if (map[y][x] == '|')
	stick++;
      if (x >= argument.base)
	{
	  x = 0;
	  y++;
	}
      else
	x++;
    }
  return (stick - 1);
}


void	ia_turn2(char **map, arg argument)
{
  int	state;
  int	line;
  int	stick;

  state = 0;
  my_putstr("AI2's turn...\n");
  line = (rand() % argument.line) - 1;
  while (!state)
    {
      stick = (rand() % argument.nb_rm_stick);
      if (stick != 0 && stick <= check_nb_stick(map, argument, line))
	state = 1;
    }
  rm_matches(line, stick, map, argument);
  display_result(line, stick, 1);
  return ;
}
