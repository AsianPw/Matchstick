/*
** display_result.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:12:20 2017 Brice Lang-Nguyen
** Last update Thu Feb 16 20:12:42 2017 Brice Lang-Nguyen
*/

#include "matchstick.h"

void	display_result(int line, int nb_of_matches, int who)
{
  if (who == 0)
    my_putstr("Player removed ");
  else
    my_putstr("AI removed ");
  my_put_nbr(nb_of_matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line + 1);
  my_putchar('\n');
  return ;
}
