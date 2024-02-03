OBJS_DIR	=	.objs
SRCS_DIR	=	sources
HEADER_DIR	=	includes
HEADER_FILE = 	pipex.h \

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
			$(SRCS_DIR)/libft/ft_strnstr.c \
			$(SRCS_DIR)/libft/ft_strncmp.c

ifeq ($(BONUS),true)
SRCS_DIR = sources_bonus
SRCS =			$(SRCS_DIR)/ft_pipex_bonus.c \
				$(SRCS_DIR)/utils/arg_parsing_bonus.c \
				$(SRCS_DIR)/utils/env_parsing_bonus.c \
				$(SRCS_DIR)/utils/free_functions_bonus.c \
				$(SRCS_DIR)/utils/inits_bonus.c \
				$(SRCS_DIR)/utils/secure_error_functions_bonus.c \
				$(SRCS_DIR)/utils/here_doc_bonus.c \
				$(SRCS_DIR)/gnl/get_next_line_utils_bonus.c \
				$(SRCS_DIR)/gnl/get_next_line_bonus.c \
				$(SRCS_DIR)/libft/ft_strjoin_bonus.c \
				$(SRCS_DIR)/libft/ft_strlen_bonus.c \
				$(SRCS_DIR)/libft/ft_split_bonus.c \
				$(SRCS_DIR)/libft/ft_strnstr_bonus.c \
				$(SRCS_DIR)/libft/ft_strncmp_bonus.c
HEADER_DIR = includes_bonus
HEADER_FILE = 	pipex_bonus.h
endif

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

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER_DIR)/$(HEADER_FILE)
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
	@$(RM) $(OBJS) rm -rf $(OBJS_DIR)
	@printf $(UP)$(CUT)
	@echo "$(GREEN)$(NAME) files deleted !$(RESET)"

fclean:	clean
	@echo "$(YELLOW)cleaning files$(RESET)"
	@$(RM) $(NAME)
	@printf $(UP)$(CUT)
	@echo "$(GREEN)$(NAME) executable deleted !$(RESET)"

re:	fclean $(NAME)

bonus: 
	@$(MAKE) $(NAME) BONUS=true
	
.PHONY:	all clean fclean re bonus
