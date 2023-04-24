/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** compute_neuron - 2022
**
** *****************************************************************************
*/

#include	"neuron.h"

void		compute_neuron(t_neuron		*neuron)
{
  size_t	i;
  
  i = 0;
  neuron->coefficient = 0;
  while (i != neuron->nbr_inputs)
    {
      if (neuron->inputs[i].neuron->output_value == true)
	neuron->coefficient += neuron->inputs[i].neuron->coefficient	\
	  * neuron->inputs[i].weight + neuron->bias;
      i++;
    }
  neuron->coefficient = 1 / (1 + exp(-neuron->coefficient));
  if (neuron->coefficient <= 0.5)
    neuron->output_value = false;
  else
    neuron->output_value = true;
}

