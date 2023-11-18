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
SRC_PRIO = ADT/prioqueue/prioqueue.c
SRC_PCOLOR = ADT/pcolor/pcolor.c
SRC_MATRIX = ADT/matrix/matrix.c
SRC_LISTSTAT = ADT/liststatik/liststatik.c
SRC_LISTLIN = ADT/listlinier/listlinier.c
SRC_LISTDIN = ADT/listdin/listdin.c


SRC_KICAU = features/kicau/kicau.c
SRC_PENGGUNA = features/pengguna/pengguna.c
SRC_DRAF = features/draf/draf.c
SRC_TEMAN = features/teman/teman.c
SRC_PERMINTAAN = features/permintaan/permintaan.c
SRC_INIT = features/inisialisasi/inisialisasi.c
SRC_PROFIL = features/profil/profil.c
SRC_BALASAN = features/balasan/balasan.c
SRC_MUAT = features/muat/muat.c
SRC_UTAS = features/utas/utas.c

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
OBJ_PERMINTAAN = $(SRC_PERMINTAAN:.c=.o)
OBJ_INIT = $(SRC_INIT:.c=.o)
OBJ_PROFIL = $(SRC_PROFIL:.c=.o)
OBJ_BALASAN = $(SRC_BALASAN:.c=.o)
OBJ_MUAT = $(SRC_MUAT:.c=.o)
OBJ_UTAS = $(SRC_UTAS:.c=.o)


all: main_program

build :
	$(MAKE) main_program

run :
	./main_program



%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program mword mqueue test_dt test_stack test_queue $(OBJ_MAIN) $(OBJ_WORD) $(OBJ_TEST) $(TEST_RESULTS) $(STDOUT)

# UNIT TESTS

# DATETIME
SRC_TEST_DT = ADT/datetime/tests/testdt.c
OBJ_TEST_DT = $(SRC_TEST_DT:.c=.o)

