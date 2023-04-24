/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** neuron_network - 2022
**
** *****************************************************************************
*/

#include                "neuron.h"

bool			new_neuron_array(t_neuron_array		*array,	
					 size_t			nbr_neurons,
					 t_neuron_array		*inputs)
{
  size_t		i;

  array->neurons = malloc(nbr_neurons * sizeof(t_neuron));
  if (array->neurons == NULL)
    return (0);
  i = 0;
  array->nbr_neurons = nbr_neurons;
  while (i != nbr_neurons)
    {
      if (new_neuron(&(array->neurons[i]), inputs) == NULL)
	return (0);
      i++;
    }
  return (true);
}
