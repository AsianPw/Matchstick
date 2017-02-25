/*
** main.c for gnl in /home/brice/Documents/CPE/CPE_2016_getnextline
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Tue Feb 14 17:11:12 2017 Brice Lang-Nguyen
** Last update Sat Feb 25 10:56:20 2017 Brice
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

char		get_next_char(const int fd)
{
  static char	buff[READ_SIZE];
  static char	*pos;
  static int	len = 0;
  char		c;

  if (len == 0)
    {
      len = read(fd, buff, READ_SIZE);
      pos = &buff[0];
      if (len == 0)
	return (0);
    }
  c = *pos;
  pos++;
  len--;
  return (c);
}

char	*get_next_line(const int fd)
{
  char	*res;
  char	char_in_prog;
  int	size;

  size =  0;
  if ((res = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (NULL);
  char_in_prog = get_next_char(fd);
  while (char_in_prog != '\n' && char_in_prog != '\0')
    {
      res[size] = char_in_prog;
      char_in_prog = get_next_char(fd);
      size++;
      if (size == READ_SIZE)
	res = my_realloc(res);
    }
  res[size] = '\0';
  if (char_in_prog == '\0' && res[0] == 0)
    return (NULL);
  return (res);
}
