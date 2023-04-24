/**
** @file play_game.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"game.h"

bool		play_game(t_iam		*iam)
{
  int		victory;

  victory = 0;
  init_tab(iam->tab);
  draw_table(iam->tab);
  std_puts("Let's match !\n");
  while (victory == 0)
    {
      if ((victory = game_turn(iam, iam->players[0])) == 1)
	{
	  std_puts("Player 1 won !\n");
	  return (true);
	}
      else if (victory == -1)
	{
	  std_puts("The A.I. playing player 1 could not respect the rules of the game\n");
	  return (false);
	}
      if ((victory = game_turn(iam, iam->players[1])) == 1)
	{
	  std_puts("Player 2 won !\n");
	  return (true);
	}
      else if (victory == -1)
	std_puts("The A.I. playing player 2 could not respect the rules of the game\n");
    }
  if (victory == -1)
    return (false);
  return (true);
}
