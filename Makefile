CFLAGS = -Wextra -Wall -Werror -ggdb

LIBS = ./libs/

INCLUDES += -I$(LIBS)libft -I./includes
LDFLAGS = $(INCLUDES) -L$(LIBS)libft -lft

SOURCES = src/main.c \
		  src/pipex.c \
		  src/util/utils.c \
		  src/util/cleanup_utils.c \

OBJECTS = $(SOURCES:.c=.o)

NAME = pipex

all: libs $(NAME)

$(NAME): $(OBJECTS)
	cc $(CFLAGS) -fsanitize=address $(OBJECTS) -o $(NAME) $(LDFLAGS)

strict:
	@# dirty hack, grep returns 1 if there's no instance of the word "Error"
	@# https://stackoverflow.com/a/38485725
	@norminette | (grep 'Error' || true)
	@norminette > /dev/null
	@echo "norminette check passed !"
	make

%.o: %.c
	cc $(CFLAGS) -c $(INCLUDES) $< -o $@

clean:
	make -C ./libs/libft clean
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	make -C ./libs/libft fclean
	rm -rf build

re:
	make fclean
	make libs
	make

libs:
	make -C ./libs/libft

.PHONY: all clean fclean re libs $(NAME)
