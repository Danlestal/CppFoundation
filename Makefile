CXX		  := clang++
CXX_FLAGS := -Wno-c++11-narrowing -Wall -Wextra -std=c++17 -g 
RAYLIB_FLAGS := -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL ../raylib/src/libraylib.a
BIN		:= bin
SRC		:= src
INCLUDE	:= include 
RAYLIB := "../raylib/src"
RAYGUI := "../raygui/src"
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main
COMPONENTS := $(SRC)/engine/components/*.cpp
GRAPHIC_COMPONENTS := $(SRC)/engine/components/graphics/*.cpp
BEHAVIOUR_COMPONENTS := $(SRC)/engine/components/behaviours/*.cpp
EVENTS := $(SRC)/engine/events/*.cpp
SYTEMS := $(SRC)/engine/systems/*.cpp
ENGINE := $(SRC)/engine/*.cpp
UICOMPONENTS := $(SRC)/engine/uiComponents/*.cpp
GAME := $(SRC)/game/*.cpp


$(BIN)/$(EXECUTABLE): $(EVENTS) $(COMPONENTS) $(GRAPHIC_COMPONENTS) $(BEHAVIOUR_COMPONENTS) $(SYTEMS) $(ENGINE) $(GAME) $(UICOMPONENTS) $(SRC)/main.cpp
	$(CXX) $(CXX_FLAGS) $(RAYLIB_FLAGS) -I$(INCLUDE) -I$(RAYLIB) -I$(RAYGUI) -L$(LIB) $^ -o $@ $(LIBRARIES) 


run:
	./$(BIN)/$(EXECUTABLE)

clean:
	-rm $(BIN)/*

# Tests
tester:
	$(CXX) $(CXX_FLAGS) $(RAYLIB_FLAGS) $(EVENTS) $(COMPONENTS) $(GRAPHIC_COMPONENTS) $(BEHAVIOUR_COMPONENTS) $(SYTEMS) $(ENGINE) $(GAME) test/tester.cpp -I$(INCLUDE) -I$(RAYLIB) -L$(LIB) $^ -o bin/tester
	./$(BIN)/tester