# Specify the compiler
CXX = g++

# Specify the compile flags
CXXFLAGS = -Wall -std=c++11

# Target file
TARGET = gs

# Source files
SOURCES = gs.cpp

# Default target
all: $(TARGET)

# Rule: how to generate the target file from the source files
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Clean target
clean:
	rm -f $(TARGET)