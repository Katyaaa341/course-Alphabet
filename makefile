EXE = bin/Alphabet
TEST = bin/Test

DIR_SRC = build/src
DIR_TEST = build/test
DIR_GTEST = thirdparty/googletest

GFLAGS += -isystem $(DIR_GTEST)/include
LDFLAGS += -g -Wall -Wextra -pthread --std=c++17

FLAGS = -Wall -Werror --std=c++17
TEST_FLAGS = g++ $(GFLAGS) $(LDFLAGS) -L$(DIR_GTEST)/lib -l gtest_main -l gtest -lpthread

OBJ = g++ $(FLAGS) -c $^ -o $@
TEST_OBJ = g++ $(GFLAGS) $(LDFLAGS) -I src -c $^ -o $@

all: $(EXE) $(TEST)

.PHONY: clean all

$(EXE): $(DIR_SRC)/main.o $(DIR_SRC)/menu.o $(DIR_SRC)/parse.o $(DIR_SRC)/textFunctions.o
	g++ $(FLAGS) $^ -o $@

$(TEST): $(DIR_TEST)/test.o $(DIR_SRC)/parse.o $(DIR_SRC)/textFunctions.o
	$(TEST_FLAGS) $^ -o $@

$(DIR_TEST)/test.o: test/test.cpp
	$(TEST_OBJ)
$(DIR_SRC)/main.o: src/main.cpp
	$(OBJ)
$(DIR_SRC)/menu.o: src/menu.cpp
	$(OBJ)
$(DIR_SRC)/parse.o: src/parse.cpp
	$(OBJ)
$(DIR_SRC)/textFunctions.o: src/textFunctions.cpp
	$(OBJ)

clean:
	rm -rf $(DIR_SRC)/*.o
	rm -rf $(DIR_TEST)/*.o
	rm -rf bin/*.exe
	rm $(EXE)
	rm $(TEST)
