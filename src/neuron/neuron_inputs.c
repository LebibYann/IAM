/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** new_inputs - 2022
**
** *****************************************************************************
*/

#include		"neuron.h"

t_neuron_input		*neuron_inputs(t_neuron		*neuron,
				       t_neuron_array	*inputs)
{
  size_t		i;

  neuron->inputs = malloc(inputs->nbr_neurons * sizeof(t_neuron_input));
  if (neuron->inputs == NULL)
    return (NULL);
  i = 0;
  while (i != inputs->nbr_neurons)
    {
      neuron->inputs[i].neuron = &(inputs->neurons[i]);
      neuron->inputs[i].weight = ((rand() % 1000) / 100.0) * ((rand() % 2 == 0) ? 1 : -1);
      i++;
    }
  return (neuron->inputs);
}
