/**
 * @brief This show how much the exponentiation by squaring algorithme is better with powers
 */

#include <sys/time.h>
#include <iostream>
#include "../cryptoLib.h"

int main(int argc, char *argv[])
{
	//Init the two big numbers (integer) that we will manipulate
	mpz2_class a, res;
	unsigned long power;

	//Time init
	struct timeval t1, t2;

	//Set numbers
	a = "148189247128974289127484021983013239823";
	power = 20000;

	//Show operation
	std::cout << "Operation :" << std::endl;
	std::cout << "  " << a << " ^ " << power << std::endl;

	//Classic way of doing c=a^b
	std::cout << "Classic : " << std::endl;
	gettimeofday(&t1, NULL);
	res = Crypto::pow_classic(a, power);
	gettimeofday(&t2, NULL);
	std::cout << "  Duration : " << ((double)(t2.tv_usec-t1.tv_usec)/1000000 + (t2.tv_sec-t1.tv_sec)) << " s"  << std::endl; 
	std::cout << "  Result end : 0x" << std::hex << (res%0xffffffff) << std::endl; 

	//Squaring
	std::cout << "Squaring : " << std::endl;
	gettimeofday(&t1, NULL);
	res = Crypto::pow(a, power);
	gettimeofday(&t2, NULL);
	std::cout << "  Duration : " << ((double)(t2.tv_usec-t1.tv_usec)/1000000 + (t2.tv_sec-t1.tv_sec)) << " s"  << std::endl; 
	std::cout << "  Result end : 0x" << std::hex << (res%0xffffffff) << std::endl; 

	//Internal
	std::cout << "GMP Internal : " << std::endl;
	gettimeofday(&t1, NULL);
	res = a.pow(power);
	gettimeofday(&t2, NULL);
	std::cout << "  Duration : " << ((double)(t2.tv_usec-t1.tv_usec)/1000000 + (t2.tv_sec-t1.tv_sec)) << " s" << std::endl; 
	std::cout << "  Result end : 0x" << std::hex << (res%0xffffffff) << std::endl; 

	return 0;
}