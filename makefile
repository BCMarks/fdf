NAME			= fdf
CC				= gcc
FLAGS			= -Wall -Werror -Wextra
SRC_DIR 		= ./srcs/
INCLUDES 		= ./includes

SRCS			= $(SRC_DIR)main.c
OBJS			= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(SRCS)		
		@$(CC) $(FLAGS) -I libft/includes -I minilibx -o $(OBJS) -c $(SRCS)
		@$(CC) -o fdf $(OBJS) -I libft/includes -L libft/ -lft -I minilibx -L minilibx/ -lmlx -framework OpenGL -framework AppKit -g

clean:
		@/bin/rm -f $(OBJS)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
