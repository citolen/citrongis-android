NAME=	Test-CitronGIS

SRC=	vectors.cpp \
	boundingBox.cpp \
	../Sources/Geometry/Point.cpp \
	../Sources/Geometry/Vector2.cpp \
	../Sources/Geometry/Vector3.cpp \
	../Sources/Geometry/BoundingBox.cpp \
	../Sources/Utils/Comparison.cpp \
	../Sources/Utils/Intersection.cpp \
	../Sources/Helpers/CoordinatesHelper.cpp \
	../Sources/Helpers/ProjectionsHelper.cpp \
	../Sources/System/Viewport.cpp \


OBJ=	$(SRC:.cpp=.o)

RM=	rm -f

G++=	g++

CPPFLAGS=	-I./../Headers

LIBS=	-lboost_unit_test_framework -lproj -Wl,-rpath=/usr/local/lib


$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

all: $(NAME)

clean:
	$(RM) *~
	$(RM) *#
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all