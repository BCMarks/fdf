NAME			= fdf
CC				= gcc
FLAGS			= -Wall -Werror -Wextra
SRC_DIR 		= ./srcs/
INCLUDES 		= -I./libft/includes -I./includes -I./minilibx_macos
LIBRARIES		= -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -g
SRCS			= $(SRC_DIR)main.c $(SRC_DIR)graphic_main.c
OBJS			= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(SRCS)		
		@$(CC) $(FLAGS) $(INCLUDES) $(SRCS) $(LIBRARIES) -o $(NAME)

clean:
		@/bin/rm -f $(OBJS)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
