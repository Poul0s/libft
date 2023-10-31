# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psalame <psalame@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 11:02:12 by psalame           #+#    #+#              #
#    Updated: 2023/10/31 12:13:30 by psalame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SRCS=ft_isstr.c ft_strlen.c ft_memutil.c ft_bzero.c ft_strlutil.c ft_strutil.c ft_strcase.c ft_atoi.c ft_calloc.c ft_putstr.c ft_split.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_strutil.c ft_substr.c
OBJS=$(SRCS:.c=.o)
BSRCS=ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c  ft_lstadd_bonus.c ft_lstfree_bonus.c ft_lstiter_bonus.c
BOBJS=$(BSRCS:.c=.o)

$(NAME): all

all: $(OBJS) 
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: $(OBJS) $(BOBJS)
	ar -rcs $(NAME) $(OBJS) $(BOBJS)

.PHONY: bonus all clean fclean re