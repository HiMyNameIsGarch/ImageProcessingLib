CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -Werror -Wpedantic -g

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
DEBUG_DIR = debug

SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.cpp')
INCLUDE_DIRS := $(shell find $(INCLUDE_DIR) -type d)

MAIN := ./main.cpp

EXECUTABLE = $(BUILD_DIR)/myprogram

.PHONY: all clean debug run

all: $(EXECUTABLE) run

$(EXECUTABLE): $(SRC_FILES)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(MAIN)

debug: $(EXECUTABLE)
	@valgrind --leak-check=full --show-leak-kinds=all --log-file=$(DEBUG_DIR)/valgrind_output.txt ./$(EXECUTABLE)
	@echo "Valgrind output saved to $(DEBUG_DIR)/valgrind_output.txt"
	@cat $(DEBUG_DIR)/valgrind_output.txt

run: $(EXECUTABLE)
	$(info "Running ./$(EXECUTABLE)..")
	@./$(EXECUTABLE)

clean:
	rm -rf $(BUILD_DIR)/* $(DEBUG_DIR)/*
