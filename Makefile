# Makefile for building C++ project

CXX := g++
CXXFLAGS := -std=c++11 -Wall
SRCDIR := ./includes
BUILDDIR := ./out
TARGET := main

INCLUDES=-I/opt/homebrew/include -I$(SRCDIR)
LIB=-L/opt/homebrew/lib -lcppcms

SRCS := $(wildcard $(SRCDIR)/**/*.cpp $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

$(TARGET): $(OBJS)
	$(CXX) $(TARGET).o $(CXXFLAGS) $^ -o $@ $(LIB) $(INCLUDES) -v

$(TARGET).o: $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(INCLUDES) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(INCLUDES) $(LIB)

clean:
	rm -rf $(BUILDDIR) $(TARGET)

.PHONY: clean
