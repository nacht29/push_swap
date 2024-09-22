NAME = push_swap

SRCS = $(wildcard push_swap_main/*.c init_parse/*.c turk_algo/*.c operations/*.c)
OBJS_DIR = obj/
OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(notdir $(SRCS)))

HEADER = -Iincludes

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = cc
# CFLAGS = -Wall -Wextra -Werror

vpath %.c push_swap_main:init_parse:turk_algo:operations

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

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
	@rm -rf $(OBJS_DIR)
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
	@valgrind ./push_swap 99 0 25 -38 10 7 42 > out.txt

test: re
	./push_swap 15 20 5 9 11 16 17 14 4 13 6 12 19 7 8 3 10 18 1 2 > out.txt

oneline:
	cat out.txt | tr '\n' ' ' > out2.txt

FORCE:

.PHONY: all bonus clean fclean re val