/**
** @file main.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include	"iam.h"

int		main(void)
{
  t_iam		iam;
  char		*entry;

  init_program(&iam);
  while ((entry = read_entry()) != NULL)
    {
      if (entry[0] == 't')
	game_train(&iam);
      else if (entry[0] == 'p')
	play_game(&iam);
      else if (entry[0] == 'l')
	load_ai(&iam);
      else if (entry[0] == 's')
	{
	  std_puts("Choose your save name.\n");
	  save_neuron_network(iam.default_network, read_entry());
	  std_puts("Neuron network saved.\n");
	}
      else if (entry[0] == 'q')
	{
	  return (exit_iam(iam));
	  free(entry);
	}
      free(entry);
    }
  return (exit_iam(iam));
}

