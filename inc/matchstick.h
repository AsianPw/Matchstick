
/*
** matchstick.h for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Wed Feb 15 11:47:15 2017 Brice Lang-Nguyen
** Last update Wed Feb 15 19:29:42 2017 Brice Lang-Nguyen
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

char	*get_next_line(const int fd);

int	my_put_nbr(int nb);
int	my_getnbr(char*);
int	my_strlen(char*);

void	my_putchar(char c);

#endif /* !MATCHSTICK */
