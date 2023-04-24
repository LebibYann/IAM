/**
** @file check_table.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"game.h"

static int      horizontal_check(char               *tab)
{
  size_t        x;
  size_t        y;
  char          c;

  y = 0;
  while (y != 3)
    {
      x = 0;
      c = tab[(y * 3) + x];
      while (x != 3 && c != ' ')
        {
          c = (c != tab[(y * 3) + x]) ? ' ' : c;
          x++;
        }
      if (c != ' ')
        return (1);
      y++;
    }
  return (0);
}

static int      vertical_check(char                *tab)
{
  size_t        x;
  size_t        y;
  char          c;

  x = 0;
  while (x != 3)
    {
      y = 0;
      c = tab[(y * 3) + x];
      while (y != 3 && c != ' ')
        {
          c = (c != tab[(y * 3) + x]) ? ' ' : c;
          y++;
        }
      if (c != ' ')
        return (1);
      x++;
    }
  return (0);
}

static int      diagonal_check(char                *tab)
{
  size_t        x;
  size_t        y;
  char          c;

  x = 0;
  y = 0;
  c = tab[(y * 3) + x];
  while (x != 3 && c != ' ')
    {
      c = (c != tab[(y * 3) + x]) ? ' ' : c;
      x++;
      y++;
    }
  if (c != ' ')
    return (1);
  x = 0;
  y = 2;
  c = tab[(y * 3) + x];
  while (x != 3 && c != ' ')
    {
      c = (c != tab[(y * 3) + x]) ? ' ' : c;
      x++;
      y--;
    }
  return (c != ' ');
}

int             check_table(char                      *tab)
{
  size_t        i;
  char          c;

  i = 0;
  c = tab[i];
  while (i != 9)
    {
      c = (tab[i] == ' ') ? ' ' : c;
      i = i + 1;
    }
  if (c != ' ')
    return (-1);
  if (horizontal_check(tab) == 1)
    return (1);
  if (vertical_check(tab) == 1)
    return (1);
  if (diagonal_check(tab) == 1)
    return (1);
  return (0);
}