TESTS_DIR_DT = ADT/datetime/tests
TEST_CASES_DT = $(wildcard $(TESTS_DIR_DT)/*.in)
TEST_OUTPUTS_DT = $(TEST_CASES_DT:.in=.out)
TEST_RESULTS_DT = $(TEST_CASES_DT:.in=.result)

testdt: $(OBJ_TIME) $(OBJ_WORD) $(OBJ_CHAR) $(OBJ_DATETIME) $(OBJ_TEST_DT) 
	$(CC) $(CFLAGS) -o $@ $^


test_dt: testdt $(TEST_RESULTS_DT)
	@cat $(TEST_RESULTS_DT)

$(TEST_RESULTS_DT): $(TESTS_DIR_DT)/%.result: $(TESTS_DIR_DT)/%.in $(TESTS_DIR_DT)/%.out testdt
	@if ./testdt < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# LISTSTATIK
SRC_TEST_LS = ADT/liststatik/tests/mstatik.c
OBJ_TEST_LS = $(SRC_TEST_LS:.c=.o)

TESTS_DIR_LS = ADT/liststatik/tests
TEST_CASES_LS = $(wildcard $(TESTS_DIR_LS)/*.in)
TEST_OUTPUTS_LS = $(TEST_CASES_LS:.in=.out)
TEST_RESULTS_LS = $(TEST_CASES_LS:.in=.result)

mstatik: $(OBJ_LISTST) $(OBJ_TEST_LS)
	$(CC) $(CFLAGS) -o $@ $^
test_statik: mstatik $(TEST_RESULTS_LS)
	@cat $(TEST_RESULTS_LS)
	
$(TEST_RESULTS_LS): $(TESTS_DIR_LS)/%.result: $(TESTS_DIR_LS)/%.in $(TESTS_DIR_LS)/%.out mstatik
	@if ./mstatik < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
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

# QUEUE
SRC_TEST_Q = ADT/queue/tests/mqueue.c
OBJ_TEST_Q = $(SRC_TEST_Q:.c=.o)

TESTS_DIR_Q = ADT/queue/tests
TEST_CASES_Q = $(wildcard $(TESTS_DIR_Q)/*.in)
TEST_OUTPUTS_Q = $(TEST_CASES_Q:.in=.out)
TEST_RESULTS_Q = $(TEST_CASES_Q:.in=.result)

testQueue: $(OBJ_QUEUE) $(OBJ_TEST_Q) 
	$(CC) $(CFLAGS) -o $@ $^


test_queue: testQueue $(TEST_RESULTS_Q)
	@cat $(TEST_RESULTS_Q)

$(TEST_RESULTS_Q): $(TESTS_DIR_Q)/%.result: $(TESTS_DIR_Q)/%.in $(TESTS_DIR_Q)/%.out testQueue
	@if ./testQueue < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# PRIOQUEUE
SRC_TEST_PQ = ADT/prioqueue/tests/mqueue.c
OBJ_TEST_PQ = $(SRC_TEST_PQ:.c=.o)

TESTS_DIR_PQ = ADT/prioqueue/tests
TEST_CASES_PQ = $(wildcard $(TESTS_DIR_PQ)/*.in)
TEST_OUTPUTS_PQ = $(TEST_CASES_PQ:.in=.out)
TEST_RESULTS_PQ = $(TEST_CASES_PQ:.in=.result)

testprioQueue: $(OBJ_PRIO) $(OBJ_TEST_PQ) 
	$(CC) $(CFLAGS) -o $@ $^


test_prioqueue: testprioQueue $(TEST_RESULTS_PQ)
	@cat $(TEST_RESULTS_PQ)

$(TEST_RESULTS_PQ): $(TESTS_DIR_PQ)/%.result: $(TESTS_DIR_PQ)/%.in $(TESTS_DIR_PQ)/%.out testprioQueue
	@if ./testprioQueue < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# PCOLOR
SRC_TEST_PC = ADT/pcolor/tests/mcolor.c
OBJ_TEST_PC = $(SRC_TEST_PC:.c=.o)

TESTS_DIR_PC = ADT/pcolor/tests
TEST_CASES_PC = $(wildcard $(TESTS_DIR_PC)/*.in)
TEST_OUTPUTS_PC = $(TEST_CASES_PC:.in=.out)
TEST_RESULTS_PC = $(TEST_CASES_PC:.in=.result)

testpcolor: $(OBJ_PCOLOR) $(OBJ_TEST_PC) 
	$(CC) $(CFLAGS) -o $@ $^


test_pcolor: testpcolor $(TEST_RESULTS_PC)
	@cat $(TEST_RESULTS_PC)

$(TEST_RESULTS_PC): $(TESTS_DIR_PC)/%.result: $(TESTS_DIR_PC)/%.in $(TESTS_DIR_PC)/%.out testpcolor
	@if ./testpcolor < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@






STDOUT = $(addprefix stdout_,$(notdir $(TEST_CASES_PC:.in=.txt)))



create_stdout: $(STDOUT)

$(STDOUT): stdout_%.txt: $(TESTS_DIR_PC)/%.in testpcolor
	@./testpcolor < $(word 1, $^) | tr '\r' '\n' > $@

main_program: $(OBJ_MAIN) $(OBJ_WORD) $(OBJ_CHAR) $(OBJ_TIME) $(OBJ_DATETIME) $(OBJ_PRIO) $(OBJ_PCOLOR) $(OBJ_MATRIX) $(OBJ_LISTLIN) $(OBJ_PROFIL) $(OBJ_INIT) $(OBJ_KICAU) $(OBJ_PENGGUNA) $(OBJ_DRAF) $(OBJ_TEMAN) $(OBJ_PERMINTAAN) $(OBJ_BALASAN) $(OBJ_MUAT) $(OBJ_UTAS)
	$(CC) $(CFLAGS) -o $@ $^