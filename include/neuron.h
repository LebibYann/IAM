/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** neuron - 2022
**
** *****************************************************************************
*/

#include			<stdlib.h>
#include			<stdbool.h>
#include			<lapin.h>
#include			<time.h>

#ifndef				__NEURON_H__
#define				__NEURON_H__

#define				ABS(a) ((a) < 0) ? ((a) * -1) : (a)

struct				s_neuron_input;

typedef struct                  s_neuron
{
  double                        coefficient;
  double			bias;
  struct s_neuron_input		*inputs;
  size_t			nbr_inputs;
  bool                          output_value;
}                               t_neuron;

typedef struct			s_neuron_input
{
  t_neuron			*neuron;
  double			weight;
}				t_neuron_input;
  
typedef struct                  s_neuron_array
{
  t_neuron			*neurons;
  size_t                        nbr_neurons;
}                               t_neuron_array;

typedef struct			s_neuron_network
{
  t_neuron_array		*array;
  size_t			nbr_array;
}				t_neuron_network;

typedef struct			s_preset
{
  double			*inputs;
  double			*outputs;
}				t_preset;

t_neuron			*new_neuron(t_neuron				*neuron,
					    t_neuron_array			*inputs);

t_neuron_input			*neuron_inputs(t_neuron				*neuron,
					       t_neuron_array			*neurons);

bool				new_neuron_array(t_neuron_array			*array,
						 size_t				nbr_neurons,
						 t_neuron_array			*inputs);

t_neuron_network		*neuron_network(size_t				*array_width,
						size_t				nbr_array);

void				delete_neuron_network(t_neuron_network		*network);

t_neuron_network		*compute_neuron_network(t_neuron_network	*network,
							double                  *input);

void				set_inputs(t_neuron_array			inputs,
					   double				*inputs_values);

void				compute_neuron(t_neuron				*neuron);

void				save_neuron_network(t_neuron_network		*network,
						    char			*name);

t_neuron_network		*load_neuron_network(t_bunny_configuration      *cnf);

#endif
