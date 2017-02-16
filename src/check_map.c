/*
** check_map.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:10:36 2017 Brice Lang-Nguyen
** Last update Thu Feb 16 20:10:57 2017 Brice Lang-Nguyen
*/

#include "matchstick.h"

int	check_map(char	**map, arg argument)
{
  int	i;
  int	j;

  i = 0;
  while (i < argument.line)
    {
      j = 0;
      while (j < argument.base)
	{
	  if (map[i][j] == '|')
	    return (false);
	  j++;
	}
      i++;
    }
  return (true);
}
