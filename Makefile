#Compiler
CXX := g++

#Executable to compile
EXECUTABLE := cpu-sch-sim 

#Compiler Flags
CFLAGS := -std=c++0x -Wall

#Linker Flags
LDFLAGS := -g

#Source files
SRC := $(wildcard src/*.cpp)

#Object Files 
OBJ := $(subst src/, obj/, $(SRC:.cpp=.o))

#Prevent echoing of commands
.SILENT :

#Rule to link executable
$(addprefix bin/, $(EXECUTABLE)) : $(OBJ)
	echo "	LD	$@"
	mkdir -p bin/
	$(CXX) $(LDFLAGS) -o $@ $(OBJ)
	echo "Build Succeeded"

#Rule to generate .d and .o files from .cpp files
obj/%.o : src/%.cpp
	echo "	CXX	$<"
	mkdir -p obj/
	$(CXX) $(CFLAGS) -o $@ -c -MMD -MP $<

#include dependency files
-include $(patsubst src/%.cpp, obj/%.d, $(SRC))  

#Rule to clean generated files
.PHONY : clean
clean  :
	$(RM) -r bin/ obj/
