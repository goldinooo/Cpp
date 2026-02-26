NAME = megaphone
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
BUILD_DIR= build
CWD = .
SRCS= $(shell find $(CWD) -type f -name "*.cpp")
OBJS= $(addprefix $(BUILD_DIR)/, $(SRCS:$(CWD)/%.cpp=%.o))

all: $(NAME)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(BUILD_DIR) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re