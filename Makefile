# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 19:29:43 by vfuhlenb          #+#    #+#              #
#    Updated: 2022/01/17 15:09:48 by vfuhlenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME_SERVER = server
NAME_CLIENT = client
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJ_SERVER = ${SRC_SERVER:.c=.o}
OBJ_CLIENT = ${SRC_CLIENT:.c=.o}

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	cd ft_printf && ${MAKE}
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) ./ft_printf/libftprintf.a

$(NAME_CLIENT): $(OBJ_CLIENT)
	cd ft_printf && ${MAKE}
	$(CC) -o $(NAME_CLIENT) $(CFLAGS) $(OBJ_CLIENT) ./ft_printf/libftprintf.a

clean:
	cd ft_printf && $(MAKE) clean
	-/bin/rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	@echo Clean done

fclean: clean
	cd ft_printf && $(MAKE) fclean
	-/bin/rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@echo Fclean done

re: fclean all

.PHONY: all clean fclean re
