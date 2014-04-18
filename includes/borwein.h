/*
** borwein.h for borwein in /home/mathon_j/rendu/110borwein/includes
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Fri Apr 18 17:18:20 2014 Jérémy MATHON
** Last update Fri Apr 18 19:03:23 2014 Jérémy MATHON
*/

#ifndef BORWEIN_H_
# define BORWEIN_H_

# include	<math.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>

# define	M_PI		3.141592653589793238462
# define	BORNESUP	5000
# define	SUBDIV		10000

void		check_arg(char *,int);
double		check_n(double);
int		main(int, char **);
void		prompt(double, double, double, int);
void		borwein(double, double, double);
void		method_rect(double, double, double);
double		calc_integrate(double, double);
void		method_trapeze(double, double, double);
void		method_simpson(double, double, double);

#endif /* !BORWEIN_H_ */
