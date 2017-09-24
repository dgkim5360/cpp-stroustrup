CC=g++ -std=c++11
BIN=bin

default:
	echo "Chapter 4: A Tour of C++: Containers and Algorithms"


4-2-string: $(BIN)/4-2-string.out
	./$< dgkim5360 dgkim.com

4-3-streamio: $(BIN)/4-3-streamio.out
	./$< < $(BIN)/book-entries.txt

4-4-1-vector: $(BIN)/4-4-1-vector.out
	./$< < $(BIN)/book-entries.txt

4-4-1-2-range-check: $(BIN)/4-4-1-2-range-check.out
	./$< < $(BIN)/book-entries.txt

4-4-2-list: $(BIN)/4-4-2-list.out
	./$<

4-4-3-map: $(BIN)/4-4-3-map.out
	./$<

4-4-4-unordered-map: $(BIN)/4-4-4-unordered-map.out
	./$<

4-5-algorithms: $(BIN)/4-5-algorithms.out
	./$< < $(BIN)/book-entries.txt

4-5-1-find-all: $(BIN)/4-5-1-find-all.out
	./$<

4-5-3-io-iterators: $(BIN)/4-5-3-io-iterators.out
	./$<

4-5-4-predicates: $(BIN)/4-5-4-predicates.out
	./$<

4-5-6-sort: $(BIN)/4-5-6-sort.out
	./$< < $(BIN)/book-entries.txt
	

$(BIN)/4-2-string.out: 4-2-strings.cpp
	$(CC) -o $@ $<

$(BIN)/4-3-streamio.out: 4-3-stream-io.cpp
	$(CC) -o $@ $<

$(BIN)/4-4-1-vector.out: 4-4-containers-1-vector.cpp
	$(CC) -o $@ $<

$(BIN)/4-4-1-2-range-check.out: 4-4-containers-1-vector-2-range-checking.cpp
	$(CC) -o $@ $<

$(BIN)/4-4-2-list.out: 4-4-containers-2-list.cpp
	$(CC) -o $@ $<

$(BIN)/4-4-3-map.out: 4-4-containers-3-map.cpp
	$(CC) -o $@ $<

$(BIN)/4-4-4-unordered-map.out: 4-4-containers-4-unordered-map.cpp
	$(CC) -o $@ $<

$(BIN)/4-5-algorithms.out: 4-5-algorithms.cpp
	$(CC) -o $@ $<

$(BIN)/4-5-1-find-all.out: 4-5-algorithms-1-use-of-iterators.cpp
	$(CC) -o $@ $<

$(BIN)/4-5-3-io-iterators.out: 4-5-algorithms-3-stream-iterators.cpp
	$(CC) -o $@ $<

$(BIN)/4-5-4-predicates.out: 4-5-algorithms-4-predicates.cpp
	$(CC) -o $@ $<

$(BIN)/4-5-6-sort.out: 4-5-algorithms-6-container-algorithms.cpp
	$(CC) -o $@ $<


clean:
	$(RM) $(BIN)/*.out
