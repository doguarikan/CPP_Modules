NAME = fixed

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

RM = rm -rf

SRCS = main.cpp Fixed.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:clean

re: clean all

.PHONY:all re clean fclean
