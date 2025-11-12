# Compiler and flags
CC = gcc
# Add -g for debugging
CFLAGS = -Wall -Wextra -pedantic -Iinclude -g
LDFLAGS = -lm

# Directories
SRCDIR = src
OBJDIR = obj
# BINDIR = bin
BINDIR = ./

# Find all .c files in the source directory
SOURCES = $(wildcard $(SRCDIR)/*.c)
# Create a list of object files in the obj directory
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Name of the final executable
EXECUTABLE = $(BINDIR)/matrix_app

# Default target: build all
all: $(EXECUTABLE)

# Rule to link the executable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BINDIR) # Create bin directory if it doesn't exist
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "Compilation finished. Executable is at $(EXECUTABLE)"

# Rule to compile a .c file into a .o file
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR) # Create obj directory if it doesn't exist
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up the project
clean:
	@echo "Cleaning up..."
	rm -rf $(OBJDIR) $(BINDIR) a.out

# Phony targets are not files
.PHONY: all clean
