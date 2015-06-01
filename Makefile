CFLAGS=-I /usr/local/Cellar/gmp/6.0.0a/include/
LFLAGS=-L/usr/local/Cellar/gmp/6.0.0a/lib/

.PHONY: lib example run

lib: cryptoLib.cpp cryptoLib.h mpz2_class.cpp mpz2_class.h
	# ================= Build cryptoLib =================
	mkdir -p ./bin
	clang++ -c mpz2_class.cpp -o ./bin/mpz2_class.o $(CFLAGS)
	clang++ -c cryptoLib.cpp -o ./bin/cryptoLib.o $(CFLAGS)
example:
	# ================ Build example $(src) ================
	clang++ -c examples/$(src).cpp -o ./bin/$(src).o $(CFLAGS)
	clang++ -o ./bin/$(src) ./bin/mpz2_class.o ./bin/cryptoLib.o ./bin/$(src).o $(LFLAGS) -lgmp -lgmpxx
run:
	# ===================== Run $(src) =====================
	./bin/$(src)
