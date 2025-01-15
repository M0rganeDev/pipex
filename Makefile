CFLAGS = -Wextra -Wall -Werror -ggdb

LIBS = ./libs/

INCLUDES += -I$(LIBS)libft -I./includes
LDFLAGS = $(INCLUDES) -L$(LIBS)libft -lft

SOURCES = src/main.c \
		  src/pipex.c \
		  src/util/utils.c \

OBJECTS = $(SOURCES:.c=.o)

NAME = pipex

all: libs $(NAME)
	rm -rf build
	mkdir build
	touch build/test
	touch build/test2
	cp $(NAME) build/

$(NAME): $(OBJECTS)
	cc $(CFLAGS)  $(OBJECTS) -o $(NAME) $(LDFLAGS)

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
