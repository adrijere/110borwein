/*
** main.c for main in /home/mathon_j/rendu/110borwein/sources
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Fri Apr 18 17:26:32 2014 Jérémy MATHON
** Last update Fri Apr 18 18:11:46 2014 Jérémy MATHON
*/

#include	"borwein.h"

void	check_arg(char *str, int nb)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    if (str[i] >= '0' && str[i] <= '9')
      i++;
    else
      {
	printf("L'argument %d n'est pas correct. Le calcul ne peut avoir lieu.\n", nb);
	exit (EXIT_FAILURE);
      }
}

double	check_n(double n)
{
  if (n >= 0)
    return (n);
  else
    {
      printf("n doit être supérieur ou égal à 0.\n");
      exit (EXIT_FAILURE);
    }
}

int	main(int ac, char **av)
{
  if (ac == 2)
    {
      check_arg(av[1], 1);
      borwein(check_n(atof(av[1])), BORNESUP, SUBDIV);
    }
  else if (ac == 3)
    {
      check_arg(av[1], 1);
      check_arg(av[2], 2);
      borwein(check_n(atof(av[1])), check_n(atof(av[2])), SUBDIV);
    }
  else if (ac == 4)
    {
      check_arg(av[1], 1);
      check_arg(av[2], 2);
      check_arg(av[3], 3);
      borwein(check_n(atof(av[1])), check_n(atof(av[2])), check_n(atof(av[3])));
    }
  else
    {
      printf("Usage\t./110borwein n [borne supérieure] [nombre de subdivisions]\nN doit être supérieur ou égal à 0.\n");
      exit (EXIT_FAILURE);
    }
  return (0);
}
