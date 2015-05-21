/**
 * @brief This is a simple example with the gmp library that will sum to big numbers
 */

#include <stdio.h>
#include <gmpxx.h>
#include <iostream>
 
int main(int argc, char *argv[])
{
	//Init the three big numbers (integer) that we will manipulate
	mpz_class a, b, c;

	//Set a to a big number in base 10
	a = "148189247128974289127484021983013239823";

	//Set a to a small number in hexadecimal
	b = 0xA;

	//c=a+b
	c = a + b;

	//Print output
	std::cout << a << " + " << b << " = " << c << std::endl;


	return 0;
}