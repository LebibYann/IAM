/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** set_inputs - 2022
**
** *****************************************************************************
*/

#include	"neuron.h"

void		set_inputs(t_neuron_array	inputs,
			   double		*inputs_values)
{
  size_t	i;

  i = 0;
  while (i != inputs.nbr_neurons)
    {
      inputs.neurons[i].output_value = true;
      inputs.neurons[i].coefficient = inputs_values[i];
      i++;
    }
}
