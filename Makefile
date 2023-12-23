NAME = minishell
CC = cc
LIBFT = libft/libft.a \

SRC = minishell.c \

OBJ = $(SRC:.c=.o)

CFLAGS = 

all: init $(NAME)

init: 
	@cd libft && $(MAKE)

$(NAME): $(OBJ)
	$(CC) -g $(OBJ) $(LIBFT) -o $(NAME) -lreadline

%.o: %.c
	$(CC) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re

norme: $(SRCS) $(SRCS_B) $(BONUS) $(Lib_H)
	$(NM) $@ $^

git: 
	git add .
	git commit -m "makefile"
	git push
	clear
