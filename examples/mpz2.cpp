/**
 * @brief This is a simple example with the gmp library that will sum to big numbers
 */

#include <stdio.h>
#include <iostream>
#include "../mpz2_class.h"
#include <gmp.h>
 
int main(int argc, char *argv[])
{
	// Init
	mpz2_class a;
	mpz2_class b, c, d, e, f, g, h, i;
	std::cout << "Init : " << std::endl;
	std::cout << "    a:" << a << ", b:" << b << ", c:" << c << std::endl;

	// Clear
	a = 2;
	d = 2;
	a.clear();
	std::cout << "Clear : " << std::endl;
	std::cout << "   sizeof(a):" << a << ", sizeof(d):" << d << std::endl;

	// Set
	d = (unsigned long) 0xffffffffffffffff;
	e = (long) 0xffffffffffffffff;
	f = (double) 42.42;
	std::cout << "Set with numbers : " << std::endl;
	std::cout << "    d:" << d << ", e:" << e << ", f:" << f << std::endl;


	//Convert from other gmp types
	mpf_t mpf;
	mpf_init(mpf);
	mpf_set_d(mpf, 42.42);
	
	mpq_t mpq;
	mpq_init(mpq);
	mpq_set_d(mpq, 42.42);

	mpz_t mpz;
	mpz_init(mpz);
	mpz_set_ui(mpz, 42);

	d = mpf;
	e = mpq;
	f = mpz;

	std::cout << "Convert from other gmp types : " << std::endl;
	std::cout << "    d:" << d << ", e:" << e << ", f:" << f << std::endl;


	// Convert from string
	d = "0x10"; //Hexadecimal test
	e = "010"; //Octal test
	f = "0b10"; //Binary test
	g = "10"; //Decimal test
	std::cout << "Set with strings : " << std::endl;
	std::cout << "   d:" << d << ", e:" << e << ", f:" << f << ", g:" << g << std::endl;

	// Swap
	d = 1;
	e = 2;
	std::cout << "Swap : " << std::endl;
	std::cout << "   d:" << d << ", e:" << e << std::endl;
	d.swap(e);
	std::cout << "   d:" << d << ", e:" << e << std::endl;

	//Multiplication
	d = 2;
	e = 3;
	f = d * e;
	g = 2 * e;
	h = d * 3;
	d *= e;
	e *= 2;
	std::cout << "Multiplication : " << std::endl;
	std::cout << "   d:" << d << ", e:" << e << ", f:" << f << ", g:" << g << ", h:" << h << std::endl;

	//Addition
	d = 2;
	e = 3;
	f = d + e;
	g = 2 + e;
	h = d + 3;
	d += e;
	e += 2;
	std::cout << "Addition : " << std::endl;
	std::cout << "   d:" << d << ", e:" << e << ", f:" << f << ", g:" << g << ", h:" << h << std::endl;

	//Division
	d = 20;
	e = 3;
	f = d / e;
	g = 20 / e;
	h = d / 3;
	d /= e;
	e /= 2;
	std::cout << "Division : " << std::endl;
	std::cout << "   d:" << d << ", e:" << e << ", f:" << f << ", g:" << g << ", h:" << h << std::endl;

	//Soustraction
	d = 7;
	e = 3;
	f = d - e;
	g = 7 - e;
	h = d - 3;
	d -= e;
	e -= 3 + 3-7;
	std::cout << "Soustraction : " << std::endl;
	std::cout << "   d:" << d << ", e:" << e << ", f:" << f << ", g:" << g << ", h:" << h << std::endl;

	//Modulo
	d = 20;
	e = 3;
	f = d % e;
	g = 20 % e;
	h = d % 3;
	d %= e;
	e %= 2;
	std::cout << "Modulo : " << std::endl;
	std::cout << "   d:" << d << ", e:" << e << ", f:" << f << ", g:" << g << ", h:" << h << std::endl;


	//Negative
	d = 20;
	e = -d;
	std::cout << "Negative : " << std::endl;
	std::cout << "   d:" << d << ", e:" << e << std::endl;

	//Abs
	e = -20;
	std::cout << "Abs : " << std::endl;
	std::cout << "   e.abs():" << e.abs() << ", e:" << e << std::endl;

	//Pow
	double aa = 2.1;
	float bb = 2.1;
	int cc = 2;
	d = 2;
	e = d.pow(aa);
	f = d.pow(bb);
	g = d.pow(cc);
	h = d.pow(2);
	std::cout << "Pow : " << std::endl;
	std::cout << "   d:" << d.pow(2) << ", e:" << e << ", f:" << f << ", g:" << g << ", h:" << h << std::endl;

	//Pow mod
	d = 2;
	e = 3;
	f = d.powmod(d,e);
	std::cout << "Pow mod : " << std::endl;
	std::cout << "   d.powmod(2,3)=" << d.powmod(2,3) << ", d.powmod(d,e)=" << d.powmod(d,e) << std::endl;

	return 0;
}