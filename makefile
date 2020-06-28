EXE = bin/Alphabet

DIR_SRC = build/src

FLAGS = -Wall -Werror --std=c++17

OBJ = g++ $(FLAGS) -c $^ -o $@

all: $(EXE)

.PHONY clean all

$(EXE): $(DIR_SRC)/main.o
	g++ $(FLAGS) $^ -0 $@

$(DIR_SRC)/main.o: src/main.cpp
	$(OBJ)

clean:
	rm -rf $(DIR_SRC)/*.o
	rm bin/*.exe
