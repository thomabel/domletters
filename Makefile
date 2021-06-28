CXX = g++
CXXFLAGS = -g -Wall -Werror
TARGET = domletters
SRCS = domletters.cpp

$(TARGET): $(SCRS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	-rm -f $(TARGET)
