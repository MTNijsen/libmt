
NAME = libprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf_flag.c ft_printf_freeoutput.c ft_printf_nmb.c ft_printf_str.c ft_printf_strappend.c ft_printf.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $^

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re