/**
** @file init_program.h
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#ifndef		__INIT_PROGRAM_H__
#define		__INIT_PROGRAM_H__

#include	"global.h"

#define		P1_S 'X'
#define		P2_S 'O'

#define		INIT_NEURON_PARAMETERS ({ t_neuron_parameters parameters; \
      parameters.nbr_arrays = 0;					\
      parameters.neurons_per_array = NULL;				\
      parameters;})

bool            init_program(t_iam			*iam);

bool            init_neuron_network(t_neuron_network    **network,
                                    t_neuron_parameters *parameters);

bool            init_players(t_player			*players);

void		init_parameters(t_parameters		*parameters);

bool            new_neuron_parameters(t_neuron_parameters       *parameters);

#endif
