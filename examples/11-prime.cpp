/**
 * @brief This compare the cryptoLib rabin miller prime test with the gmp one
 */

#include <sys/time.h>
#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
#include "../cryptoLib.h"
 
int main(int argc, char *argv[])
{
	//Init the two big numbers (integer) that we will manipulate
	mpz2_class a;
	int res;
	unsigned long k;

	//Time init
	struct timeval t1, t2;

	//Set numbers
	a = "0x9b83c987e7277d74c350556297556cf013f5d8d1e334b3af169303569b7b8f30968e19cc340d1dfed4a382d072eda1c33a46e864310dc86c175aa9069f61c38ad518272ced4cd7ca7d7ef27b172b0cfd1b26b4d5241154dfc146325fd056771f7bd002b59c67b3bbee16826faced5b7a104b5f64d3331d31f212174039075fe3";
	k = 5000;

	//Show operation
	std::cout << "Try to find if this number is prime with Rabin-Miller algorithm :" << std::endl;
	std::cout << "  0x" << std::hex << a << std::endl;
	std::cout << "  " << " with " << std::dec << k << " tests" << std::endl;

	//Classic way of doing c=a^b
	std::cout << "Simple Rabin-Miller : " << std::endl;
	gettimeofday(&t1, NULL);
	res = crypto_primality_test(a, k);
	gettimeofday(&t2, NULL);
	std::cout << "  Duration : " << ((double)(t2.tv_usec-t1.tv_usec)/1000000 + (t2.tv_sec-t1.tv_sec)) << " s"  << std::endl; 
	if(res != 0) {
		std::cout << "  Probably prime" << std::endl; 
	}
	else {
		std::cout << "  Not prime" << std::endl; 
	}

	//Internal
	std::cout << "GMP Internal : " << std::endl;
	gettimeofday(&t1, NULL);
	res = a.probab_prime(k);
	gettimeofday(&t2, NULL);
	std::cout << "  Duration : " << ((double)(t2.tv_usec-t1.tv_usec)/1000000 + (t2.tv_sec-t1.tv_sec)) << " s" << std::endl; 
	if(res == 2) {
		std::cout << "  It is prime" << std::endl; 
	}
	if(res != 0) {
		std::cout << "  Probably prime" << std::endl; 
	}
	else {
		std::cout << "  Not prime" << std::endl; 
	}

	return 0;
}