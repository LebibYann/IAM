/**
** @file print_base10.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include        "libstd.h"

void		print_base10(int	nbr)
{
  int		val;

  if (nbr < -9 || nbr > 9)
    print_base10(nbr / 10);
  else if (nbr < 0)
    write(1, "-", sizeof(char));
  val = ((nbr < 0) ? -1 : 1) * (nbr % 10) + '0';
  write(1, &val, sizeof(char));
}
