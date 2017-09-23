CC=g++ -std=c++11
BIN=bin

2-2-1-hello: $(BIN)/2-2-1-hello.out
	./$<

2-2-4-y-or-n: $(BIN)/2-2-4-y-or-n.out
	./$<

2-2-5-print-and-count: $(BIN)/2-2-5-print-and-count.out
	./$<

2-3-1-vector-sum: $(BIN)/2-3-1-vector-sum.out
	./$<

2-3-2-vector-sum: $(BIN)/2-3-2-vector-sum.out
	./$<

2-3-3-traffic-lights: $(BIN)/2-3-3-traffic-lights.out
	./$<

2-4-1-vector-sqrt-sum: $(BIN)/2-4-1-vector-sqrt-sum.out
	./$<

2-4-3-error-handling: $(BIN)/2-4-3-error-handling.out
	./$<


$(BIN)/2-2-1-hello.out: 2-2-the-basics-1-hello-world.cpp
	$(CC) -o $@ $<

$(BIN)/2-2-4-y-or-n.out: 2-2-the-basics-4-tests-and-loops.cpp
	$(CC) -o $@ $<

$(BIN)/2-2-5-print-and-count.out: 2-2-the-basics-5-pointers-arrays-and-loops.cpp
	$(CC) -o $@ $<

$(BIN)/2-3-1-vector-sum.out: 2-3-user-defined-types-1-structures.cpp
	$(CC) -o $@ $<

$(BIN)/2-3-2-vector-sum.out: 2-3-user-defined-types-2-classes.cpp
	$(CC) -o $@ $<

$(BIN)/2-3-3-traffic-lights.out: 2-3-user-defined-types-3-enumerations.cpp
	$(CC) -o $@ $<

$(BIN)/2-4-1-vector-sqrt-sum.out: $(BIN)/2-4-modularity-1-separate-compilation--Vector.o $(BIN)/2-4-modularity-1-separate-compilation--user.o
	$(CC) -o $@ $(BIN)/2-4-modularity-1-separate-compilation--Vector.o $(BIN)/2-4-modularity-1-separate-compilation--user.o

$(BIN)/2-4-3-error-handling.out: 2-4-modularity-3-error-handling.cpp
	$(CC) -o $@ $<


$(BIN)/2-4-modularity-1-separate-compilation--Vector.o: 2-4-modularity-1-separate-compilation--Vector.cpp 2-4-modularity-1-separate-compilation--Vector.h
	$(CC) -o $@ -c $<

$(BIN)/2-4-modularity-1-separate-compilation--user.o: 2-4-modularity-1-separate-compilation--user.cpp 2-4-modularity-1-separate-compilation--Vector.h
	$(CC) -o $@ -c $<


clean:
	$(RM) $(BIN)/*.o $(BIN)/*.out
