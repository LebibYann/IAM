/**
** @file strlen.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include        "libstd.h"

size_t		std_strlen(const char	*str)
{
  size_t	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
