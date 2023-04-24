/**
** @file new_neuron_parameters.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"init_program.h"

bool		new_neuron_parameters(t_neuron_parameters	*parameters)
{
  size_t	i;

  puts("How many hidden layers do you want ?\n");
  parameters->nbr_arrays = read_number();
  if (parameters->neurons_per_array == NULL)
    free(parameters->neurons_per_array);
  parameters->neurons_per_array = malloc((parameters->nbr_arrays + 2) * sizeof(size_t));
  if (parameters->neurons_per_array == NULL)
    return (false);
  parameters->neurons_per_array[0] = 9;
  i = 1;
  while (i != parameters->nbr_arrays + 1)
    {
      parameters->neurons_per_array[i] = read_number();
      if (parameters->neurons_per_array[i] > 0)
	i++;
    }
  parameters->neurons_per_array[i] = 9;
  return (true);
}

