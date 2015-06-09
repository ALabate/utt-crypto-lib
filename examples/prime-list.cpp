#include "../cryptoLib.h"
#include <iostream>
#include <cmath>


int main(int argc, char const *argv[])
{
	int k;
	double probability;

	std::cout << "Prime list :" << std::endl;
	for (int i = 0; i < 1000; i+=1)
	{
		if(crypto_primality_test(i, 10))
		{
			std::cout << i << std::endl;
		}	
	}

	return 0;
}
