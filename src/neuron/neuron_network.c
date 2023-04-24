/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** neuron_network - 2022
**
** *****************************************************************************
*/

#include		"neuron.h"

t_neuron_network	*neuron_network(size_t		*array_width,
					size_t		nbr_array)
{
  t_neuron_network	*network;
  size_t		i;

  if ((network = malloc(sizeof(t_neuron_network))) == NULL)
    return (NULL);
  if ((network->array = malloc(nbr_array * sizeof(t_neuron_array))) == NULL)
    return (NULL);
  if (new_neuron_array(&(network->array[0]), array_width[0], NULL) == false)
    {
      free(network->array);
      free(network);
      return (NULL);
    }
  i = 1;
  while (i != nbr_array)
    {
      if (new_neuron_array(&(network->array[i]), array_width[i], &(network->array[i - 1])) == false) 
	{
	  while (i != 0)
	    {
	      free((network->array[i]).neurons);
	      i--;
	    }
	  free(network->array);
	  free(network);
	  return (NULL);
	}
      i++;
    }
  network->nbr_array = nbr_array;
  return (network);
}
