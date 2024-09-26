NAME = push_swap
B_NAME = checker

SRCS = $(wildcard main_file/push_swap.c push_swap_dir/*.c init_parse/*.c turk_algo/*.c operations/*.c)
OBJS_DIR = obj/
OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(notdir $(SRCS)))

B_SRCS = $(wildcard main_file/checker.c checker_dir/*.c push_swap_dir/*.c init_parse/*.c turk_algo/*.c operations/*.c)
B_OBJS_DIR = b_obj/
B_OBJS = $(patsubst %.c,$(B_OBJS_DIR)%.o,$(notdir $(B_SRCS)))

HEADER = -Iincludes

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = cc
# CFLAGS = -Wall -Wextra -Werror

vpath %.c push_swap_dir:init_parse:turk_algo:operations:checker_dir:main_file

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(B_OBJS_DIR)%.o: %.c
	@mkdir -p $(B_OBJS_DIR)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

GREEN = \033[1;32m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
AQUA = \033[1;36m
RESET = \033[0m

all: $(NAME)

bonus: $(B_NAME)

$(B_NAME): $(B_OBJS) $(LIBFT)
	@$(CC) $(B_OBJS) -L$(LIBFT_DIR) -lft -o $(B_NAME)
	@echo ""
	@echo "$(AQUA)checker compiled$(RESET)"

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
	@rm -rf $(OBJS_DIR) $(B_OBJS_DIR)
	@echo "$(PURPLE)clean successful$(RESET)"

fclean: clean
	@clear
	@make fclean -C $(LIBFT_DIR) -s
	@rm -f $(NAME) $(B_NAME)
	@echo "$(PURPLE)fclean successful$(RESET)"

clear:
	@clear

re: clear fclean all

bre: re bonus

val: re
	@valgrind ./push_swap 99 0 25 -38 10 7 42 > out.txt

FORCE:

.PHONY: all bonus clean fclean re val test