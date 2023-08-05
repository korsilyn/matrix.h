CC = gcc
#CC = clang
CFLAGS = -Wall -Wextra -Werror -std=c11
#CFLAGS += -O2 -march=native -pipe
TESTSFLAGS = -lcheck
ifeq ($(shell uname), Linux)
    TESTSFLAGS += -lpthread -lrt -lm -lsubunit
endif

SOURCES = $(wildcard *.c)
OBJECTS = $(addprefix obj/,$(SOURCES:.c=.o))
LIBNAME = s21_matrix.a
TESTS = s21_matrix_test.c
TESTSOBJ = $(addprefix obj/,$(TESTS:.c=.o))
TESTSSRC = $(addprefix tests/,$(TESTS))

all: test

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBNAME): $(OBJECTS)
	ar rc $@ $^
	ranlib $@

$(TESTSOBJ): $(TESTSSRC)
	$(CC) $(CFLAGS) -c $^ -o $@

test: $(TESTSOBJ) $(LIBNAME)
	$(CC) $(CFLAGS) $(TESTSFLAGS) $^ -o $@
	./$@

gcov_report: $(TESTSSRC) $(SOURCES)
	$(CC) $(CFLAGS) $(TESTSFLAGS) --coverage $^ -o $@
	-./$@
	lcov -t $@ -o $@.info -c -d .
	genhtml -o report $@.info
	open ./report/index.html

style:
	-clang-format -i --style=Google *.c *.h */*.c */*.h

rebuild: clean all

clean:
	rm -rf */*.o report test gcov_report *.a *.gcda *gcno *.gcov *.info

