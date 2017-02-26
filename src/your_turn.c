/*
** your_turn.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:13:45 2017 Brice Lang-Nguyen
** Last update Sun Feb 26 13:31:57 2017 Brice
*/

#include <stdlib.h>
#include "matchstick.h"

int	is_good(int nb_of_matches, char **map, arg argument, int line)
{
  if (nb_of_matches == 0)
    {
      my_putstr("Error: you have to remove at least one match\n");
      return (false);
    }
  else if (nb_of_matches < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (false);
    }
  else if (nb_of_matches > check_nb_stick(map, argument, line))
    {
      my_putstr("Error: not enough matches on this line\n");
      return (false);
    }
  else if (nb_of_matches > argument.nb_rm_stick)
    {
      my_putstr("Error: you cannot remove more than ");
      my_put_nbr(argument.nb_rm_stick);
      my_putstr(" matches per turn\n");
      return (false);
    }
  return (true);
}

int	what_line(arg argument)
{
  char	*input;
  int	line;

  input = get_next_line(0);
  if (input == NULL)
    return (-1);
  if (any_char(input))
    {
      my_putstr("ERROR: invalid input (positive number expected)\n");
      return (0);
    }
  line = my_getnbr(input);
  if (line <= 0 || line > argument.line)
    {
      my_putstr("ERROR: this line is out of range\n");
      return (0);
    }
  free(input);
  return (line);
}

int	your_turn(char **map, arg argument)
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
      if ((line = what_line(argument)) == -1)
	return (-1);
      else if (line > 0)
	{
	  line -= 1;
	  my_putstr("Matches: ");
	  input = get_next_line(0);
	  nb_of_matches = my_getnbr(input);
	  if (is_good(nb_of_matches, map, argument, line) && !any_char(input))
	    state = 1;
	}
    }
  rm_matches(line, nb_of_matches, map, argument);
  free(input);
  display_result(line, nb_of_matches, 0);
  return (0);
}
