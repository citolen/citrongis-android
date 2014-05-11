NAME=	test

SRC=	Point.cpp\
	CoordinatesHelper.cpp\
	main.cpp

OBJ=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) -lproj -Wl,-rpath=/usr/local/lib

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all