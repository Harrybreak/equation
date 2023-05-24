.PHONY: clean
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp, %.o, $(SRC))
NAME=main
CC=g++
LIBS=-lm
CFLAGS=-g
OFLAGS=-O2 -I .
$(NAME): $(OBJ)
	$(CC) $(OFLAGS) -o $@ $^ $(LIBS)
	./$(NAME)
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $^
clean:
	rm -Rf $(NAME) *.o *.exe *.obj *.class *.dep *.dump *.temp