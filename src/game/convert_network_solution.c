/**
** @file convert_network_solution.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"game.h"

int		convert_network_solution(t_neuron_network	*network)
{
  int		i;
  int		best_solution;
  double	coefficient;
  double	best_coefficient;

  best_solution = -1;
  best_coefficient = 0;
  i = 0;
  while (i != 9)
    {
      coefficient = network->array[network->nbr_array - 1].neurons[i].coefficient;
      if (coefficient == 1)
	return (i);
      if (coefficient > 0.5 && coefficient > best_coefficient)
	{
	  best_solution = i;
	  best_coefficient = coefficient;
	}
      i++;
    }
  return (best_solution);
}
