/*
** my_putchar.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb 16 20:04:18 2017 Brice Lang-Nguyen
** Last update Thu Feb 16 20:04:47 2017 Brice Lang-Nguyen
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
