NAME = zombie

FLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

SRCS = main.cpp newZombie.cpp Zombie.cpp randomChump.cpp
all: $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:clean

re: clean all

.PHONY:all re clean fclean