/**
** @file puts.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include        "libstd.h"

int		std_puts(const char		*str)
{
  return (write(1, str, std_strlen(str)));
}
