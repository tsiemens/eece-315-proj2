#Compiler
CXX := g++

#Executable to compile
EXECUTABLE :=  

#Compiler Flags
CFLAGS := -std=c++0x -Wall

#Linker Flags
LDFLAGS := -g

#Source files
SRC := $(wildcard src/*.cpp)

#Object Files 
OBJ := $(subst src/, obj/, $(SRC:.cpp=.o))

#Rule to link executable
$(addprefix bin/, $(EXECUTABLE)) : $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ)

#Rule to generate .d and .o files from .cpp files
obj/%.o : src/%.cpp
	$(CXX) $(CFLAGS) -o $@ -c -MT "$@" -MMD -MP $<

#include dependency files
-include $(patsubst src/%.cpp, obj/%.d, $(SRC))  

#Rule to clean generated files
.PHONY : clean
clean  :
	$(RM) $(addprefix bin/, $(EXECUTABLE)) $(OBJ)
