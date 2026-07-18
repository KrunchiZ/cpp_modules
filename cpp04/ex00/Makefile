CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP

NAME		= ex00
SRC			= main.cpp		\
			  Animal.cpp	\
			  Dog.cpp		\
			  Cat.cpp

OBJS_DIR	= build/

OBJS		= $(SRC:.cpp=.o)
BUILD_OBJS	= $(addprefix $(OBJS_DIR), $(OBJS))
DEPS		= $(BUILD_OBJS:.o=.d)

GREEN	= \e[32m
CYAN	= \e[36m
WHITE	= \e[0m

.PHONY: all fclean clean re
.SILENT:

all: $(NAME)

$(NAME): $(OBJS_DIR) $(BUILD_OBJS)
	$(CPP) $(CPPFLAGS) $(BUILD_OBJS) -o $(NAME)
	printf "Making $(GREEN)$(NAME)$(WHITE)...\n"

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@
	printf "Compiling $(CYAN)$@$(WHITE)...\n"

fclean: clean
	rm -f $(NAME)
	printf "Removing $(GREEN)$(NAME)$(WHITE)...\n"

clean:
	rm -rf $(OBJS_DIR)
	printf "Removing $(CYAN)object$(WHITE) files...\n"

re: fclean all

-include $(DEPS)
