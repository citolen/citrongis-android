NAME=	test

SRC=	Geometry/Point.cpp\
	Geometry/Vector2.cpp\
	Geometry/Vector3.cpp\
	Geometry/BoundingBox.cpp\
	Helpers/CoordinatesHelper.cpp\
	Utils/Comparison.cpp\
	Utils/Intersection.cpp\
	main.cpp

OBJ=	$(SRC:.cpp=.o)

CPPFLAGS=	-I./Geometry -I./Helpers -I./Utils

all: $(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) -lproj -Wl,-rpath=/usr/local/lib

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all