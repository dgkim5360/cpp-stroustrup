CC=g++ -std=c++11
BIN=bin

default:
	echo "Chapter 5. A Tour of C++: Concurrency and Utilities"


5-3-1-hello-parallel: $(BIN)/5-3-1-hello-parallel.out
	./$<

5-3-2-print-vector: $(BIN)/5-3-2-print-vector.out
	./$<

5-3-3-thread-result: $(BIN)/5-3-3-thread-result.out
	./$<


$(BIN)/5-3-1-hello-parallel.out: 5-3-concurrency-1-tasks-and-threads.cpp
	$(CC) -o $@ $< -lpthread

$(BIN)/5-3-2-print-vector.out: 5-3-concurrency-2-passing-arguments.cpp
	$(CC) -o $@ $< -lpthread

$(BIN)/5-3-3-thread-result.out: 5-3-concurrency-3-returning-results.cpp
	$(CC) -o $@ $< -lpthread
	

clean:
	$(RM) $(BIN)/*.out
