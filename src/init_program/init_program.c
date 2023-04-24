/**
** @file init_program.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"init_program.h"

bool		init_program(t_iam	*iam)
{
  init_parameters(&iam->parameters);
  init_neuron_network(&iam->default_network,
		      &iam->parameters.neuron);
  init_players(iam->players);
  return (true);
}
