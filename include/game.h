/**
** @file game.h
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#ifndef                 __GAME_H__
#define                 __GAME_H__

#include                "global.h"
#include		"init_program.h"

bool			add_symbol_in_tab(int				position,
					  char				*tab,
					  char				symbol,
					  bool				ai);

void			set_tab_inputs(double				*inputs,
				       char				*tab,
				       char				symbol);

int			check_table(char				*tab);

void			draw_table(char					*tab);

int                     game_train(t_iam				*iam);

int			game_turn(t_iam					*iam,
				  t_player				player);

int			ai_game_turn(char				*tab,
				     char				symbol,
				     t_neuron_network			*network);

int			player_game_turn(char				*tab,
					 char				symbol);

bool			play_game(t_iam					*iam);

int			convert_network_solution(t_neuron_network       *network);

int			coliseum(t_neuron_network			*fighter1,
				 t_neuron_network			*fighter2);

void			init_tab(char					*tab);

#endif
