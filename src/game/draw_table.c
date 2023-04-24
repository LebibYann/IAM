/**
** @file draw_table.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"game.h"

void		draw_table(char		*tab)
{
  size_t        x;
  size_t        y;
  
  write(1, "+---+\n", 6 * sizeof(char));
  y = 0;
  while (y != 3)
    {
      write(1, "|", sizeof(char));
      x = 0;
      while (x != 3)
        {
          write(1, &tab[(y * 3) + x], sizeof(char));
          x++;
        }
      write(1, "|\n", 2 * sizeof(char));
      y++;
    }
  write(1, "+---+\n", 6 * sizeof(char));
}
