/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** new_neuron - 2022
**
** *****************************************************************************
*/

#include	"neuron.h"

t_neuron	*new_neuron(t_neuron		*neuron,
			    t_neuron_array	*inputs)
{
  neuron->bias = ((rand() % 1000) / 100.0) * ((rand() % 2 == 0) ? 1 : -1);
  if (inputs != NULL)
    {
      neuron_inputs(neuron, inputs);
      neuron->nbr_inputs = inputs->nbr_neurons;
    }
  neuron->output_value = true;
  return (neuron);
}

