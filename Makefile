# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muaktas <muaktas@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/29 02:19:24 by muhakgul          #+#    #+#              #
#    Updated: 2026/04/06 16:33:32 by muaktas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

SRCS    = utils.c \
		  parse_args.c \
		  push.c \
		  rank_normalize.c \
		  reverse_rotate.c \
		  rotate.c \
		  sort_complex.c \
		  sort_simple.c \
          stack_utils.c \
		  sort_utils.c \
		  swap.c \
          main.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

# Önce libft'i derle, sonra push_swap'ı linkle demek
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# libft klasörüne gir, oradaki Makefile'ı çalıştır demek
$(LIBFT):
	make -C $(LIBFT_DIR)


%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
