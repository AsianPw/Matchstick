/*
** verif.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:03:30 2017 Brice Lang-Nguyen
** Last update Sun Feb 26 13:18:06 2017 Brice
*/

#include <unistd.h>
#include "matchstick.h"
#include "msg.h"

int	is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (true);
  return (false);
}

int	any_char(char *argv)
{
  int	i;

  i = 0;
  while (argv[i] != '\0')
    {
      if (!is_num(argv[i]))
	return (true);
      i++;
    }
  return (false);
}

int	verif(int argc, char **argv)
{
  int	tmp;

  if (argc > 3)
    {
      write(2, MUCH_ARG, my_strlen(MUCH_ARG));
      return (false);
    }
  else if (argc < 3)
    {
      write(2, MISS_ARG, my_strlen(MISS_ARG));
      return (false);
    }
  tmp = my_getnbr(argv[1]);
  if ((tmp < 1 || tmp > 100) || any_char(argv[1]))
    {
      write(2, ERR_SIZE, my_strlen(ERR_SIZE));
      return (false);
    }
  tmp = my_getnbr(argv[2]);
  if (tmp <= 0 || any_char(argv[2]))
    {
      write(2, ERR_POS, my_strlen(ERR_POS));
      return (false);
    }
  return (true);
}
