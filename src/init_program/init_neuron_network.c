/**
** @file init_neuron_network.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"init_program.h"

bool		init_neuron_network(t_neuron_network	**network,
				    t_neuron_parameters	*parameters)
{
  t_bunny_configuration	*cnf;

  if ((cnf = bunny_open_configuration("Default_network.dab", NULL)) != NULL)
    *network = load_neuron_network(cnf);
  else
    {
      if (new_neuron_parameters(parameters) == false)
	return (false);
      *network = neuron_network(parameters->neurons_per_array, parameters->nbr_arrays);
    }
  if (*network == NULL)
    return (false);
  return (true);
}
