/**
** @file iam.h
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#ifndef                 __GLOBAL_H__
#define                 __GLOBAL_H__

#include                "neuron.h"
#include		"libstd.h"

typedef enum            e_type
  {
    PLAYER,
    AI
  }                     t_type;

typedef struct          s_player
{
  int                   type;
  char                  symbol;
}                       t_player;

typedef struct          s_neuron_parameters
{
  size_t                nbr_arrays;
  size_t                *neurons_per_array;
}                       t_neuron_parameters;

typedef struct          s_parameters
{
  t_neuron_parameters   neuron;
}                       t_parameters;

typedef struct          s_iam
{
  t_parameters          parameters;
  t_neuron_network      *default_network;
  t_player              players[2];
  char                  tab[9];
}                       t_iam;

#endif
