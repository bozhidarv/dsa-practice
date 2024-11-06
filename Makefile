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

compile-sorts:
	$(CR_OUT_DIR) && $(CC) $(FLAGS) $(DEVFLAGS) $(FILES) ./sorts/sorts.cpp -o ./out/main


compile-2:
	$(CR_OUT_DIR) && $(CC) $(FLAGS) $(DEVFLAGS) $(FILES) ./practice2/practice2.cpp -o ./out/main

compile-3:
	$(CR_OUT_DIR) && $(CC) $(FLAGS) $(DEVFLAGS) $(FILES) ./practice3/practice3.cpp -o ./out/main

compile-4:
	$(CR_OUT_DIR) && $(CC) $(FLAGS) $(DEVFLAGS) $(FILES) ./practice4/practice4.cpp -o ./out/main

compile-5:
	$(CR_OUT_DIR) && $(CC) $(FLAGS) $(DEVFLAGS) $(FILES) ./practice5/practice5.cpp -o ./out/main

run:
	./out/main
