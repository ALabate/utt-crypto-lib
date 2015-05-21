.PHONY: lib example run


lib: cryptoLib.c cryptoLib.h
	# ================= Build cryptoLib =================
	mkdir -p ./bin
	gcc -c cryptoLib.c -o ./bin/cryptoLib.o
example:
	# ================ Build example $(src) ================
	gcc -c examples/$(src).c -o ./bin/$(src).o
	gcc -lgmp -o ./bin/$(src) ./bin/cryptoLib.o ./bin/$(src).o
run:
	# ===================== Run $(src) =====================
	./bin/$(src)


libcpp: cryptoLib.cpp cryptoLib.hpp
	# ================= Build cryptoLib =================
	mkdir -p ./bincpp
	clang++ -c cryptoLib.cpp -o ./bincpp/cryptoLib.o
examplecpp:
	# ================ Build example $(src) ================
	clang++ -c examples/$(src).cpp -o ./bincpp/$(src).o
	clang++ -lgmp -lgmpxx -o ./bincpp/$(src) ./bincpp/cryptoLib.o ./bincpp/$(src).o
runcpp:
	# ===================== Run $(src) =====================
	./bincpp/$(src)