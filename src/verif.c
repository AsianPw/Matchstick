/*
** verif.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:03:30 2017 Brice Lang-Nguyen
** Last update Thu Feb 16 20:22:45 2017 Brice Lang-Nguyen
*/

#include <unistd.h>
#include "matchstick.h"

int	verif(int argc, char **argv)
{
  int	tmp;

  if (argc > 3)
    {
      write(2, "ERROR: Too Much Argument\n", 25);
      return (false);
    }
  else if (argc < 3)
    {
      write(2, "ERROR: Not Enough Argument\n", 27);
      return (false);
    }
  tmp = my_getnbr(argv[1]);
  if (tmp < 1 || tmp > 100)
    {
      write(2, "The size should be between 1 and 100\n", 37);
      return (false);
    }
  tmp = my_getnbr(argv[2]);
  if (tmp <= 0)
    {
      write(2, "The 2nd argument must be strictly positive\n", 44);
      return (false);
    }
  return (true);
}
