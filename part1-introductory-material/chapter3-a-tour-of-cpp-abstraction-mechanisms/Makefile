CC=g++ -std=c++11
BIN=bin

default:
	echo "Chapter 3. A Tour of C++: Abstraction Mechanisms"

3-2-1-complex: $(BIN)/3-2-1-complex.out
	./$<

3-2-2-containers: $(BIN)/3-2-2-containers.out
	./$<

3-4-1-vector: $(BIN)/3-4-1-vector.out
	./$<

3-4-2-sum: $(BIN)/3-4-2-sum.out
	./$<

3-4-3-functor: $(BIN)/3-4-3-functor.out
	./$<

3-4-4-printf: $(BIN)/3-4-4-printf.out
	./$<


$(BIN)/3-2-1-complex.out: 3-2-classes-1-concrete-types-1-an-arithmetic-type.cpp
	$(CC) -o $@ $<

$(BIN)/3-2-2-containers.out: 3-2-classes-2-abstract-types.cpp
	$(CC) -o $@ $<

$(BIN)/3-4-1-vector.out: 3-4-templates-1-parameterized-types.cpp
	$(CC) -o $@ $<

$(BIN)/3-4-2-sum.out: 3-4-templates-2-function-templates.cpp
	$(CC) -o $@ $<

$(BIN)/3-4-3-functor.out: 3-4-templates-3-function-objects.cpp
	$(CC) -o $@ $<

$(BIN)/3-4-4-printf.out: 3-4-templates-4-variadic-templates.cpp
	$(CC) -o $@ $<


clean:
	$(RM) $(BIN)/*.o $(BIN)/*.out
