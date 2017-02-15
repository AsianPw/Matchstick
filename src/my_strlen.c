/*
** my_strlen.c for matchstick in /home/brice/Documents/CPE/CPE_2016_matchstick
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Wed Feb 15 12:15:12 2017 Brice Lang-Nguyen
** Last update Wed Feb 15 12:15:42 2017 Brice Lang-Nguyen
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
