# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhakgul <muhakgul@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/29 02:19:24 by muhakgul          #+#    #+#              #
#    Updated: 2026/04/05 14:06:36 by muhakgul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

SRCS    = swap.c \
          utils.c \
          stack_utils.c \
          parse_args.c \
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
