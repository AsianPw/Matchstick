/*
** rm_matches.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:11:12 2017 Brice Lang-Nguyen
** Last update Sat Feb 25 11:26:04 2017 Brice
*/

#include "matchstick.h"

void	rm_matches(int line, int nb_of_matches, char **map, arg argument)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < argument.base)
    {
      if (map[line][i] == '|')
	j++;
      i++;
    }
  if (j < nb_of_matches)
    return ;
  //i = argument.base;
  while (map[line][i] != '|')
    {
      i--;
    }
  j = 0;
  while (j < nb_of_matches)
    {
      map[line][i] = ' ';
      i--;
      j++;
    }
}
