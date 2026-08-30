NAME = Array

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS) Array.hpp Array.tpp
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
