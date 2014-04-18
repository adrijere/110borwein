##
## Makefile for 110borwein in /home/mathon_j/rendu/110borwein
## 
## Made by Jérémy MATHON
## Login   <mathon_j@epitech.net>
## 
## Started on  Fri Apr 18 17:17:13 2014 Jérémy MATHON
## Last update Fri Apr 18 18:08:16 2014 Jérémy MATHON
##

NAME	=	110borwein

SRC	=	sources/main.c		\
		sources/borwein.c

OBJ	=	$(SRC:.c=.o)

CC	=	cc

RM	=	rm -vf

TMP	=	$(SRC:.c=.c~)

CFLAGS	+=	-Wextra -Wall

CFLAGS	+=	-ansi -pedantic

CFLAGS	+=	-I . -I includes/

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lm

clean:
		$(RM) $(OBJ) $(TMP)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
