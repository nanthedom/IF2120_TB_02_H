CC = gcc
CFLAGS = -Wall -Werror -std=c11

# SRC dan OBJ file
SRC_MAIN = main.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

SRC_TIME = ADT/time/time.c
SRC_DATETIME = ADT/datetime/datetime.c
SRC_CHAR = ADT/charmachine/charmachine.c
SRC_WORD = ADT/wordmachine/wordmachine.c
SRC_STACK = ADT/stack/stack.c
SRC_QUEUE = ADT/queue/queue.c
SRC_PRIO = ADT/prioqueue/prioqueuechar.c
SRC_PCOLOR = ADT/pcolor/pcolor.c
SRC_MATRIX = ADT/matrix/matrix.c
SRC_LISTSTAT = ADT/liststatik/liststatik.c
SRC_LISTLIN = ADT/listlinier/listlinier.c
SRC_LISTDIN = ADT/listdin/listdin.c


SRC_KICAU = features/kicau/kicau.c
SRC_PENGGUNA = features/pengguna/pengguna.c
SRC_DRAF = features/draf/draf.c
SRC_TEMAN = features/teman/teman.c
SRC_INIT = features/inisialisasi/inisialisasi.c
SRC_PROFIL = features/profil/profil.c

OBJ_TIME = $(SRC_TIME:.c=.o)
OBJ_DATETIME = $(SRC_DATETIME:.c=.o)
OBJ_CHAR = $(SRC_CHAR:.c=.o)
OBJ_WORD = $(SRC_WORD:.c=.o)
OBJ_STACK = $(SRC_STACK:.c=.o)
OBJ_QUEUE = $(SRC_QUEUE:.c=.o)
OBJ_PRIO = $(SRC_PRIO:.c=.o)
OBJ_PCOLOR = $(SRC_PCOLOR:.c=.o)
OBJ_MATRIX = $(SRC_MATRIX:.c=.o)
OBJ_LISTST = $(SRC_LISTSTAT:.c=.o)
OBJ_LISTLIN = $(SRC_LISTLIN:.c=.o)
OBJ_LISTDIN = $(SRC_LISTDIN:.c=.o)


OBJ_KICAU = $(SRC_KICAU:.c=.o)
OBJ_PENGGUNA = $(SRC_PENGGUNA:.c=.o)
OBJ_DRAF = $(SRC_DRAF:.c=.o)
OBJ_TEMAN = $(SRC_TEMAN:.c=.o)
OBJ_INIT = $(SRC_INIT:.c=.o)
OBJ_PROFIL = $(SRC_PROFIL:.c=.o)


all: main_program

build :
	$(MAKE) main_program

run :
	./main_program



%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program mword test_dt test_stack $(OBJ_MAIN) $(OBJ_WORD) $(OBJ_TEST) $(TEST_RESULTS) $(STDOUT)

# UNIT TESTS

# DATETIME
SRC_TEST_DT = ADT/datetime/tests/testdt.c
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
SRC_TEST_WORD = ADT/wordmachine/tests/mword.c
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

# STACK
SRC_TEST_ST = ADT/stack/tests/testStack.c
OBJ_TEST_ST = $(SRC_TEST_ST:.c=.o)

TESTS_DIR_ST = ADT/stack/tests
TEST_CASES_ST = $(wildcard $(TESTS_DIR_ST)/*.in)
TEST_OUTPUTS_ST = $(TEST_CASES_ST:.in=.out)
TEST_RESULTS_ST = $(TEST_CASES_ST:.in=.result)

testStack: $(OBJ_STACK) $(OBJ_TEST_ST) 
	$(CC) $(CFLAGS) -o $@ $^


test_stack: testStack $(TEST_RESULTS_ST)
	@cat $(TEST_RESULTS_ST)

$(TEST_RESULTS_ST): $(TESTS_DIR_ST)/%.result: $(TESTS_DIR_ST)/%.in $(TESTS_DIR_ST)/%.out testStack
	@if ./testStack < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@






STDOUT = $(addprefix stdout_,$(notdir $(TEST_CASES:.in=.txt)))



create_stdout: $(STDOUT)

$(STDOUT): stdout_%.txt: $(TESTS_DIR)/%.in $(file)
	@./mword < $< | tr '\r' '\n' > $@

main_program: $(OBJ_MAIN) $(OBJ_WORD) $(OBJ_CHAR) $(OBJ_TIME) $(OBJ_DATETIME) $(OBJ_PRIO) $(OBJ_PCOLOR)  $(OBJ_LISTLIN) $(OBJ_PROFIL) $(OBJ_INIT) $(OBJ_KICAU) $(OBJ_PENGGUNA) $(OBJ_DRAF) $(OBJ_TEMAN)
	$(CC) $(CFLAGS) -o $@ $^