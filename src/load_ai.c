/**
** @file exit_iam.c
** @author Yann Lebib [lebib.yann@gmail.com]
** @brief
**/

#include		"iam.h"

int			load_ai(t_iam	*iam)
{
  char			*file;
  t_bunny_configuration	*cnf;
  t_neuron_network	*nnetwork;

  std_puts("Enter the name of the file.\n");
  file = read_entry();
  if (file == NULL)
    return (-1);
  if ((cnf = bunny_open_configuration(file, NULL)) == NULL)
    return (-1);
  nnetwork = load_neuron_network(cnf);
  if (nnetwork == NULL)
    return (-1);
  delete_neuron_network(iam->default_network);
  iam->default_network = nnetwork;
  std_puts("File loaded\n");
  return (0);
}
