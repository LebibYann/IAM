/**
** @file game_turn.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"game.h"

int		game_turn(t_iam		*iam,
			  t_player	player)
{
  if (player.type == AI)
    {
      if (ai_game_turn(iam->tab, player.symbol, iam->default_network) == -1)
	return (-1);
    }
  else
    player_game_turn(iam->tab, player.symbol);
  draw_table(iam->tab);
  return (check_table(iam->tab));
}
