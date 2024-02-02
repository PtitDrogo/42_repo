OBJS_DIR	=	.objs
SRCS_DIR	=	sources
HEADER_DIR	=	includes

SRCS	=	$(SRCS_DIR)/ft_pipex.c \
			$(SRCS_DIR)/utils/arg_parsing.c \
			$(SRCS_DIR)/utils/env_parsing.c \
			$(SRCS_DIR)/utils/free_functions.c \
			$(SRCS_DIR)/utils/inits.c \
			$(SRCS_DIR)/utils/secure_error_functions.c \
			$(SRCS_DIR)/utils/here_doc.c \
			$(SRCS_DIR)/gnl/get_next_line_utils.c \
			$(SRCS_DIR)/gnl/get_next_line.c \
			$(SRCS_DIR)/libft/ft_strjoin.c \
			$(SRCS_DIR)/libft/ft_strlen.c \
			$(SRCS_DIR)/libft/ft_split.c \
			$(SRCS_DIR)/libft/ft_strnstr.c			

OBJS	=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -g3

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
	@echo "$(YELLOW)Compiling [$<]$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $@ -I $(HEADER_DIR)
	@printf $(UP)$(CUT)
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

clean:
	@echo "$(YELLOW)cleaning files$(RESET)"
	@$(RM) $(OBJS)
	@printf $(UP)$(CUT)
	@echo "$(GREEN)$(NAME) files deleted !$(RESET)"

fclean:	clean
	@echo "$(YELLOW)cleaning files$(RESET)"
	@$(RM) $(NAME)
	@printf $(UP)$(CUT)
	@echo "$(GREEN)$(NAME) executable deleted !$(RESET)"

re:	fclean $(NAME)

.PHONY:	all clean fclean re
