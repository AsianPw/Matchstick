/*
** ia_turn.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:14:23 2017 Brice Lang-Nguyen
** Last update Sat Feb 25 11:28:34 2017 Brice
*/

#include <time.h>
#include <stdlib.h>
#include "matchstick.h"

void	ia_turn(char **map, arg argument)
{
  int	line;
  int	state;
  int	nb_of_matches;

  my_putstr("AI's turn...\n");
  srand(time(NULL));
  state = 0;
  while (!state)
    {
      line = rand() % (argument.line);
      nb_of_matches = rand() % (argument.nb_rm_stick) + 1;
      if (nb_of_matches <= check_nb_stick(map, argument, line))
	{
	  if (nb_of_matches > 0)
	    state = 1;
	}
    }
  rm_matches(line, nb_of_matches, map, argument);
  display_result(line, nb_of_matches, 1);
}
