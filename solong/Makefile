#---------------------------------Variables---------------------------------#

OBJS_DIR	=	.objs
SRCS_DIR	=	sources
HEADER_DIR	=	includes
HEADER_FILE = 	so_long.h
LIBFT		=	./libft/libft.a
MINIBILX	=	./minilibx-linux/libmlx_Linux.a
NAME		=	so_long
OBJS	=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
#------------------------------------------------------------------------#

#---------------------------------Sources---------------------------------#
SRCS =		$(SRCS_DIR)/so_long.c \
			$(SRCS_DIR)/floodfill.c \
			$(SRCS_DIR)/map_check.c \
			$(SRCS_DIR)/utils.c \
			$(SRCS_DIR)/get_map.c	\
			$(SRCS_DIR)/key_pressed.c	\
			$(SRCS_DIR)/generate_map.c \
			$(SRCS_DIR)/init.c \
			$(SRCS_DIR)/exit_game.c 
#------------------------------------------------------------------------#

#---------------------------------Compilation & Linking---------------------------------#
CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -g3
LINKLIBS = -L minilibx-linux/ -lmlx_Linux -L libft/ -lft
INCLUDES = -I $(HEADER_DIR) -I minilibx-linux -I libft

#------------------------------------------------------------------------#


#---------------------------------Pretty---------------------------------#
YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m
UP		=	"\033[A"
CUT		=	"\033[K"
#------------------------------------------------------------------------#


all: $(NAME)

$(LIBFT): FORCE
	@$(MAKE) --no-print-directory -C ./libft

$(MINIBILX) : FORCE
	@$(MAKE) --no-print-directory -C ./minilibx-linux

FORCE:

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER_DIR)/$(HEADER_FILE)
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling [$<]$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 
	@printf $(UP)$(CUT)

$(NAME): $(OBJS) $(MINIBILX) $(LIBFT) Makefile
	@echo "$(YELLOW)Compiling [$<]$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LINKLIBS) -lXext -lX11 -lz -o $@ 
	@printf $(UP)$(CUT)
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

clean:
	@echo "$(YELLOW)cleaning files$(RESET)"
	@$(RM) $(OBJS) rm -rf $(OBJS_DIR)
	@printf $(UP)$(CUT)
	@echo "$(GREEN)$(NAME) files deleted !$(RESET)"
	@$(MAKE) --no-print-directory -C ./libft clean
	@$(MAKE) --no-print-directory -C ./minilibx-linux clean

fclean:	clean
	@echo "$(YELLOW)cleaning files$(RESET)"
	@$(RM) $(NAME)
	@printf $(UP)$(CUT)
	@echo "$(GREEN)$(NAME) executable deleted !$(RESET)"
	@$(RM) $(LIBFT)
	@echo "$(GREEN)libft.a executable deleted !$(RESET)"
	@$(RM) $(MINIBILX)
	@echo "$(GREEN)libmlx_Linux.a executable deleted !$(RESET)"

re:	fclean $(NAME)

.PHONY:	all clean fclean re bonus FORCE
