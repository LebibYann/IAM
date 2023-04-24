/**
** @file read_number.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"libstd.h"

int		read_number(void)
{
  char          *entry;
  
  entry = NULL;
  std_puts("Enter the desired value\n");
  while (entry == NULL || (entry[0] < '0' || entry[0] > '9'))
    {
      entry = read_entry();
      if (entry == NULL || (entry[0] < '0' || entry[0] > '9'))
        std_puts("Error, please enter a value\n");
    }
  return (std_atoi(entry));
}
