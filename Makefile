CC = gcc

SRC = main.c

TARGET = main

FLAGS = -lGL -lm -lpthread -ldl -lrt -lX11

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(FLAGS)
