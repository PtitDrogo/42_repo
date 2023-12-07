SRCS	=	ft_printf.c ft_nbr_len.c ft_putnbr_base.c ft_putncount_char.c \
		ft_putncount_str.c ft_strlen.c ft_putunsign_int.c ft_print_ptr.c 
OBJS	=	$(SRCS:.c=.o)

CC	=	cc
RM	=	rm -f
CFLAGS	=	-I. -MMD -MP
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
