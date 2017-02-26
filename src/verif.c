/*
** verif.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:03:30 2017 Brice Lang-Nguyen
** Last update Sun Feb 26 11:01:08 2017 Brice
*/

#include <unistd.h>
#include "matchstick.h"
#include "msg.h"

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
  if (tmp < 1 || tmp > 100)
    {
      write(2, ERR_SIZE, my_strlen(ERR_SIZE));
      return (false);
    }
  tmp = my_getnbr(argv[2]);
  if (tmp <= 0)
    {
      write(2, ERR_POS, my_strlen(ERR_POS));
      return (false);
    }
  return (true);
}
