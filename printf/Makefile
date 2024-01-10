OBJS_DIR	=	.objs

SRCS_DIR	=	sources
HEADER_DIR	=	includes

SRCS	=	$(SRCS_DIR)/ft_printf.c \
			$(SRCS_DIR)/utils/ft_putnbr.c \
			$(SRCS_DIR)/utils/ft_putncount_char.c \
			$(SRCS_DIR)/utils/ft_putncount_str.c \
			$(SRCS_DIR)/utils/ft_putunsign.c \
			$(SRCS_DIR)/utils/ft_print_ptr.c

OBJS	=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -I $(HEADER_DIR)

NAME	=	libftprintf.a

YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m
UP		=	"\033[A"
CUT		=	"\033[K"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER_DIR)/ft_printf.h
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling [$<]$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf $(UP)$(CUT)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
