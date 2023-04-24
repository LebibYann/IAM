/**
** @file add_symbol_in_tab.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"game.h"

bool		add_symbol_in_tab(int	position,
				  char	*tab,
				  char	symbol,
				  bool	ai)
{
  if (position == -1)
    return (false);
  if (tab[position] != ' ')
    {
      if (ai == false)
	std_puts("Impossiblen this position is already choosen\n");
      return (false);
    }
  tab[position] = symbol;
  return (true);
}
