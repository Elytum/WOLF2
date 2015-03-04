# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by pfournet          #+#    #+#              #
#    Updated: 2014/12/13 12:55:35 by pfournet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I ./libft/includes -I /usr/X11/include -g
X11 = -L/usr/X11/lib -lmlx -lXext -lX11
#--------------Name-------------------------#
NAME = wolf3d

#--------------Sources----------------------#
FILES =	main.c	\
		ft_event.c \
		ft_event2.c \
		utils.c \
		ft_ray.c \
		ft_ray2.c \
		mlx_tools.c \
		read.c

OBJECT = $(patsubst %.c,%.o,$(FILES))
BASEDIR = ./srcs
#-------------------------------------------#



#--------------Actions----------------------#

all:$(NAME)

$(NAME):
		make re -C ./libft
		$(CC) -c $(CFLAGS) $(addprefix $(BASEDIR)/, $(FILES))
		$(CC) -o $(NAME) $(OBJECT) -L./libft -lft $(X11)

clean :
		/bin/rm -Rf $(OBJECT)

fclean: clean
		/bin/rm -Rf $(NAME)

re: fclean all
