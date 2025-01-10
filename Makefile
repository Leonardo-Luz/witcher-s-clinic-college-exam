# Project: witcher
#
# Compiler and flags
CC=gcc
CFLAGS=-Wall -g

# Libraries
LIBS=-lGL -lm -lpthread -ldl -lrt -lX11

# Source and output
SRC := $(wildcard ./src/*.c)
OBJ=$(SRC:./src/%.c=build/%.o)
EXEC=./bin/app

# Directories
BUILDDIR := build
BINDIR := bin

# Create the build and bin directory if it doesn't exist
build:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BINDIR)

# Default target (build the executable)
all: $(EXEC)

# Link the object files into the executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LIBS)

# Compile the source files into object files
build/%.o: ./src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -rf build bin

# Run the program
run: $(EXEC)
	./$(EXEC)

# Declare phony targets
.PHONY: all clean run build
