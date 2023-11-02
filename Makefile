CC = gcc
CFLAGS = -Wall -Werror -std=c11

SRC_MAIN = main.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

all: main_program

build :
	main_program

run :
	./main_program

main_program: $(OBJ_MAIN) $(OBJ_WORD) 
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program mword $(OBJ_MAIN) $(OBJ_WORD) $(OBJ_TEST) $(TEST_RESULTS) $(STDOUT)

# UNIT TESTS

# DATETIME
SRC_TIME = ADT/time/time.c
SRC_DATETIME = ADT/datetime/datetime.c
SRC_TEST_DT = ADT/datetime/tests/testdt.c
OBJ_TIME = $(SRC_TIME:.c=.o)
OBJ_DATETIME = $(SRC_DATETIME:.c=.o)
OBJ_TEST_DT = $(SRC_TEST_DT:.c=.o)

TESTS_DIR_DT = ADT/datetime/tests
TEST_CASES_DT = $(wildcard $(TESTS_DIR_DT)/*.in)
TEST_OUTPUTS_DT = $(TEST_CASES_DT:.in=.out)
TEST_RESULTS_DT = $(TEST_CASES_DT:.in=.result)

testdt: $(OBJ_TIME) $(OBJ_DATETIME) $(OBJ_TEST_DT) 
	$(CC) $(CFLAGS) -o $@ $^


test_dt: testdt $(TEST_RESULTS_DT)
	@cat $(TEST_RESULTS_DT)

$(TEST_RESULTS_DT): $(TESTS_DIR_DT)/%.result: $(TESTS_DIR_DT)/%.in $(TESTS_DIR_DT)/%.out testdt
	@if ./testdt < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# WORD
SRC_CHAR = ADT/charmachine/charmachine.c
SRC_WORD = ADT/wordmachine/wordmachine.c
SRC_TEST_WORD = ADT/wordmachine/tests/mword.c
OBJ_CHAR = $(SRC_CHAR:.c=.o)
OBJ_WORD = $(SRC_WORD:.c=.o)
OBJ_TEST_WORD = $(SRC_TEST_WORD:.c=.o)

TESTS_DIR_WORD = ADT/wordmachine/tests
TEST_CASES_WORD = $(wildcard $(TESTS_DIR_WORD)/*.in)
TEST_OUTPUTS_WORD = $(TEST_CASES_WORD:.in=.out)
TEST_RESULTS_WORD = $(TEST_CASES_WORD:.in=.result)

mword: $(OBJ_WORD) $(OBJ_CHAR) $(OBJ_TEST_WORD)
	$(CC) $(CFLAGS) -o $@ $^
test_word: mword $(TEST_RESULTS_WORD)
	@cat $(TEST_RESULTS_WORD)
	
$(TEST_RESULTS_WORD): $(TESTS_DIR_WORD)/%.result: $(TESTS_DIR_WORD)/%.in $(TESTS_DIR_WORD)/%.out mword
	@if ./mword < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@



STDOUT = $(addprefix stdout_,$(notdir $(TEST_CASES:.in=.txt)))



create_stdout: $(STDOUT)

$(STDOUT): stdout_%.txt: $(TESTS_DIR)/%.in $(file)
	@./mword < $< | tr '\r' '\n' > $@
