# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmarks <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/15 12:21:26 by bmarks            #+#    #+#              #
#    Updated: 2019/06/20 15:50:57 by bmarks           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_isblank.c \
	  ft_isxdigit.c \
	  ft_islower.c \
	  ft_isupper.c \
	  ft_isspace.c \
	  ft_iscntrl.c \
	  ft_ispunct.c \
	  ft_isgraph.c \
	  ft_strcspn.c \
	  ft_strspn.c \
	  ft_strpbrk.c \
	  ft_strtok.c \
	  ft_strtok_r.c \
	  ft_rotx.c \
	  ft_lstadd_end.c \
	  ft_strndup.c \
	  get_next_line.c
	 
	 OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):
	@gcc $(FLAGS) -c -I. $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@/bin/rm -f $(OBJ)

fclean:	clean
	@/bin/rm -f $(NAME)

re:	fclean all

test: re
	@gcc $(FLAGS) testrun.c -L. -lft -o testrun
	@./testrun

norm:
	@norminette -R CheckForbiddenSourceHeader
