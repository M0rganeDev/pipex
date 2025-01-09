CFLAGS = -Wextra -Wall -Werror -ggdb

LIBS = ./libs/

INCLUDES += -I$(LIBS)libft -I./includes
LDFLAGS = $(INCLUDES) -L$(LIBS)libft -lft

SOURCES = src/main.c \
		  src/pipex.c \
		  src/util/utils.c \

OBJECTS = $(SOURCES:.c=.o)

NAME = pipex

all: $(NAME)

$(NAME): $(OBJECTS)
	cc $(CFLAGS)  $(OBJECTS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	cc $(CFLAGS) -c $(INCLUDES) $< -o $@

clean:
	make -C ./libs/libft clean
	rm -f $(OBJECTS)

push:
	git add *
	git add .
ifeq ($(m),)
    $(error This task require a MESSAGE variable, please do make push m="your message")
endif
	git commit -m "$(m)"
	git push

fclean: clean
	rm -f $(NAME)
	make -C ./libs/libft fclean

re:
	make fclean
	make libs
	make

libs:
	make -C ./libs/libft

.PHONY: all clean fclean re libs $(NAME)
