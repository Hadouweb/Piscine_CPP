CC = -Wall -Wextra -Werror

NAME = array

SRC = main.cpp\

OBJ = $(SRC:%.cpp=%.o)

%.o: %.cpp
	clang++ $(CC) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(CC) -o $(NAME) $(OBJ) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re