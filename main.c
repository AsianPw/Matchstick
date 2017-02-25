/*
** main.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Wed Feb 15 11:44:15 2017 Brice Lang-Nguyen
** Last update Sat Feb 25 11:06:28 2017 Brice
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "matchstick.h"
#include "msg.h"

int	game_loop(char **map, arg argument)
{
  int	state;
  int	turn;

  state = 0;
  turn = 0;
  while (!state)
    {
      display_map(map, argument);
      my_putchar('\n');
      if (turn == 0)
	{
	  if (your_turn(map, argument) == -1)
	    return (-1);
	  turn = 1;
	}
      else
	{
	  ia_turn(map, argument);
	  turn = 0;
	}
      if (check_map(map, argument) && turn == 0)
	return (1);
      else if (check_map(map, argument) && turn == 1)
	return (2);
    }
  return (0);
}

int	prep_game(char **argv)
{
  arg	argument;
  char	**map;
  int	return_value;

  argument.line = my_getnbr(argv[1]);
  argument.nb_rm_stick = my_getnbr(argv[2]);
  argument.base = argument.line * 2 - 1;
  map = create_map(argument);
  return_value = game_loop(map, argument);
  if (return_value == -1)
    return (return_value);
  display_map(map, argument);
  if (return_value == 1)
    my_putstr(IA_FAIL);
  else if (return_value == 2)
    my_putstr(PLAYER_FAIL);
  free(map[0]);
  free(map);
  return (return_value);
}


int	main(int argc, char **argv)
{
  int	return_value;

  if (!(verif(argc, argv)))
    return (84);
  if ((return_value = prep_game(argv)))
    return (return_value);
  return (EXIT_SUCCESS);
}
