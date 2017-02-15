/*
** main.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Wed Feb 15 11:44:15 2017 Brice Lang-Nguyen
** Last update Wed Feb 15 14:29:02 2017 Brice Lang-Nguyen
*/

#include <unistd.h>
#include <stdlib.h>
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

void	my_putchar(char c)
{
  write(1, &c, 1);
  return ;
}

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

void	display_map(char **map, arg argument)
{
  int	i;
  int	j;

  i = 0;
  while (i < argument.base + 2)
    {
      my_putstr("*");
      i++;
    }
  my_putchar('\n');
  i = 0;
  while (i < argument.line)
    {
      j = 0;
      my_putstr("*");
      while (j < argument.base)
	my_putchar(map[i][j++]);
      my_putstr("*\n");
      i++;
    }
  i = 0;
  while (i < argument.base + 2)
    {
      my_putstr("*");
      i++;
    }
  my_putchar('\n');
  return ;
}


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
  display_map(tab, argument);
  return (tab);
}


int	game(char **argv)
{
  arg	argument;
  char	**map;

  argument.line = my_getnbr(argv[1]);
  argument.nb_rm_stick = my_getnbr(argv[2]);
  argument.base = argument.line * 2 - 1;
  map = create_map(argument);
  free(map[0]);
  free(map);
  return (0);
}


int	main(int argc, char **argv)
{
  int	return_value;

  if (!(verif(argc, argv)))
    return (84);
  if ((return_value = game(argv)))
    return (return_value);
  return (EXIT_SUCCESS);
}
