/**
** @file exit_iam.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include        "iam.h"

int		exit_iam(t_iam		iam)
{
  save_neuron_network(iam.default_network, "Default_network.dab");
  if (iam.default_network != NULL)
    delete_neuron_network(iam.default_network);
  if (iam.parameters.neuron.neurons_per_array)
    free(iam.parameters.neuron.neurons_per_array);
  return (0);
}
