
NAME = libmt.a

STD = stdlibmt/libstdmt.a
PRINTF = printf/libprintf.a
GNL = get_next_line/libgnl.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(STD) $(PRINTF) $(GNL)

all: $(NAME)

$(NAME): $(SRCS)
	@ar rcT $(NAME) $^

$(STD): 
	@(cd stdlibmt; make)

$(PRINTF):
	@(cd printf; make)

$(GNL):
	@(cd get_next_line; make)

clean:
	@(cd stdlibmt; make clean)
	@(cd printf; make clean)
	@(cd get_next_line; make clean)

fclean: clean
	@rm -f $(NAME)
	@(cd stdlibmt; make fclean)
	@(cd printf; make fclean)
	@(cd get_next_line; make fclean)

re: fclean all

.PHONY: all clean fclean re