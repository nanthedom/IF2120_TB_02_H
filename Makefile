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


SRC_TIME = ADT/time/time.c
SRC_DATETIME = ADT/datetime/datetime.c
SRC_TEST_DT = ADT/datetime/tests/testdt.c
OBJ_TIME = $(SRC_TIME:.c=.o)
OBJ_DATETIME = $(SRC_DATETIME:.c=.o)
OBJ_TEST_DT = $(SRC_TEST_DT:.c=.o)


SRC_CHAR = ADT/charmachine/charmachine.c
SRC_WORD = ADT/wordmachine/wordmachine.c
SRC_TEST_WORD = ADT/wordmachine/tests/mword.c
OBJ_CHAR = $(SRC_CHAR:.c=.o)
OBJ_WORD = $(SRC_WORD:.c=.o)
OBJ_TEST_WORD = $(SRC_TEST_WORD:.c=.o)


TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)
STDOUT = $(addprefix stdout_,$(notdir $(TEST_CASES:.in=.txt)))

testdt: $(OBJ_TIME) $(OBJ_DATETIME) $(OBJ_TEST_DT) 
	$(CC) $(CFLAGS) -o $@ $^

test_dt: TESTS_DIR = ADT/datetime/tests
	file = testdt
test_dt: testdt $(TEST_RESULTS)
	@cat $(TEST_RESULTS)
	

mword: $(OBJ_WORD) $(OBJ_CHAR) $(OBJ_TEST_WORD)
	$(CC) $(CFLAGS) -o $@ $^
test_word: TESTS_DIR = ADT/wordmachine/tests
	file = mword
test_word: mword $(TEST_RESULTS)
	@cat $(TEST_RESULTS)
	

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out $(file)
	@if ./mword < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

create_stdout: $(STDOUT)

$(STDOUT): stdout_%.txt: $(TESTS_DIR)/%.in $(file)
	@./mword < $< | tr '\r' '\n' > $@

