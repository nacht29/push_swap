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
	./push_swap 19 52 69 85 60 81 9 7 31 51 67 96 75 92 5 68 26 6 97 98 16 70 45 28 38 87 80 15 40 64 59 4 17 63 100 99 76 22 83 11 89 84 35 55 1 56 34 46 30 78 3 2 48 33 12 53 54 37 62 79 29 91 14 66 41 93 90 24 49 82 18 23 95 57 20 74 94 32 13 25 71 47 61 77 86 73 8 10 72 65 21 44 36 50 43 39 88 27 42 58 > out.txt

FORCE:

.PHONY: all bonus clean fclean re val