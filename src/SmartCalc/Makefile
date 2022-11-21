WWW = -std=c++17 -Wall -Werror -Wextra -lstdc++
LINUX=-lsubunit -lrt -lpthread -lm
LFLAGS=-fprofile-arcs -ftest-coverage
LIBS=-lgtest -lgmock -pthread
OS=$(shell uname -s)

all: clean test

rebuild: clean all 

test: clean s21_smartcalc_oop.a
ifeq ($(OS), Darwin)
	gcc $(WWW) tests.cc s21_smartcalc_oop.a -o test $(LIBS)
else
	gcc $(WWW) tests.cc s21_smartcalc_oop.a -o test $(LIBS) $(LINUX)
endif
	./test

gcov_report: clean_test
ifeq ($(OS), Darwin)
	gcc $(WWW) --coverage tests.cc Controller/Controller.cc Model/Model.cc -o test $(LIBS)
else
	gcc $(WWW) --coverage tests.cc Controller/Controller.cc Model/Model.cc -o test $(LIBS) $(LINUX)
endif
	./test
	lcov -t "test" -o test.info --no-external -c -d .
	genhtml -o report test.info
	open report/index.html
	rm -rf a.out

s21_smartcalc_oop.a: build_s21_smartcalc_oop

dvi:
	open View/dvi.html

dist:
	tar -cf ../build/dist.tar ../build/SmartCalc.app


install:
	cd View && qmake && make && make clean && rm Makefile && cd ../ && mkdir build && mv View/SmartCalc.app build/

uninstall:
	rm -rf build

build_s21_smartcalc_oop:
	gcc -c Controller/Controller.cc Model/Model.cc
	# gcc -c Controller/Controller.cc Model/Model.cc tests.cc
	ar rcs s21_smartcalc_oop.a  Controller.o Model.o
	ranlib s21_smartcalc_oop.a

clean_obj:
	rm -rf *.o

clean_lib: 
	rm -rf *.a

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report
	rm -rf build

clean: clean_lib clean_test clean_obj