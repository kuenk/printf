NAME	= libftprintf.a
SRCS   	= ft_printf.c ft_auxiliar.c ft_auxiliar_two.c
CFLAGS	= -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar -crs $@ $^

%.o : %.c
	cc -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re
