/*
** main.c for gnl in /home/brice/Documents/CPE/CPE_2016_getnextline
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Tue Feb 14 17:11:12 2017 Brice Lang-Nguyen
** Last update Thu Feb 16 20:24:18 2017 Brice Lang-Nguyen
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "matchstick.h"
#define READ_SIZE 100

char	*my_realloc(char *str)
{
  char	*new;
  int	i;

  if ((new = malloc(sizeof(char) * my_strlen(str) + READ_SIZE + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  free(str);
  return (new);
}


char	*get_next_line(const int fd)
{
  char	buff[READ_SIZE + 1];
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((res = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (NULL);
  buff[READ_SIZE] = '\0';
  while (buff[j] != '\n')
    {
      if (j == 0)
	read(fd, buff, READ_SIZE);
      if (j == 0 && i != 0)
	res = my_realloc(res);
      res[i] = buff[j];
      i++;
      if (j > READ_SIZE - 1)
	j = 0;
      else
	j++;
    }
  return (res);
}
