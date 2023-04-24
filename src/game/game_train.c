/**
** @file game_train.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include		"game.h"

int			game_train(t_iam		*iam)
{
  int			champion_victory;
  t_neuron_network	*network[2];
  int			victory;
  int			nvictory;

  champion_victory = 0;
  victory = 0;
  new_neuron_parameters(&iam->parameters.neuron);
  std_puts("How many wins must your fighter have? ?\n");
  nvictory = read_number();
  std_puts("Train start welcome to the coliseum\n");
  while (champion_victory < nvictory)
    {
      network[0] = iam->default_network;
      network[1] = neuron_network(iam->parameters.neuron.neurons_per_array,
				  iam->parameters.neuron.nbr_arrays);
      victory = coliseum(network[0], network[1]);
      if (victory == 1)
	champion_victory--;
      else
	champion_victory++;
      victory = coliseum(network[1], network[0]);
      if (victory == 0)
	champion_victory--;
      else
	champion_victory++;
      if (champion_victory == -nvictory)
	{
	  delete_neuron_network(network[0]);
	  iam->default_network = network[1];
	  champion_victory = 0;
	}
      print_base10(champion_victory);
      write(1, "\n", 1);
      delete_neuron_network(network[1]);
    }
  std_puts("Training completed we have found a champion !\n");
  return (1);
}
