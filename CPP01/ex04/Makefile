NAME = replace

FLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

SRCS = main.cpp
all: $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:clean

re: clean all

.PHONY:all re clean fclean