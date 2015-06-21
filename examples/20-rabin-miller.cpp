#include "../cryptoLib.h"
#include <iostream>
#include <cmath>


int main(int argc, char const *argv[])
{
	int k;
	double probability;
	std::string nb;
	std::cout << "Enter a number to test" << std::endl;
	std::cin >> nb;

	std::cout << "How many test would you want to do? " << std::endl;
	std::cin >> k;

	if (Crypto::rm_probabPrime(mpz2_class(nb), k))
	{
		std::cout << "The number is probably prime" << std::endl;
		probability= pow(4,-k);
		std::cout << "Mistake probability is of the order of " << probability << std::endl;
	}
	else
	{
		std::cout << "The number is composite" << std::endl;
	}
	return 0;
}
