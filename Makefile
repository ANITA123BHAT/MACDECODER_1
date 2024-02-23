#makefile for compilation in one short
# Compiler and flags
CXX = g++
CFLAGS = -Wall 

# Source files
SRCS = main.cpp mac_decoder.cpp mac_lcid_val.cpp lcid_val_store.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Targets
TARGET = main

# Default target
all: $(TARGET)

# Compile source files
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

# Clean the project
clean:
	rm -f $(OBJS) $(TARGET)
	
	
