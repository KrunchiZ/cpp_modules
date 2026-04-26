CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP

NAME		= awesomePhoneBook
SRC			= main.cpp		\
			  PhoneBook.cpp	\
			  Contact.cpp

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
	echo "Making $(GREEN)$(NAME)$(WHITE)..."

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@
	echo "Compiling $(CYAN)$@$(WHITE)..."

fclean: clean
	rm -f $(NAME)
	echo "Removing $(GREEN)$(NAME)$(WHITE)"

clean:
	rm -rf $(OBJS_DIR)
	echo "Removing $(CYAN)object$(WHITE) files..."

re: fclean all

-include $(DEPS)
