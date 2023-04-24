/**
** @file atoi.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include        "libstd.h"

int		std_atoi(const char	*nptr)
{
  size_t	i;
  int		value;

  i = 0;
  value = 0;
  while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i] != '\0')
    {
      value *= 10;
      value += nptr[i] - '0';
      i++;
    }
  return (value);
}
