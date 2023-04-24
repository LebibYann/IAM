/**
** @file realloc.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include        "libstd.h"

void		*std_realloc(void       *ptr,
			     size_t     size)
{
  char          *nptr;
  size_t        i;

  i = 0;
  nptr = malloc(size * sizeof(char));
  while (i != size)
    {
      nptr[i] = '\0';
      i = i + 1;
    }
  i = 0;
  while (i != size && i != malloc_usable_size(ptr))
    {
      nptr[i] = ((char *)ptr)[i];
      i = i + 1;
    }
  if (ptr != NULL)
    free(ptr);
  return (nptr);
}
