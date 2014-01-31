EX_NAME=MEM_POOL_TEST
CC=clang++

all:
	$(CC) -o $(EX_NAME) main.cpp	

test: all
	./$(EX_NAME)

debug: 
	$(CC) -o $(EX_NAME) -g main.cpp
