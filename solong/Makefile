# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 16:22:44 by mbernard          #+#    #+#              #
#    Updated: 2024/03/06 15:10:09 by tfreydie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = so_long
FLAGS = -lX11 -lXext -lz
CFLAGS = -MMD -MP -g3
MKDIR = mkdir -p
RMDIR = rm -rf

# ---------------------------------- Sources --------------------------------- #
vpath %c sources

SRCS =	so_long
	
# ---------------------------------- Repertories ----------------------------- #
HEADER_DIR = includes/
OBJS_DIR = .objs/
HEADER = $(addprefix ${HEADER_DIR}, so_long.h)
OBJS = $(addprefix ${OBJS_DIR}, $(addsuffix .o, ${SRCS}))
DEPS = ${OBJS:.o=.d}

# ---------------------------------- LibX Gestion ----------------------------- #
LIBX_DIR = minilibx-linux/
LINK_LIBX = -L ${LIBX_DIR} -lmlx_Linux
LINK_LIBFT = -L ${LIBFT_DIR} -lft
LIBFT_DIR = libft/
LIBX = $(addprefix ${LIBX_DIR}, libmlx_Linux.a)
LIBFT = $(addprefix ${LIBFT_DIR}, libft.a)
INCLUDES = -I ${LIBX_DIR} -I ${HEADER_DIR} -I ${LIBFT_DIR}
LIBS = ${LINK_LIBX} ${LINK_LIBFT}

# ---------------------------------- Compilation ----------------------------- #
all: ${NAME}

${NAME}: ${OBJS} ${LIBX} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${INCLUDES} ${LIBS} ${FLAGS} -o $@

${OBJS_DIR}%.o: %.c ${HEADER} | ${OBJS_DIR}
	${CC} ${CFLAGS} ${INCLUDES} -O3 -c $< -o $@

${LIBX}: FORCE
	make -C ${LIBX_DIR}

${LIBFT}: FORCE
	$(MAKE) -C ${LIBFT_DIR}

-include ${DEPS}
# ---------------------------------- Create Repertory ---------------------- #
${OBJS_DIR}:
			${MKDIR} ${OBJS_DIR}

## ---------------------------------- Clean ----------------------------------- #
clean:  ${OBJS_DIR}
	${RMDIR} ${OBJS_DIR}
	${MAKE} clean -C $(LIBX_DIR)
	${MAKE} clean -C $(LIBFT_DIR)

fclean: clean
	${RM} ${NAME}
	${RM} ${LIBX}
	${RM} ${LIBFT}

re:    fclean
	${MAKE} ${NAME}

FORCE:

# ---------------------------------- Phony ----------------------------------- #
.PHONY: all clean fclean re FORCE