/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** compute_neuron_network - 2022
**
** *****************************************************************************
*/

#include		"neuron.h"

t_neuron_network	*compute_neuron_network(t_neuron_network	*network,
						double			*input)
{
  size_t		i;
  size_t		j;

  set_inputs(network->array[0], input);
  i = 1;
  while (i != network->nbr_array)
    {
      j = 0;
      while (j != network->array[i].nbr_neurons)
	{
	  compute_neuron(&(network->array[i].neurons[j]));
	  j++;
	}
      i++;
    }
  return (network);
}

