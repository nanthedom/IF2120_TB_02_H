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
SRC_CHAR = ADT/charmachine/charmachine.c
OBJ_CHAR = $(SRC_CHAR:.c=.o)
SRC_WORD = ADT/wordmachine/wordmachine.c
SRC_TEST = ADT/wordmachine/tests/mword.c
OBJ_WORD = $(SRC_WORD:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)
TESTS_DIR = ADT/wordmachine/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)
STDOUT = $(addprefix stdout_,$(notdir $(TEST_CASES:.in=.txt)))

mword: $(OBJ_WORD) $(OBJ_CHAR) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_word: mword $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mword
	@if ./mword < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): FALSE"; \
	fi > $@

create_stdout: $(STDOUT)

$(STDOUT): stdout_%.txt: $(TESTS_DIR)/%.in mword
	@./mword < $< | tr '\r' '\n' > $@

