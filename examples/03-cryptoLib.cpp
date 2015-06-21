/**
 * @brief This is a lot of simple examples of almost each method of mpz2_class
 */

#include <stdio.h>
#include <iostream>
#include "../cryptoLib.h"
 
int main(int argc, char *argv[])
{
	// Init
	mpz2_class a, b, c, d, e, f, g, h, i, z;


		// static mpz2_class file_split(FILE* file, unsigned long n);

		// static void file_append(FILE* file, unsigned long n, mpz2_class value);





	//Strings
	char buf[10];
	buf[0] = 0x41;
	buf[1] = 0x20;
	buf[2] = 0x42;
	buf[3] = 0x43;
	buf[4] = 0x44;
	buf[5] = 0;

	std::cout << buf << std::endl;


	a = Crypto::buf_split(buf, 0, 2);
	b = Crypto::buf_split(buf, 1, 2);
	c = Crypto::buf_split(buf, 2, 2);

	std::cout << "   // a = 0x" << std::hex << a << std::endl;
	std::cout << "   // b = 0x" << std::hex << b << std::endl;
	std::cout << "   // c = 0x" << std::hex << c << std::endl;

	buf[0] = 0x47;
	buf[1] = 0x47;
	buf[2] = 0x47;
	buf[3] = 0x47;
	buf[4] = 0x47;
	buf[5] = 0x47;
	buf[6] = 0x47;
	buf[7] = 0;

	std::cout << buf << std::endl;

	Crypto::buf_append(buf, 0, 2, a);
	Crypto::buf_append(buf, 1, 2, b);
	Crypto::buf_append(buf, 2, 2, c);


	std::cout << buf << std::endl;

	return 0;
}