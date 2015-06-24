#include "../cryptoLib.h"
#include <iostream>
#include <cmath>


int main(int argc, char const *argv[])
{
	unsigned int k, n;
	double probability;
	std::cout << "How many test would you want to do? " << std::endl;
	std::cin >> k;

	std::cout << "How many numbers do you want to show ? " << std::endl;
	std::cin >> n;

	std::cout << "Prime list :" << std::endl;
	std::cout << "2" << std::endl;
	unsigned int i = 1;
	unsigned int test = 3;
	while(i <= n)
	{
		if(Crypto::rm_probabPrime(test, k))
		{
			std::cout << test << std::endl;
			i++;
		}
		test += 2;
	}

	return 0;
}
