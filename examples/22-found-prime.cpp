#include "../cryptoLib.h"
#include <iostream>
#include <cmath>


int main(int argc, char const *argv[])
{
	int k, bitlength;
	mpz2_class p, randStart, randEnd;
	std::cout << "Enter the number of bits you want in your prime number :" << std::endl;
	std::cin >> bitlength;

	std::cout << "How many test would you want to do? " << std::endl;
	std::cin >> k;


	randStart = mpz2_class(1) << (bitlength - 1);
	randEnd = (mpz2_class(1) << bitlength) - 1;
	do {
		p.setRandom(randStart, randEnd);
	} while((p%2 == 0) || !crypto_primality_test(p,k));


	std::cout << "Probably prime number found :" << std::endl;
	std::cout << "0x" << std::hex << p << std::endl;

	return 0;
}
