/**
** @file set_tab_inputs.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"game.h"

void		set_tab_inputs(double	*inputs,
			       char	*tab,
			       char	symbol)
{
  size_t	i;

  i = 0;
  while (i != 9)
    {
      inputs[i] = (tab[i] == symbol) ? 1 : (tab[i] == ' ') ? 0 : -1;
      i++;
    }  
}
