# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -Werror -Iinclude -ffreestanding -O2
AR = ar
ARFLAGS = rcs

# Directories
SRC_DIRS = memory string system
BUILD_DIR = build

# Find all .c files automatically
SRCS = $(shell find $(SRC_DIRS) -name '*.c')

# Convert source files to object files inside build/
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))

# Output library
TARGET = libkstdlib.a
SHARED = libkstdlib.so

# Default target
all: $(TARGET)

# Create static library
$(TARGET): $(OBJS)
	@echo "Archiving library..."
	$(AR) $(ARFLAGS) $@ $^

# Compile .c -> .o
$(BUILD_DIR)/%.o: %.c
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(SHARED): $(OBJS)
	$(CC) -shared -o $@ $^

install:
	cp $(TARGET) /usr/local/lib/
	cp -r include/* /usr/local/include/

# Clean build files
clean:
	@echo "Cleaning..."
	rm -rf $(BUILD_DIR) $(TARGET)

# Rebuild everything
re: clean all

.PHONY: all clean re
