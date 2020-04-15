CXX		  := clang++
CXX_FLAGS := -Wall -Wextra -std=c++17 -g
RAYLIB_FLAGS := -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL /Users/eudvazquez/personal/raylib/raylib/src/libraylib.a
BIN		:= bin
SRC		:= src
INCLUDE	:= include 
RAYLIB := "/Users/eudvazquez/personal/raylib/raylib/src"
RAYGUI := "/Users/eudvazquez/personal/raylib/raygui/src"
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main
COMPONENTS := $(SRC)/engine/components/*.cpp
GRAPHIC_COMPONENTS := $(SRC)/engine/components/graphics/*.cpp
BEHAVIOUR_COMPONENTS := $(SRC)/engine/components/behaviours/*.cpp
EVENTS := $(SRC)/engine/events/*.cpp
SYTEMS := $(SRC)/engine/systems/*.cpp
ENGINE := $(SRC)/engine/*.cpp
GAME := $(SRC)/game/*.cpp


$(BIN)/$(EXECUTABLE): $(EVENTS) $(COMPONENTS) $(GRAPHIC_COMPONENTS) $(BEHAVIOUR_COMPONENTS) $(SYTEMS) $(ENGINE) $(GAME) $(SRC)/main.cpp
	$(CXX) $(CXX_FLAGS) $(RAYLIB_FLAGS) -I$(INCLUDE) -I$(RAYLIB) -I$(RAYGUI) -L$(LIB) $^ -o $@ $(LIBRARIES)

run:
	./$(BIN)/$(EXECUTABLE)

clean:
	-rm $(BIN)/*

# Tests
tester:
	$(CXX) $(CXX_FLAGS) $(RAYLIB_FLAGS) $(EVENTS) $(COMPONENTS) $(GRAPHIC_COMPONENTS) $(BEHAVIOUR_COMPONENTS) $(SYTEMS) $(ENGINE) $(GAME) test/tester.cpp -I$(INCLUDE) -I$(RAYLIB) -L$(LIB) $^ -o bin/tester
	./$(BIN)/tester