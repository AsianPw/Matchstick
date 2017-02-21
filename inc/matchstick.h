/*
** matchstick.h for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Wed Feb 15 11:47:15 2017 Brice Lang-Nguyen
** Last update Mon Feb 20 16:16:18 2017 Brice Lang-Nguyen
*/

#ifndef __MATCHSTICK__
 #define __MATCHSTICK__

typedef enum
  {
    false,
    true
  } Bool;

typedef struct arg
{
  int	base;
  int	line;
  int	nb_rm_stick;
} arg;

char	*get_next_line(const int);

char	**create_map(arg);

int	check_map(char**, arg);
int	check_nb_stick(char**, arg, int);
int	my_put_nbr(int);
int	my_getnbr(char*);
int	my_strlen(char*);
int	verif(int, char**);

void	display_map(char**, arg);
void	display_result(int, int, int);
void	draw_line(arg);
void	filled_map(char**, arg);
void	ia_turn(char**, arg);
void	ia_turn2(char **, arg);
void	my_putchar(char);
void	my_putstr(char*);
void	rm_matches(int, int, char**, arg);
void	your_turn(char**, arg);

#endif /* !MATCHSTICK */
