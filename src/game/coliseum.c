/**
** @file coliseum.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"game.h"

#define		NO_ONE_DIES 1

int		coliseum(t_neuron_network	*fighter1,
			 t_neuron_network	*fighter2)
{
  char		tab[9];
  
  init_tab(tab);
  while (NO_ONE_DIES)
    {
      if (ai_game_turn(tab, 'X', fighter1) == -1)
	return (1);
      if (check_table(tab) == 1)
	return (0);
      if (ai_game_turn(tab, 'O', fighter2) == -1)
        return (0);
      if (check_table(tab) == 1)
        return (1);
    }
}
