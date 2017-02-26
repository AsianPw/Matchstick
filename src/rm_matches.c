/*
** rm_matches.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:11:12 2017 Brice Lang-Nguyen
** Last update Sun Feb 26 10:47:26 2017 Brice
*/

#include "matchstick.h"

void	rm_matches(int line, int nb_of_matches, char **map, arg argument)
{
  int	i;

  i = argument.base - 1;
  while (map[line][i] != '|')
    i--;
  while (nb_of_matches > 0)
    {
      map[line][i] = ' ';
      i--;
      nb_of_matches--;
    }
  return ;
}
