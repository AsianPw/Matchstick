/*
** your_turn.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:13:45 2017 Brice Lang-Nguyen
** Last update Thu Feb 16 20:23:23 2017 Brice Lang-Nguyen
*/

#include <stdlib.h>
#include "matchstick.h"

void	your_turn(char **map, arg argument)
{
  char	*input;
  int	line;
  int	nb_of_matches;
  int	state;

  my_putstr("Your turn:\n");
  state = 0;
  while (!state)
    {
      my_putstr("Line: ");
      input = get_next_line(0);
      line = my_getnbr(input) - 1;
      free(input);
      if (line + 1 >= 1 && line + 1 <= argument.line)
	{
	  my_putstr("Matches: ");
	  input = get_next_line(0);
	  nb_of_matches = my_getnbr(input);
	  if (nb_of_matches > 0)
	    {
	      if (nb_of_matches <= check_nb_stick(map, argument, line))
		{
		  if (nb_of_matches <= argument.nb_rm_stick)
		    state = 1;
		  else
		    {
		      my_putstr("Error: you cannot remove more than ");
		      my_put_nbr(argument.nb_rm_stick);
		      my_putstr(" matches per turn\n");
		    }
		}
	      else
		my_putstr("Error: not enough matches on this line\n");
	    }
	  else if (nb_of_matches == 0)
	    my_putstr("Error: you have to remove at least one match\n");
	  else if (nb_of_matches < 0)
	    my_putstr("Error: invalid input (positive number expected)\n");
	}
      else
	my_putstr("Error: this line is out of range\n");
    }
  rm_matches(line, nb_of_matches, map, argument);
  free(input);
  display_result(line, nb_of_matches, 0);
}
