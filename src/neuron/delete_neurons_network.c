/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** delete_neuron_network - 2022
**
** *****************************************************************************
*/

#include                "neuron.h"

void			delete_neuron_network(t_neuron_network		*network)
{
  size_t		i;
  size_t		j;

  free((network->array[0]).neurons);
  i = 1;
  while (i != network->nbr_array)
    {
      j = 0;
      while (j != (network->array[i]).nbr_neurons)
	{
	  free((network->array[i]).neurons[j].inputs);
	  j++;
	}
      free((network->array[i]).neurons);
      i++;
    }
  free(network->array);
  free(network);
}
