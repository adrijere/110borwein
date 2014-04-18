/*
** borwein.c for borwein in /home/mathon_j/rendu/110borwein/sources
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Fri Apr 18 17:39:02 2014 Jérémy MATHON
** Last update Fri Apr 18 19:13:27 2014 Jérémy MATHON
*/

#include	<math.h>
#include	"borwein.h"

void	prompt(double nb1, double nb2, double n, int option)
{
  if (option == 1)
    printf("Méthode des rectangles\n");
  else if (option == 2)
    printf("Méthode des trapèzes\n");
  else if (option == 3)
    printf("Méthode de Simpson\n");
  else
    return ;
  printf("\tI%.0f = %.10f\n\tdiff = %.10f\n", n, nb1, nb2);
}

double		calc_integrate(double n, double x)
{
  double	res;
  int		k;

  res = 1;
  k = 0;
  while (k <= n)
    {
      if (x != 0)
	res = res * (sin(x / ((2 * k) + 1)) / (x / ((2 * k) + 1)));
      k = k + 1;
    }
  return (res);
}

void		method_rect(double n, double bornesup, double subdiv)
{
  double	a;
  double	b;
  double	i;
  double	h;
  double	result;

  a = 0;
  b = bornesup;
  i = a;
  h = (b - a) / subdiv;
  result = 0;
  while (i < b)
    {
      result = result + calc_integrate(n, (a + i * h));
      i++;
    }
  result = result * h;
  prompt(result, result - (M_PI / 2), n, 1);
}

void		method_trapeze(double n, double bornesup, double subdiv)
{
  double	a;
  double	b;
  double	i;
  double	h;
  double	result;

  a = 0;
  b = bornesup;
  i = 1;
  h = (b - a) / subdiv;
  result = 0;
  while (i < b)
    {
      result = result + calc_integrate(n, (a + i * h));
      i++;
    }
  result = ((result * 2) + calc_integrate(n, a) + calc_integrate(n, b)) * ((b - a) / (2 * subdiv));
  prompt(result, result - (M_PI / 2), n, 2);
}

void		method_simpson(double n, double bornesup, double subdiv)
{
  double	a;
  double	b;
  double	i;
  double	h;
  double	result;
  double	res;
  double	final;

  a = 0;
  b = bornesup;
  i = a;
  h = (b - a) / subdiv;
  result = 0;
  res = 0;
  while (i < b)
    {
      result = result + calc_integrate(n, (a + i * h) + (h / 2));
      i++;
    }
  i = 1;
  while (i < b)
    {
      res = res + calc_integrate(n, (a + i * h));
      i++;
    }
  final = ((result * 4) + (res * 2) + calc_integrate(n, a) + calc_integrate(n, b)) * ((b - a) / (6 * subdiv));
  prompt(final, final - (M_PI / 2), n, 3);
}

void		borwein(double n, double bornesup, double subdiv)
{
  method_rect(n, bornesup, subdiv);
  method_trapeze(n, bornesup, subdiv);
  method_simpson(n, bornesup, subdiv);
}
