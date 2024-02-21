OBJS_DIR	=	.objs
SRCS_DIR	=	sources
HEADER_DIR	=	includes
HEADER_FILE = 	pushswap.h 

SRCS	=	$(SRCS_DIR)/push_swap.c \
			$(SRCS_DIR)/instructions.c \
			$(SRCS_DIR)/utils/freenerror_functions.c \
			$(SRCS_DIR)/utils/arg_parsing.c \
			$(SRCS_DIR)/utils/algorithm.c \
			$(SRCS_DIR)/utils/list_parsing.c \
			$(SRCS_DIR)/utils/exec_instructions.c
			
ifeq ($(BONUS),true)
SRCS_DIR = sources_bonus
SRCS =			$(SRCS_DIR)/ft_pipex_bonus.c
HEADER_DIR = 	includes_bonus
HEADER_FILE = 	pushswap_bonus.h
endif

OBJS	=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

CC		=	cc
RM		=	rm -f
CFLAGS	=	-g3
LDFLAGS =	-L./libft -lft
LIBFT	=	compile_libft


NAME	=	pushswap

YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m
UP		=	"\033[A"
CUT		=	"\033[K"


all: $(NAME)

$(LIBFT):
	@$(MAKE) --no-print-directory -C ./libft

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER_DIR)/$(HEADER_FILE)
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling [$<]$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR)
	@printf $(UP)$(CUT)

$(NAME): $(OBJS) | $(LIBFT)
	@echo "$(YELLOW)Compiling [$<]$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $@ -I $(HEADER_DIR) $(LDFLAGS)
	@printf $(UP)$(CUT)
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

clean:
	@echo "$(YELLOW)cleaning files$(RESET)"
	@$(RM) $(OBJS) rm -rf $(OBJS_DIR)
	@printf $(UP)$(CUT)
	@echo "$(GREEN)$(NAME) files deleted !$(RESET)"
	@$(MAKE) --no-print-directory -C ./libft clean

fclean:	clean
	@echo "$(YELLOW)cleaning files$(RESET)"
	@$(RM) $(NAME)
	@printf $(UP)$(CUT)
	@echo "$(GREEN)$(NAME) executable deleted !$(RESET)"
	@$(RM) ./libft/libft.a
	@echo "$(GREEN)libft.a executable deleted !$(RESET)"

re:	fclean $(NAME)

bonus: 
	@$(MAKE) $(NAME) BONUS=true
	
.PHONY:	all clean fclean re bonus
