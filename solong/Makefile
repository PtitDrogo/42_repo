OBJS_DIR	=	.objs
SRCS_DIR	=	sources
HEADER_DIR	=	includes
HEADER_FILE = 	so_long.h 

SRCS	=	$(SRCS_DIR)/so_long.c \

OBJS	=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -g3
LDFLAGS =	-L./libft -lft
LIBXFLAGS = -I minilibx-linux -O3
LIBXFLAGSASSEMBLY = -L mlx_linux -lmlx_Linux -lXext -lX11 

NAME	=	so_long

YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m
UP		=	"\033[A"
CUT		=	"\033[K"
LIBFT	=	./libft/libft.a


all: $(NAME)

$(LIBFT): FORCE
	@$(MAKE) --no-print-directory -C ./libft

FORCE:

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER_DIR)/$(HEADER_FILE)
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling [$<]$(RESET)"
	@$(CC) $(CFLAGS) $(LIBXFLAGS) $(LIBXFLAGSASSEMBLY) -c $< -o $@ -I $(HEADER_DIR) 
	@printf $(UP)$(CUT)

$(NAME): $(OBJS) $(LIBFT) Makefile
	@echo "$(YELLOW)Compiling [$<]$(RESET)"
	@$(CC) $(CFLAGS) $(LIBXFLAGS) $(OBJS) -o $@ -I $(HEADER_DIR) $(LDFLAGS)
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

.PHONY:	all clean fclean re bonus FORCE
