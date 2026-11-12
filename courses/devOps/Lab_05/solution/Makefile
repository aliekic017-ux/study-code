# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Iinclude -std=c11 -Wall -Wextra -Werror -g -DSTARTING_TIME=300

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
TEST_DIR := tests

# Source and object files
SRCS := $(SRC_DIR)/main.c \
		$(SRC_DIR)/board.c \
		$(SRC_DIR)/move.c \
		$(SRC_DIR)/util.c

SRCS_TEST := $(SRC_DIR)/board.c \
				$(SRC_DIR)/move.c \
				$(SRC_DIR)/util.c \
				$(TEST_DIR)/test_move.c

OBJS := $(BUILD_DIR)/main.o \
		$(BUILD_DIR)/board.o \
		$(BUILD_DIR)/move.o \
		$(BUILD_DIR)/util.o

TARGET := $(BIN_DIR)/chess_clock
TEST_TARGET := $(BIN_DIR)/test_move

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(SRCS_TEST)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRCS_TEST) -o $(TEST_TARGET)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)