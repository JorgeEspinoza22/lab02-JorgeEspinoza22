CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = testbst
SRCS = intbst.cpp testbst.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

intbst.o: intbst.cpp intbst.h
    $(CXX) $(CXXFLAGS) -c intbst.cpp -o intbst.o

testbst.o: testbst.cpp intbst.h
    $(CXX) $(CXXFLAGS) -c testbst.cpp -o testbst.o

clean:
    rm -f *.o $(TARGET)

