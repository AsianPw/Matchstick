/*
** check_nb_stick.c for matchsick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:12:57 2017 Brice Lang-Nguyen
** Last update Thu Feb 16 20:13:21 2017 Brice Lang-Nguyen
*/

#include "matchstick.h"

int	check_nb_stick(char **map, arg argument, int line)
{
  int	i;
  int	nb_of_stick;

  i = 0;
  nb_of_stick = 0;
  while (i < argument.line * 2 - 1)
    {
      if (map[line][i] == '|')
	nb_of_stick++;
      i++;
    }
  return (nb_of_stick);
}
