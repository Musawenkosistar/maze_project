# Makefile for building and running the SDL2 project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
LDFLAGS = -lm `sdl2-config --cflags` `sdl2-config --libs`

# Source files
SRC = ./src/*.c
# Output binary name
TARGET = maze

# Build target
build:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)

# Run target
run:
	./$(TARGET)

# Clean target
clean:
	rm -f $(TARGET)  # Use -f to avoid error if the file doesn't exist
