SRCS	=	get_next_line.c
OBJS	=	$(SRCS:.c=.o)
BONUS            =	
BONUS_OBJS        = $(BONUS:.c=.o)
CC	=	cc
RM	=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -I.

NAME	=	get_next_line.a

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

bonus : $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:	all clean fclean re bonus
