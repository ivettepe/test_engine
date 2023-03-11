FLAGS=g++ -Wall -Werror -Wextra

all: test_stand clean

test_stand: data_io.o engine_model.o engines.o
	${FLAGS} data_io.o engine_model.o engines.o -o test_stand

data_io.o: data_io.h test_stand.h data_io.cpp
	${FLAGS} -c data_io.cpp

engine_model.o: data_io.h test_stand.h engine_model.cpp
	${FLAGS} -c engine_model.cpp

engines.o: engines.h engines.cpp
	${FLAGS} -c engines.cpp

clean:
	-del *.o

build: 
	make test_stand

rebuild: 
	make clean
	make build