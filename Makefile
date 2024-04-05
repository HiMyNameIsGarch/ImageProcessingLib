# Created Date: Friday, April 5th 2021, 00:02:00 AM
# Author: Gabriel Hanu
#
# *DOCUMENTATION*
# To see a list of typical targets execute "make help"
# More detailed info can be located in ./README
#
# *LICENSE*
# SPDX-License-Identifier: GPL-3.0
# See LICENSE file for more information.
#
# *WARNING*
# This Makefile is intended for the GNU/Linux operating system.
# It may not work as expected or at all on other operating systems such as Windows or macOS.


# Compiler flags
CXX = clang++
CXXFLAGS = -std=c++20 -Wall -Wextra -I$(INCLUDE_DIR) -Werror -Wpedantic -g

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
DEBUG_DIR = debug

# Files and include directories
SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.cpp')
INCLUDE_DIRS := $(shell find $(INCLUDE_DIR) -type d)

MAIN := ./app.cpp
EXECUTABLE = $(BUILD_DIR)/process_image

.PHONY: all clean debug run

all: $(EXECUTABLE) run

# Build the executable
$(EXECUTABLE): $(SRC_FILES)
	@mkdir -p $(BUILD_DIR) # Make sure the build directory exists
	$(CXX) $(CXXFLAGS) -o $@ $^ $(MAIN)

# Debug the executable
debug: $(EXECUTABLE)
	@mkdir -p $(DEBUG_DIR) # Make sure the debug directory exists
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$(DEBUG_DIR)/valgrind_output.txt ./$(EXECUTABLE)
	@echo "Valgrind output saved to $(DEBUG_DIR)/valgrind_output.txt"
	@cat $(DEBUG_DIR)/valgrind_output.txt

# Run the executable
run: $(EXECUTABLE)
	@./$(EXECUTABLE)

# Clean the build and debug directories
clean:
	rm -rf $(BUILD_DIR)/* $(DEBUG_DIR)/*

help:
	@echo "Usage: make [all|clean|debug|run|help]"
	@echo "	all: Builds the executable and runs it"
	@echo "	clean: Cleans the build and debug directories"
	@echo "	debug: Builds the executable and runs it with valgrind"
	@echo "	run: Runs the executable from $(EXECUTABLE)"
	@echo "	help: Displays this message"
