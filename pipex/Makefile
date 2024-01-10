SRCS	=	ft_pipex.c 
OBJS	=	$(SRCS:.c=.o)
BONUS            =	pipex_bonus.c 
BONUS_OBJS        = $(BONUS:.c=.o)
CC	=	cc
RM	=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -I.

NAME	=	pipex.a

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) 

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

bonus : $(OBJS) 
	ar rcs $(NAME) $(OBJS) 

.PHONY:	all clean fclean re bonus
