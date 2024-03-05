OBJS_DIR	=	.objs
SRCS_DIR	=	sources
HEADER_DIR	=	includes
HEADER_FILE = 	pushswap.h 
NAME		=	push_swap

SRCS	=	$(SRCS_DIR)/push_swap.c \
			$(SRCS_DIR)/instructions.c \
			$(SRCS_DIR)/instructions_double.c \
			$(SRCS_DIR)/utils/freenerror_functions.c \
			$(SRCS_DIR)/utils/arg_parsing.c \
			$(SRCS_DIR)/utils/find_cheapest.c \
			$(SRCS_DIR)/utils/list_parsing.c \
			$(SRCS_DIR)/utils/exec_instructions.c \
			$(SRCS_DIR)/utils/safety.c \
			$(SRCS_DIR)/utils/inits.c \
			$(SRCS_DIR)/utils/find_all_target.c \
			$(SRCS_DIR)/utils/utils.c 
			
ifeq ($(BONUS),true)

NAME		=	checker
SRCS_DIR 	= 	sources_bonus
SRCS 		=	$(SRCS_DIR)/utils/arg_parsing_bonus.c \
				$(SRCS_DIR)/utils/free_bonus.c \
				$(SRCS_DIR)/checker.c \
				$(SRCS_DIR)/utils/instructions_bonus.c \
				$(SRCS_DIR)/utils/instructions_double_bonus.c \
				$(SRCS_DIR)/utils/safety_bonus.c \
				$(SRCS_DIR)/gnl/get_next_line.c \
				$(SRCS_DIR)/gnl/get_next_line_utils.c

HEADER_DIR 	= 	includes_bonus
HEADER_FILE = 	pushswap_bonus.h
OBJS_DIR	=	.objs_bonus
endif

OBJS	=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -g3
LDFLAGS =	-L./libft -lft
LIBFT	=	./libft/libft.a

YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m
UP		=	"\033[A"
CUT		=	"\033[K"


all: $(NAME)


$(LIBFT): FORCE
	@$(MAKE) --no-print-directory -C ./libft

FORCE:

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER_DIR)/$(HEADER_FILE)
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling [$<]$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR)
	@printf $(UP)$(CUT)

$(NAME): $(OBJS) $(LIBFT) Makefile
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
	@$(MAKE) BONUS=true 

# bclean:
# 	$(MAKE) BONUS=true $(clean)

	
.PHONY:	all clean fclean re bonus
