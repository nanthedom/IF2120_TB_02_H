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
SRC_GRAF = ADT/graf/graf.c
SRC_TREE = ADT/tree/tree.c


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
SRC_SIMPAN = features/simpan/simpan.c

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
OBJ_GRAF = $(SRC_GRAF:.c=.o)
OBJ_TREE = $(SRC_TREE:.c=.o)

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
OBJ_SIMPAN = $(SRC_SIMPAN:.c=.o)


all: main_program

build :
	$(MAKE) main_program

run :
	./main_program



%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program mword mqueue test_dt test_stack test_queue test_statik mchar *.o */*/*.o

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

# CHAR
SRC_TEST_CHAR = ADT/charmachine/tests/mchar.c
OBJ_TEST_CHAR = $(SRC_TEST_CHAR:.c=.o)

TESTS_DIR_CHAR = ADT/charmachine/tests
TEST_CASES_CHAR = $(wildcard $(TESTS_DIR_CHAR)/*.in)
TEST_OUTPUTS_CHAR = $(TEST_CASES_CHAR:.in=.out)
TEST_RESULTS_CHAR = $(TEST_CASES_CHAR:.in=.result)

mchar: $(OBJ_CHAR) $(OBJ_TEST_CHAR)
	$(CC) $(CFLAGS) -o $@ $^
test_char: mchar $(TEST_RESULTS_CHAR)
	@cat $(TEST_RESULTS_CHAR)
	
$(TEST_RESULTS_CHAR): $(TESTS_DIR_CHAR)/%.result: $(TESTS_DIR_CHAR)/%.in $(TESTS_DIR_CHAR)/%.out mchar
	@if ./mchar < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
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
SRC_TEST_PQ = ADT/prioqueue/tests/mprioqueue.c
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

# MATRIX
SRC_TEST_MAT = ADT/matrix/tests/mmatrix.c
OBJ_TEST_MAT = $(SRC_TEST_MAT:.c=.o)

TESTS_DIR_MAT = ADT/matrix/tests
TEST_CASES_MAT = $(wildcard $(TESTS_DIR_MAT)/*.in)
TEST_OUTPUTS_MAT = $(TEST_CASES_MAT:.in=.out)
TEST_RESULTS_MAT = $(TEST_CASES_MAT:.in=.result)

testMatrix: $(OBJ_MATRIX) $(OBJ_TEST_MAT) 
	$(CC) $(CFLAGS) -o $@ $^


test_matrix: testMatrix $(TEST_RESULTS_MAT)
	@cat $(TEST_RESULTS_MAT)

$(TEST_RESULTS_MAT): $(TESTS_DIR_MAT)/%.result: $(TESTS_DIR_MAT)/%.in $(TESTS_DIR_MAT)/%.out testMatrix
	@if ./testMatrix < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# GRAF
SRC_TEST_GRAF = ADT/graf/tests/mgraf.c
OBJ_TEST_GRAF = $(SRC_TEST_GRAF:.c=.o)

TESTS_DIR_GRAF = ADT/graf/tests
TEST_CASES_GRAF = $(wildcard $(TESTS_DIR_GRAF)/*.in)
TEST_OUTPUTS_GRAF = $(TEST_CASES_GRAF:.in=.out)
TEST_RESULTS_GRAF = $(TEST_CASES_GRAF:.in=.result)

testGraf: $(OBJ_GRAF) $(OBJ_TEST_GRAF) 
	$(CC) $(CFLAGS) -o $@ $^


test_graf: testGraf $(TEST_RESULTS_GRAF)
	@cat $(TEST_RESULTS_GRAF)

$(TEST_RESULTS_GRAF): $(TESTS_DIR_GRAF)/%.result: $(TESTS_DIR_GRAF)/%.in $(TESTS_DIR_GRAF)/%.out testGraf
	@if ./testGraf < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# TIME
SRC_TEST_T = ADT/time/tests/mtime.c
OBJ_TEST_T = $(SRC_TEST_T:.c=.o)

TESTS_DIR_T = ADT/time/tests
TEST_CASES_T = $(wildcard $(TESTS_DIR_T)/*.in)
TEST_OUTPUTS_T = $(TEST_CASES_T:.in=.out)
TEST_RESULTS_T = $(TEST_CASES_T:.in=.result)

testTime: $(OBJ_TIME) $(OBJ_TEST_T)
	$(CC) $(CFLAGS) -o $@ $^


test_time: testTime $(TEST_RESULTS_T)
	@cat $(TEST_RESULTS_T)

$(TEST_RESULTS_T): $(TESTS_DIR_T)/%.result: $(TESTS_DIR_T)/%.in $(TESTS_DIR_T)/%.out testTime
	@if ./testTime < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# LISTDIN
SRC_TEST_LD = ADT/listdin/tests/mlistdin.c
OBJ_TEST_LD = $(SRC_TEST_LD:.c=.o)

TESTS_DIR_LD = ADT/listdin/tests
TEST_CASES_LD = $(wildcard $(TESTS_DIR_LD)/*.in)
TEST_OUTPUTS_LD = $(TEST_CASES_LD:.in=.out)
TEST_RESULTS_LD = $(TEST_CASES_LD:.in=.result)

testLD: $(OBJ_LISTDIN) $(OBJ_TEST_LD)
	$(CC) $(CFLAGS) -o $@ $^


test_ld: testLD $(TEST_RESULTS_LD)
	@cat $(TEST_RESULTS_LD)

$(TEST_RESULTS_LD): $(TESTS_DIR_LD)/%.result: $(TESTS_DIR_LD)/%.in $(TESTS_DIR_LD)/%.out testLD
	@if ./testLD < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# LISTLINIER
SRC_TEST_LL = ADT/listlinier/tests/mlistlinier.c
OBJ_TEST_LL = $(SRC_TEST_LL:.c=.o)

TESTS_DIR_LL = ADT/listlinier/tests
TEST_CASES_LL = $(wildcard $(TESTS_DIR_LL)/*.in)
TEST_OUTPUTS_LL = $(TEST_CASES_LL:.in=.out)
TEST_RESULTS_LL = $(TEST_CASES_LL:.in=.result)

testLL: $(OBJ_LISTLIN) $(OBJ_TEST_LL)
	$(CC) $(CFLAGS) -o $@ $^


test_ll: testLL $(TEST_RESULTS_LL)
	@cat $(TEST_RESULTS_LL)

$(TEST_RESULTS_LL): $(TESTS_DIR_LL)/%.result: $(TESTS_DIR_LL)/%.in $(TESTS_DIR_LL)/%.out testLL
	@if ./testLL < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# TREE
SRC_TEST_TREE = ADT/tree/tests/mtree.c
OBJ_TEST_TREE = $(SRC_TEST_TREE:.c=.o)

TESTS_DIR_TREE = ADT/tree/tests
TEST_CASES_TREE = $(wildcard $(TESTS_DIR_TREE)/*.in)
TEST_OUTPUTS_TREE = $(TEST_CASES_TREE:.in=.out)
TEST_RESULTS_TREE = $(TEST_CASES_TREE:.in=.result)

mtree: $(OBJ_TREE) $(OBJ_TEST_TREE) 
	$(CC) $(CFLAGS) -o $@ $^


test_tree: mtree $(TEST_RESULTS_TREE)
	@cat $(TEST_RESULTS_TREE)

$(TEST_RESULTS_TREE): $(TESTS_DIR_TREE)/%.result: $(TESTS_DIR_TREE)/%.in $(TESTS_DIR_TREE)/%.out mtree
	@if ./mtree < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

STDOUT = $(addprefix stdout_,$(notdir $(TEST_CASES_LD:.in=.txt)))



create_stdout: $(STDOUT)

$(STDOUT): stdout_%.txt: $(TESTS_DIR_LD)/%.in testLD
	@./testLD < $(word 1, $^) | tr '\r' '\n' > $@

main_program: $(OBJ_MAIN) $(OBJ_WORD) $(OBJ_CHAR) $(OBJ_TIME) $(OBJ_DATETIME) $(OBJ_PRIO) $(OBJ_PCOLOR) $(OBJ_MATRIX) $(OBJ_LISTLIN) $(OBJ_GRAF) $(OBJ_PROFIL) $(OBJ_INIT) $(OBJ_KICAU) $(OBJ_PENGGUNA) $(OBJ_DRAF) $(OBJ_TEMAN) $(OBJ_PERMINTAAN) $(OBJ_BALASAN) $(OBJ_MUAT) $(OBJ_UTAS) $(OBJ_SIMPAN)
	$(CC) $(CFLAGS) -o $@ $^