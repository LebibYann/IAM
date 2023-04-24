/**
** @file init_players.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"init_program.h"

bool		init_players(t_player	*players)
{
  int		entry;

  entry = -1;
  std_puts("Who will be player 1 ?\n");
  while (entry == -1)
    {
      std_puts("Enter 0 to be played by an AI and 1 to be played by a player.\n");
      entry = read_number();
      if (entry == 0)
	players[0].type = AI;
      else if (entry == 1)
	players[0].type = PLAYER;
      else
	entry = -1;
    }
  entry = -1;
  std_puts("Who will be player 2 ?\n");
  while (entry == -1)
    {
      std_puts("Enter 0 to be played by an AI and 1 to be played by a player.\n");
      entry = read_number();
      if (entry == 0)
        players[1].type = AI;
      else if (entry == 1)
        players[1].type = PLAYER;
      else 
        entry = -1;
    }
  players[0].symbol = P1_S;
  players[1].symbol = P2_S;
  return (true);
}
