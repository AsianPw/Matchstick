/*
** my_putstr.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:05:00 2017 Brice Lang-Nguyen
** Last update Thu Feb 16 20:05:27 2017 Brice Lang-Nguyen
*/

#include "matchstick.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return ;
}
