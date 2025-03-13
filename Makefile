# Define Directories
SRC_DIR = src
BIN_DEBUG_DIR = bin/Debug
BIN_RELEASE_DIR = bin/Release

# Target Executable
TARGET_DEBUG = $(BIN_DEBUG_DIR)/calculator
TARGET_RELEASE = $(BIN_RELEASE_DIR)/calculator

# Source File
SRC = $(SRC_DIR)/main.c

# Compiler Flags
CC = gcc
CFLAGS_DEBUG = -Wall -Wextra -g # Debug flags (include debugging symbols)
CFLAGS_RELEASE = -Wall -Wextra -02 # Release flags (optimize for performance)

# Default target (builds debug mode)
all: debug

# Debug Target
debug: $(TARGET_DEBUG)

# Release target
release: $(TARGET_RELEASE)

# Rule to build the debug target
$(TARGET_DEBUG): $(SRC)
	@mkdir -p $(BIN_DEBUG_DIR) # Create the output directory if it doens't exist
	$(CC) $(CFLAGS_DEBUG) -o $(TARGET_DEBUG) $(SRC)

# Rule to build the releae target
$(TARGET_RELEASE): $(SRC)
	@mkdir -p $(BIN_RELEASE_DIR) # Create the output directory if it doens't exist
	$(CC) $(CFLAGS_DEBUG) -o $(TARGET_RELEASE) $(SRC)

# Clean Up
clean: 
	rm -f $(TARGET_DEBUG) $(TARGET_RELEASE) # Remove both debug and release executables
