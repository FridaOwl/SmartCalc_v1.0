.PHONY: all test gcov_report clean valgrind_check leaks style
CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11
GCOV = -fprofile-arcs -ftest-coverage
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
TARGET = SmartCalc
TEST_LIBS = -lcheck -lm -lpthread -lsubunit -L
DESTDIR = calc
SRC_BACKEND = $(wildcard backend/*.c)
OBJ_BACKEND = $(SRC_BACKEND:.c=.o)
SRCS=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o, ${SRC})

OS := $(shell uname -s)

ifeq ($(OS),Linux)
  OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

TEST_SRC=$(wildcard ./test//*.c)
LIBS=-lcheck

all: calculator test gcov_report install

calculator: calculator.a
	$(CC) test/test.c -lcheck -L. calculator.a -o calculator

calculator.a: $(SRC_BACKEND)
	$(CC) -c $(FLAGS) $(SRC_BACKEND)
	ar rcs calculator.a $(OBJS)
	ranlib calculator.a

install:
	@mkdir -p $(DESTDIR)
	qmake -o $(DESTDIR)/Makefile frontend/$(TARGET).pro
	cd $(DESTDIR) && make INSTALL_ROOT=../src/$(DESTDIR)


start: install
ifeq ($(OS), Darwin)
	cd $(DESTDIR)/$(TARGET).app/Contents/MacOS && ./$(TARGET)
endif
ifeq ($(OS), Linux)
	cd $(DESTDIR) && ./$(TARGET)
endif

uninstall: clean
	rm -rf $(DESTDIR)

dist: install 
	tar -czf $(TARGET).tgz src

dvi:
	open README.md

test : calculator.a
ifeq ($(OS), Darwin)
	${CC} $(FLAGS) test/test.c $(SRC_BACKEND) $< -o calc_test $(LIBS) -lm
else
	${CC} $(FLAGS) test/test.c $(SRC_BACKEND) $< -o calc_test $(LIBS) $(LINUX_FLAGS)
endif
	./calc_test

clean:
	rm -rf *.a backend/*.o frontend/*.o  *.o *.info *.gcno *.gcda *.gcov
	rm -rf report
	rm -rf calc_test
	rm -rf calculator

gcov_report:
ifeq ($(OS), Darwin)
	$(CC) $(FLAGS) $(GCOV) test/test.c $(SRC_BACKEND) ${SRC}  -o calc_test $(LIBS) -lm
else
	$(CC) $(FLAGS) $(GCOV) test/test.c $(SRC_BACKEND) ${SRC} -o calc_test $(LIBS) $(LINUX_FLAGS)
endif
	./calc_test
	lcov -t "calc_test" -o calc_test.info -c -d .
	lcov --remove calc_test.info "*/extern/*" -o calc_test_filtered.info

	genhtml -o report calc_test.info
	$(OPEN_CMD) ./report/index.html

valgrind_check: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./calc_test

leak: test
	CK_FORK=no leaks -atExit -- ./calc_test

style:
	cp ../materials/linters/.clang-format ./
	clang-format -n backend/*.c backend/*.h
	clang-format -n test/test.c

rebuild:
	$(MAKE) clean
	$(MAKE) all
