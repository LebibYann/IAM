/**                                                                                    
** @file libstd.h                                                                
** @author Yann Lebib [lebib.yann@gmail.com]                                           
** @brief                                                                              
**/

#ifndef         __LIBSTD_H__
#define         __LIBSTD_H__

#include	<unistd.h>
#include	<stdlib.h>
#include	<malloc.h>

void            *std_realloc(void       *ptr,
                             size_t     size);

int		std_puts(const char		*str);

int             std_atoi(const char     *nptr);

void            print_base10(int        nbr);

size_t          std_strlen(const char   *str);

char            *read_entry(void);

int             read_number(void);

#endif


