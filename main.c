/*
** main.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Wed Feb 15 11:44:15 2017 Brice Lang-Nguyen
** Last update Thu Feb 16 17:55:12 2017 Brice Lang-Nguyen
*/

#include <time.h>
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

void	draw_line(arg argument)
{
  int	i;

  i = 0;
  while (i < argument.base + 2)
    {
      my_putchar('*');
      i++;
    }
  my_putchar('\n');
  return ;
}


void	display_map(char **map, arg argument)
{
  int	i;
  int	j;

  draw_line(argument);
  i = 0;
  while (i < argument.line)
    {
      j = 0;
      my_putchar('*');
      while (j < argument.base)
	my_putchar(map[i][j++]);
      my_putstr("*\n");
      i++;
    }
  draw_line(argument);
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
  return (tab);
}

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

void	rm_matches(int line, int nb_of_matches, char **map, arg argument)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < argument.base)
    {
      if (map[line][i] == '|')
	j++;
      i++;
    }
  if (j < nb_of_matches)
    return ;
  i = argument.base;
  while (map[line][i] != '|')
    {
      i--;
    }
  j = 0;
  while (j < nb_of_matches)
    {
      map[line][i] = ' ';
      i--;
      j++;
    }
  return ;
}

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

int	check_nb_stick(char **map, arg argument, int line)
{
  int	i;
  int	nb_of_stick;

  i = 0;
  nb_of_stick = 0;
  while (i < argument.line * 2 - 1)
    {
      if (map[line][i] == '|')
	nb_of_stick++;
      i++;
    }
  return (nb_of_stick);
}

void	your_turn(char **map, arg argument)
{
  char	*input;
  int	line;
  int	nb_of_matches;
  int	state;

  my_putstr("Your turn:\n");
  state = 0;
  while (!state)
    {
      my_putstr("Line: ");
      input = get_next_line(0);
      line = my_getnbr(input) - 1;
      free(input);
      if (line + 1 >= 1 && line + 1 <= argument.line)
	{
	  my_putstr("Matches: ");
	  input = get_next_line(0);
	  nb_of_matches = my_getnbr(input);
	  if (nb_of_matches <= check_nb_stick(map, argument, line))
	    {
	      if (nb_of_matches <= argument.nb_rm_stick)
		state = 1;
	      else
		{
		  my_putstr("Error: you cannot remove more than ");
		  my_put_nbr(argument.nb_rm_stick);
		  my_putstr(" matches per turn\n");
		}
	    }
	  else
	    my_putstr("Error: not enough matches on this line\n");
	}
      else
	my_putstr("Error: this line is out of range\n");
    }
  rm_matches(line, nb_of_matches, map, argument);
  free(input);
  display_result(line, nb_of_matches, 0);
}


void	ia_turn(char **map, arg argument)
{
  int	line;
  int	state;
  int	nb_of_matches;

  my_putstr("AI's turn...\n");
  srand(time(NULL));
  state = 0;
  while (!state)
    {
      line = rand() % (argument.line - 1) + 1;
      nb_of_matches = rand() % (argument.nb_rm_stick - 1) + 1;
      if (nb_of_matches <= check_nb_stick(map, argument, line))
	state = 1;
    }
  rm_matches(line, nb_of_matches, map, argument);
  display_result(line, nb_of_matches, 1);
}

int	game_loop(char **map, arg argument)
{
  int	state;
  int	turn;

  state = 0;
  turn = 0;
  while (!state)
    {
      display_map(map, argument);
      if (turn == 0)
	{
	  your_turn(map, argument);
	  turn = 1;
	}
      else
	{
	  ia_turn(map, argument);
	  turn = 0;
	}
      if (check_map(map, argument) && turn == 0)
	return (1);
      else if (check_map(map, argument) && turn == 1)
	return (2);
    }
  return (0);
}

int	prep_game(char **argv)
{
  arg	argument;
  char	**map;
  int	return_value;

  argument.line = my_getnbr(argv[1]);
  argument.nb_rm_stick = my_getnbr(argv[2]);
  argument.base = argument.line * 2 - 1;
  map = create_map(argument);
  return_value = game_loop(map, argument);
  display_map(map, argument);
  if (return_value == 1)
    my_putstr("I lost... snif... but I'll get you next time!!\n");
  else if (return_value == 2)
    my_putstr("You lost, too bad...\n");
  free(map[0]);
  free(map);
  return (return_value);
}


int	main(int argc, char **argv)
{
  int	return_value;

  if (!(verif(argc, argv)))
    return (84);
  if ((return_value = prep_game(argv)))
    return (return_value);
  return (EXIT_SUCCESS);
}
