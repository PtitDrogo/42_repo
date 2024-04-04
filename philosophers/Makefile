#---------------------------------Variables---------------------------------#

OBJS_DIR	=	.objs
SRCS_DIR	=	sources
HEADER_DIR	=	includes
HEADER_FILE = 	philo.h

NAME		=	philo
OBJS	=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
#------------------------------------------------------------------------#

#---------------------------------Sources---------------------------------#
SRCS =		$(SRCS_DIR)/philo.c \
			$(SRCS_DIR)/utils.c \
			$(SRCS_DIR)/actions.c \
			$(SRCS_DIR)/check_death.c \
			$(SRCS_DIR)/parsing.c \
			$(SRCS_DIR)/error_utils.c \
			$(SRCS_DIR)/init_dinner.c \
			$(SRCS_DIR)/cleanup.c \
			$(SRCS_DIR)/mutex_utils.c \
			$(SRCS_DIR)/lonely.c \
			$(SRCS_DIR)/init_philos.c 
#------------------------------------------------------------------------#

#---------------------------------Compilation & Linking---------------------------------#
CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -pthread 
INCLUDES = -I $(HEADER_DIR)
# -g3 -fsanitize=thread 
#------------------------------------------------------------------------#


#---------------------------------Pretty---------------------------------#
YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m
UP		=	"\033[A"
CUT		=	"\033[K"
#------------------------------------------------------------------------#


all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER_DIR)/$(HEADER_FILE)
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling [$<]$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 
	@printf $(UP)$(CUT)

$(NAME): $(OBJS) Makefile
	@echo "$(YELLOW)Compiling [$<]$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $@ 
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

.PHONY:	all clean fclean re bonus FORCE
