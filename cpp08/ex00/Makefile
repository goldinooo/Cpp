NAME = easyfind

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS) easyfind.hpp
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp whatever.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
