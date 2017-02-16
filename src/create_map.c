/*
** create_map.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:09:40 2017 Brice Lang-Nguyen
** Last update Thu Feb 16 20:21:23 2017 Brice Lang-Nguyen
*/

#include <stdlib.h>
#include "matchstick.h"

char	**create_map(arg argument)
{
  char	**tab;
  char	*tab2;
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(char*) * argument.line)) == NULL)
    return (NULL);
  if ((tab2 = malloc(sizeof(char) * argument.line * argument.base)) == NULL)
    return (NULL);
  while (i < argument.line)
    {
      tab[i] = &tab2[i * argument.base];
      i++;
    }
  filled_map(tab, argument);
  return (tab);
}
