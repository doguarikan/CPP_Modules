NAME = Harl

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

SRCS = main.cpp Harl.cpp
all: $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:clean

re: clean all

.PHONY:all re clean fclean