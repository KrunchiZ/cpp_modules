CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

NAME		= phonebook
SRC			= megaphone.cpp

OBJS_DIR	= build/

OBJS		= $(SRC:.cpp=.o)
BUILD_OBJS	= $(addprefix $(OBJS_DIR), $(OBJS))

vpath %.o $(OBJS_DIR)

GREEN	= \e[32m
CYAN	= \e[36m
WHITE	= \e[0m

.PHONY: all fclean clean re
.SILENT:

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CPP) $(CPPFLAGS) $(BUILD_OBJS) -o $(NAME)
	echo "Making $(GREEN)$(NAME)$(WHITE)..."

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $(addprefix $(OBJS_DIR), $@)
	echo "Compiling $(CYAN)$@$(WHITE)..."

fclean: clean
	rm -f $(NAME)
	echo "Removing $(GREEN)$(NAME)$(WHITE)"

clean:
	rm -rf $(OBJS_DIR)
	echo "Removing $(CYAN)object$(WHITE) files..."

re: fclean all
