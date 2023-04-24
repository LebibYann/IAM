/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** load_neuron_network - 2022
**
** *****************************************************************************
*/

#include		"neuron.h"

static int		load_neuron_array(t_bunny_configuration		*cnf,
					  size_t			step,
					  t_neuron_array		*array,
					  t_neuron_array		*inputs)
{
  size_t		i;
  size_t		j;
  int			size;

  bunny_configuration_getf_int(cnf, &size, "Network[0].Array[%ld].Nbr_neurons", step);
  array->nbr_neurons = (size_t) size;
  array->neurons = malloc(array->nbr_neurons * sizeof(t_neuron));
  if (array->neurons == NULL)
    return (-1);
  i = 0;
  while (i != array->nbr_neurons)
    {
      j = 0;
      array->neurons[i].nbr_inputs = inputs->nbr_neurons;
      array->neurons[i].inputs = malloc(inputs->nbr_neurons * sizeof(t_neuron_input));
      while (j != array->neurons[i].nbr_inputs)
	{
	  bunny_configuration_getf_double(cnf, &array->neurons[i].inputs[j].weight,
					  "Network[0].Array[%ld].Neuron[%ld].Inputs[0].Weight[%ld]", step, i, j);
	  array->neurons[i].inputs[j].neuron = &inputs->neurons[j];
	  j++;
	}
      array->neurons[i].output_value = true;
      bunny_configuration_getf_double(cnf, &array->neurons[i].bias, "Network[0].Array[%ld].Neuron[%ld].Bias", step, i);
      i++;
    }
  return (0);
}

t_neuron_network	*load_neuron_network(t_bunny_configuration	*cnf)
{
  t_neuron_network	*network;
  t_neuron_array	*inputs;
  size_t		i;
  int			size;

  network = malloc(sizeof(t_neuron_network));
  if (network == NULL)
    return (NULL);
  bunny_configuration_getf_int(cnf, &size, "Network[0].Nbr_array");
  network->nbr_array = (size_t)	size;
  network->array = malloc(network->nbr_array * sizeof(t_neuron_array));
  if (network->array == NULL)
    return (NULL);
  i = 1;
  bunny_configuration_getf_int(cnf, &size, "Network[0].Array[0].Nbr_neurons");
  network->array[0].nbr_neurons = (size_t) size;
  network->array[0].neurons = malloc(network->array[0].nbr_neurons * sizeof(t_neuron));
  inputs = &(network->array[0]);
  while (i != network->nbr_array)
    {
      if (load_neuron_array(cnf, i, &network->array[i], inputs) == -1)
	return (NULL);
      inputs = &network->array[i];
      i++;
    }
  return (network);
}
