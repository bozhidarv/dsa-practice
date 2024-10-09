CC = clang++
DEVFLAGS = --debug
FLAGS = -Wall -Wextra -std=c++2c -pedantic
FILES = main.cpp
CR_OUT_DIR = mkdir -p out

compile:
	$(CR_OUT_DIR) && $(CC) $(FLAGS) $(DEVFLAGS) $(FILES) -o ./out/main

compile-iterator:
	$(CR_OUT_DIR) && $(CC) $(FLAGS) $(DEVFLAGS) $(FILES) ./iterators/iterators.cpp -o ./out/main

compile-dev:
	$(CR_OUT_DIR) && $(CC) $(FLAGS) $(FILES) $(DEVFLAGS) -o ./out/main

run:
	./out/main
