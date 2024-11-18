# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Targets and dependencies
TARGET = WordCountTest
OBJS = WordCount.o tddFuncs.o

# Default target
all: $(TARGET)

# Linking target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile object files
WordCount.o: WordCount.cpp WordCount.h
	$(CXX) $(CXXFLAGS) -c WordCount.cpp

tddFuncs.o: tddFuncs.cpp tddFuncs.h
	$(CXX) $(CXXFLAGS) -c tddFuncs.cpp

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)
