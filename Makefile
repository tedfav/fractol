NAME = fractol
FLAGS = 
DIRLIB = ./libft
LIB = ./libft/libft.a
MLX = ./minilibx
SRCS = main.c \
	   key_fonctions.c \
	   mouse_fonctions.c \
	   models.c \
	   draw.c \

OBJS = $(SRCS:.c=.o)
INC = includes

vpath %.c srcs/

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(DIRLIB)
	@make -C $(MLX)
	@gcc -o $(NAME) $(OBJS) -L$(MLX) -l mlx -lXext -lX11 -lm $(LIB) -I $(INC)

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $< -I $(INC)

clean:
	@$(MAKE) -C $(DIRLIB) fclean
	@$(MAKE) -C $(MLX) clean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: 
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
