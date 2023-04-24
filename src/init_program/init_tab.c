/**
** @file init_tab.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include        "game.h"

void		init_tab(char	*tab)
{
  size_t	i;

  i = 0;
  while (i != 9)
    {
      tab[i] = ' ';
      i++;
    }
}
