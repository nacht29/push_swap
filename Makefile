NAME = push_swap

SRCS = $(wildcard main/*.c turk/*.c operations/*.c utils/*.c)
OBJS = ${SRCS:.c=.o}

HEADER = -Iincludes

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
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
	@rm -f $(OBJS)
	@echo "$(PURPLE)clean successful$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT_DIR) -s
	@rm -f $(NAME)
	@echo "$(PURPLE)fclean successful$(RESET)"

re: fclean all

FORCE:

.PHONY: all bonus clean fclean re