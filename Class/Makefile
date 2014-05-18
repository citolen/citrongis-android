NAME=	test

SRC=	Geometry/Point.cpp\
	Geometry/Vector2.cpp\
	Geometry/Vector3.cpp\
	Helpers/CoordinatesHelper.cpp\
	main.cpp

OBJ=	$(SRC:.cpp=.o)

CPPFLAGS=	-I./Geometry -I./Helpers

all: $(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) -lproj -Wl,-rpath=/usr/local/lib

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all