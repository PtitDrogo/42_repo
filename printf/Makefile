SRCS	=	ft_printf.c ft_putnbr.c ft_putncount_char.c \
		ft_putncount_str.c ft_putunsign.c ft_print_ptr.c 
OBJS	=	$(SRCS:.c=.o)

CC	=	cc
RM	=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -I. -MMD -MP
DEPS	=	$(OBJS:.o=.d)

NAME	=	libftprintf.a

all:	$(NAME)
-include $(DEPS) 

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
