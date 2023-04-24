/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** save_neuron_netowrk - 2022
**
** *****************************************************************************
*/

#include		"neuron.h"

static void		save_neuron(t_bunny_configuration	*cnf,
				    size_t			i,
				    size_t			j,
				    t_neuron			neuron)
{
  size_t		k;

  k = 0;
  bunny_configuration_setf_double(cnf, neuron.bias, "Network[0].Array[%ld].Neuron[%ld].Bias", i, j);
  bunny_configuration_setf_int(cnf, neuron.nbr_inputs, "Network[0].Array[%ld].Neuron[%ld].Nbr_inputs", i, j);
  while (k != neuron.nbr_inputs)
    {
      bunny_configuration_setf_double					\
	(cnf, neuron.inputs[k].weight, "Network[0].Array[%ld].Neuron[%ld].Inputs[0].Weight[%ld]", i, j, k);
      k++;
    }
}

void			save_neuron_network(t_neuron_network	*network,
					     char		*name)
{
  t_bunny_configuration	*cnf;
  size_t		i;
  size_t		j;

  if (name == NULL)
    return;
  if ((cnf = bunny_new_configuration()) == NULL)
    return;
  i = 1;
  bunny_configuration_setf_int(cnf, network->nbr_array, "Network[0].Nbr_array");
  bunny_configuration_setf_int(cnf, network->array[0].nbr_neurons, "Network[0].Array[0].Nbr_neurons");
  while (i != network->nbr_array)
    {
      j = 0;
      bunny_configuration_setf_int(cnf, network->array[i].nbr_neurons, "Network[0].Array[%ld].Nbr_neurons", i);
      while (j != network->array[i].nbr_neurons)
	{
	  save_neuron(cnf, i, j, network->array[i].neurons[j]);
	  j++;
	}
      i++;
    }
  bunny_save_configuration(BC_DABSIC, name, cnf);
}
