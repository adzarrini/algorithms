# CC
CC = clang++
NAME = bfs
CFLAGS = -W -Wall

$(NAME): vertex.o main.o
	$(CC) vertex.o main.o -o $(NAME) $(CFLAGS)

vertex.o: lib/vertex.cpp lib/vertex.h
	$(CC) $(CFLAGS) -c lib/vertex.cpp

main.o: src/main.cpp lib/vertex.h
	$(CC) $(CFLAGS) -c src/main.cpp

run: $(NAME)
	./$(NAME)

clean:
	rm -rf $(NAME) *.o
