CC = g++
CFLAGS = -std=c++11

# List of source files
SRCS = assn2.cpp functions.cpp circle.cpp square.cpp rectangle.cpp cross.cpp

# header files
HEADERS = functions.h shapetwod.h circle.h square.h rectangle.h cross.h

# List of object files to be created
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = csci251_a2.app

# Rule to compile .cpp files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Build rule
$(TARGET): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)
