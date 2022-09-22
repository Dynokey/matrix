CC=gcc
CFLAGS= -Wall -Werror -Wextra -std=c11 -pedantic -g #-fsanitize=address 
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS=-lcheck -lm -lpthread
ALL_FLAGS=$(CFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS)

SRCS = s21_create_matrix.c\
	s21_remove_matrix.c\
	s21_eq_matrix.c\
	s21_sum_matrix.c\
	s21_sub_matrix.c\
	s21_mult_number.c\
	s21_mult_matrix.c\
	s21_transpose.c\
	s21_determinant.c\
	s21_calc_complements.c\
	s21_inverse_matrix.c\
	get_minor.c\
	err_matrix.c\
	fill_in_matrix.c\
	determinant_1.c\
	determinant_2.c\
	determinant_3.c\
	determinant_n.c

OBJS = $(SRCS:.c=.o)
OBJST = $(OBJS) s21_matrix_test.c
NAME = test
REPORT_NAME = report

all: objs s21_matrix.a

leaks:
	CK_FORK=no leaks --atExit -- ./test

test: $(OBJST)
	$(CC) $(CHECK_FLAGS) $(OBJS) s21_matrix_test.c -o $(NAME)
	./test

# valgrind:
# 	rm -rf s21_matrix.a
# 	gcc -Wall -Werror -Wextra -g s21_grep.c s21_grep.h -o s21_grep
# 	cp ../../data-samples/text.txt text.txt
# 	valgrind --dsymutil=yes --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out_i.txt ./s21_grep


clean:
	@rm -rf *.o
	@rm -rf *.out
	@rm -rf *.dSYM
	@rm -rf *.gcno
	@rm -rf *.gcda
	@rm -rf *.info
	@rm -rf *.a
	@rm -rf main
	@rm -rf $(REPORT_NAME)
	@rm -rf *.log
	@rm -rf test
	@rm -rf CPPLINT.cfg
	@rm -rf cpplint.py


objs: $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) 

s21_matrix.a: $(OBJS)
	ar rc s21_matrix.a $(OBJS)
	ranlib s21_matrix.a
	
check:
	cppcheck *.h *.c
	cp ./../materials/linters/cpplint.py ./cpplint.py
	cp ./../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
	python3 cpplint.py --extension=c *.c *.h

gcov_report:
	$(CC) -o $(NAME) $(SRCS) s21_matrix_test.c $(GCOV_FLAGS) $(CHECK_FLAGS)
	./$(NAME)
	lcov -t "gcov_report" -o tests.info -c -d .
	genhtml -o $(REPORT_NAME) tests.info
	open report/index.html
	rm $(NAME)
	rm -rf *.gcno
	rm -rf *.gcda
