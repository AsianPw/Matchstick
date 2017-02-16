/*
** filled_map.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:05:45 2017 Brice Lang-Nguyen
** Last update Thu Feb 16 20:06:14 2017 Brice Lang-Nguyen
*/

#include "matchstick.h"

void	filled_map(char **map, arg argument)
{
  int	i;
  int	j;
  int	base_in;

  i = 0;
  while (i < argument.line)
    {
      j = 0;
      base_in = i * 2 - 1;
      while (j < argument.base)
	{
	  if (j < (argument.base - base_in) / 2 - 1)
	    map[i][j] = ' ';
	  else if (j > (argument.base - base_in) / 2 + base_in)
	    map[i][j] = ' ';
	  else
	    map[i][j] = '|';
	  j++;
	}
      i++;
    }
  return ;
}
