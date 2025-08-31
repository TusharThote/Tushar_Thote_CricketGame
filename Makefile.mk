
# Created By: Tushar Thote
# Date      : 31-08-2025
# Project   : CricketGame

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

# Target executable
TARGET = CricketGame

# Source files
SRCS = main.cpp Person.cpp Player.cpp Umpire.cpp Team.cpp CricketTeam.cpp Match.cpp ScoreBoard.cpp

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link object files to create final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the game
run: $(TARGET)
	./$(TARGET)
