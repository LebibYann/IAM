/**
** @file ai_game_turn.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"game.h"

int		ai_game_turn(char		*tab,
			     char		symbol,
			     t_neuron_network	*network)
{
  double	inputs[9];

  set_tab_inputs(inputs, tab, symbol);
  compute_neuron_network(network, inputs);
  if (add_symbol_in_tab(convert_network_solution(network), tab, symbol, true) == false)
    return (-1);
  return (0);
}
