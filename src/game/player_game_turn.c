/**
** @file player_game_turn.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"game.h"

int             player_game_turn(char               *tab,
				 char               symbol)
{
  int           position;
  int           value;
  bool		place;

  place = false;
  while (place == false)
    {
      std_puts("Please, choose the position X\n");
      value = read_number();
      position = (value >= 3) ? 2 : value;
      std_puts("Please, choose the position Y\n");
      value = read_number();
      position += 3 * ((value >= 3) ? 2 : value);
      place = add_symbol_in_tab(position, tab, symbol, false);
    }
  return (0);
}

