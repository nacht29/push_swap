NAME = push_swap

SRCS = $(wildcard push_swap_main/*.c init_parse/*.c turk_algo/*.c operations/*.c)
OBJS = ${SRCS:.c=.o}

HEADER = -Iincludes

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	@# $(CC) $(CFLAGS) $(HEADER) -c $< -o $@
	$(CC) $(HEADER) -c $< -o $@

GREEN = \033[1;32m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
AQUA = \033[1;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo ""
	@echo "$(AQUA)push_swap executable programme compiled$(RESET)"

$(LIBFT): FORCE
	@echo ""
	@echo "$(YELLOW)compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR) -s

clean:
	@make clean -C $(LIBFT_DIR) -s
	@rm -f $(OBJS)
	@echo "$(PURPLE)clean successful$(RESET)"

fclean: clean
	@clear
	@make fclean -C $(LIBFT_DIR) -s
	@rm -f $(NAME)
	@echo "$(PURPLE)fclean successful$(RESET)"

clear:
	@clear

re: clear fclean all

val: re
	@#valgrind --leak-check=yes ./push_swap 10 9 8 7 6 5 4 3 2 1
	@valgrind ./push_swap 10 9 8 7 6 5 4 3 2 1

test: re
	 ./push_swap 10 9 8 7 6 5 4 3 2 1 > out.txt
	# ./push_swap 10 9 8 7 6 5 4 3 2 1

FORCE:

.PHONY: all bonus clean fclean re val