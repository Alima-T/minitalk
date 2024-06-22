# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 17:14:45 by aokhapki          #+#    #+#              #
#    Updated: 2024/06/22 19:37:25 by aokhapki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

NAME_SERVER = server
NAME_CLIENT = client

SRCLIENT =   client.c
SRCSERVER = server.c

OBJSCLIENT = $(SRCLIENT:.c=.o)
OBJSERVER = $(SRCSERVER:.c=.o)

CC			=	cc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf

LIB = ./ft_printf/libftprintf.a 

all: $(NAME)

$(NAME): $(OBJSERVER) $(OBJSCLIENT)
	@make -C ./ft_printf
	@gcc -o server $(SRCSERVER) $(CFLAGS) $(LIB)
	@gcc -o client $(SRCLIENT) $(CFLAGS) $(LIB)

clean:
	rm -f $(OBJSERVER) $(OBJSCLIENT)
	rm -f ./ft_printf/*.o

fclean: clean
	rm -f server client
	rm -f ./ft_printf/*.o ./ft_printf/*.a

re: fclean all

.PHONY: all clean fclean re