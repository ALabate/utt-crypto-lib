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