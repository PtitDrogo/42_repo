OBJS_DIR	=	.objs

SRCS_DIR	=	sources
HEADER_DIR	=	includes

SRCS	=	$(SRCS_DIR)/ft_pipex.c \
			$(SRCS_DIR)/utils/ft_arg_parsing.c \
			$(SRCS_DIR)/utils/ft_env_parsing.c \
			$(SRCS_DIR)/utils/splitwesh.c \
			$(SRCS_DIR)/utils/free_functions.c

OBJS	=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

CC		=	cc
RM		=	rm -f
CFLAGS	=	-g3

NAME	=	pipex

YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m
UP		=	"\033[A"
CUT		=	"\033[K"

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER_DIR)/pipex.h
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling [$<]$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR)
	@printf $(UP)$(CUT)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -I $(HEADER_DIR)
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
