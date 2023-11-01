# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psalame <psalame@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 11:02:12 by psalame           #+#    #+#              #
#    Updated: 2023/11/01 15:59:05 by psalame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SRCS=ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memcpy.c ft_bzero.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_strnstr.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_atoi.c ft_itoa.c ft_calloc.c ft_putstr.c ft_putchar.c ft_putendl.c ft_putnbr.c ft_split.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c 
OBJS=$(SRCS:.c=.o)
HEAD=libft.h
BSRCS=ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c  ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BOBJS=$(BSRCS:.c=.o)
BHEAD=libft_bonus.h

all: $(NAME)

$(NAME): $(OBJS) 
	ar -rc $@ $^ $(HEAD)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: $(OBJS) $(BOBJS)
	ar -rc $(NAME) $^ $(BHEAD)

.PHONY: bonus all clean fclean re
