/**
 * @brief This is a lot of simple examples of almost each method of mpz2_class
 */

#include <stdio.h>
#include <iostream>
#include "../mpz2_class.h"
 
int main(int argc, char *argv[])
{
	// Init
	mpz2_class a, b, c, d, e, f, g, h, i, z;
	std::cout << "Init :" << std::endl;
	std::cout << "   mpz2_class a;" << std::endl;
	std::cout << "   // a = " << a << std::endl;

	// Clear
	z = 2;
	a = 2;
	z.clear();
	std::cout << "Clear :" << std::endl;
	std::cout << "   z = 2;" << std::endl;
	std::cout << "   a = 2;" << std::endl;
	std::cout << "   i.clear();" << std::endl;
	std::cout << "   // z = " << z << std::endl;
	std::cout << "   // a = " << a << std::endl;

	// Set to numbers
	a = 42; // int
	b = (unsigned long) 0xffffffffffffffff;
	c = (long) 0xffffffffffffffff;
	d = 42.42; // double
	std::cout << "Set from numbers :" << std::endl;
	std::cout << "   a = 42; // int" << std::endl;
	std::cout << "   b = (unsigned long) 0xffffffffffffffff;" << std::endl;
	std::cout << "   c = (long) 0xffffffffffffffff;" << std::endl;
	std::cout << "   d = 42.42; // float" << std::endl;
	std::cout << "   // a = " << a << std::endl;
	std::cout << "   // b = " << b << std::endl;
	std::cout << "   // c = " << c << std::endl;
	std::cout << "   // d = " << d << std::endl;

	//Convert from other gmp types
	mpf_t mpf;
	mpf_init(mpf);
	mpf_set_d(mpf, 42.42);
	a = mpf;
	
	mpq_t mpq;
	mpq_init(mpq);
	mpq_set_d(mpq, 42.42);
	b = mpq;

	mpz_t mpz;
	mpz_init(mpz);
	mpz_set_ui(mpz, 42);
	c = mpz;

	std::cout << "Convert from other gmp types :" << std::endl;
	std::cout << "   mpf_t mpf;" << std::endl;
	std::cout << "   mpf_init(mpf);" << std::endl;
	std::cout << "   mpf_set_d(mpf, 42.42);" << std::endl;
	std::cout << "   a = mpf;" << std::endl;
	std::cout << "   // a = " << a << std::endl;
	
	std::cout << "   mpq_t mpq;" << std::endl;
	std::cout << "   mpq_init(mpq);" << std::endl;
	std::cout << "   mpq_set_d(mpq, 42.42);" << std::endl;
	std::cout << "   b = mpq;" << std::endl;
	std::cout << "   // b = " << b << std::endl;

	std::cout << "   mpz_t mpz;" << std::endl;
	std::cout << "   mpz_init(mpz);" << std::endl;
	std::cout << "   mpz_set_ui(mpz, 42);" << std::endl;
	std::cout << "   c = mpz;" << std::endl;
	std::cout << "   // c = " << c << std::endl;


	// Convert from string
	a = "10"; 	//Decimal
	b = "0b10";	//Binary
	c = "0x10";	//Hexadecimal
	d = "010";	//Octal

	std::cout << "Convert from strings :" << std::endl;
	std::cout << "   a = \"10\";   //Decimal" << std::endl;
	std::cout << "   b = \"0b10\"; //Binary" << std::endl;
	std::cout << "   c = \"0x10\"; //Hexadecimal" << std::endl;
	std::cout << "   d = \"010\";  //Octal" << std::endl;
	std::cout << "   // a = " << a << std::endl;
	std::cout << "   // b = " << b << std::endl;
	std::cout << "   // c = " << c << std::endl;
	std::cout << "   // d = " << d << std::endl;

	// Swap
	a = 1;
	b = 2;
	std::cout << "Swap :" << std::endl;
	std::cout << "   a = 1;" << std::endl;
	std::cout << "   b = 2;" << std::endl;
	std::cout << "   a.swap(b);" << std::endl;
	std::cout << "   // a = " << a << std::endl;
	std::cout << "   // b = " << b << std::endl;

	//Convert to Standards types
	a = "0xFFFFFFFFFFFFFFFFFFFFFFFFF";
	b = 2;
	c = a.get_si();
	d = b.get_si();

	std::cout << "Convert to standard numbers :" << std::endl;
	std::cout << "   a = \"0xFFFFFFFFFFFFFFFFFFFFFFFFF\";" << std::endl;
	std::cout << "   b = 2;" << std::endl;
	std::cout << "   // a.fits_sint_p() = " << a.fits_sint_p() << std::endl;
	std::cout << "   // b.fits_sint_p() = " << b.fits_sint_p() << std::endl;
	std::cout << "   c = a.get_si();" << std::endl;
	std::cout << "   d = b.get_si();" << std::endl;
	std::cout << "   // c = " << c << std::endl;
	std::cout << "   // d = " << d << std::endl;

	//Multiplication
	a = 2;
	b = 3;
	c = a * b;
	d = 2 * b;
	e = a * 3;
	a *= b;
	b *= 2;
	std::cout << "Multiplication :" << std::endl;
	std::cout << "   a = 2;" << std::endl;
	std::cout << "   b = 3;" << std::endl;
	std::cout << "   c = a * b;" << std::endl;
	std::cout << "   // c = " << c << std::endl;
	std::cout << "   d = 2 * b;" << std::endl;
	std::cout << "   // d = " << d << std::endl;
	std::cout << "   e = a * 3;" << std::endl;
	std::cout << "   // e = " << e << std::endl;
	std::cout << "   a *= b;" << std::endl;
	std::cout << "   // a = " << a << std::endl;
	std::cout << "   b *= 2;" << std::endl;
	std::cout << "   // b = " << b << std::endl;

	//Aaaition
	a = 2;
	b = 3;
	c = a + b;
	d = 2 + b;
	e = a + 3;
	a += b;
	b += 2;
	std::cout << "Addition :" << std::endl;
	std::cout << "   a = 2;" << std::endl;
	std::cout << "   b = 3;" << std::endl;
	std::cout << "   c = a + b;" << std::endl;
	std::cout << "   // c = " << c << std::endl;
	std::cout << "   d = 2 + b;" << std::endl;
	std::cout << "   // d = " << d << std::endl;
	std::cout << "   e = a + 3;" << std::endl;
	std::cout << "   // e = " << e << std::endl;
	std::cout << "   a += b;" << std::endl;
	std::cout << "   // a = " << a << std::endl;
	std::cout << "   b += 2;" << std::endl;
	std::cout << "   // b = " << b << std::endl;

	//Division
	a = 20;
	b = 3;
	c = a / b;
	d = 20 / b;
	e = a / 3;
	a /= b;
	b /= 2;
	std::cout << "Division :" << std::endl;
	std::cout << "   a = 20;" << std::endl;
	std::cout << "   b = 3;" << std::endl;
	std::cout << "   c = a / b;" << std::endl;
	std::cout << "   // c = " << c << std::endl;
	std::cout << "   d = 20 / b;" << std::endl;
	std::cout << "   // d = " << d << std::endl;
	std::cout << "   e = a / 3;" << std::endl;
	std::cout << "   // e = " << e << std::endl;
	std::cout << "   a /= b;" << std::endl;
	std::cout << "   // a = " << a << std::endl;
	std::cout << "   b /= 2;" << std::endl;
	std::cout << "   // b = " << b << std::endl;

	//Soustraction
	a = 7;
	b = 3;
	c = a - b;
	d = 7 - b;
	e = a - 3;
	a -= b;
	b -= 3 + 3-7;
	std::cout << "Soustraction :" << std::endl;
	std::cout << "   a = 7;" << std::endl;
	std::cout << "   b = 3;" << std::endl;
	std::cout << "   c = a - b;" << std::endl;
	std::cout << "   // c = " << c << std::endl;
	std::cout << "   d = 7 - b;" << std::endl;
	std::cout << "   // d = " << d << std::endl;
	std::cout << "   e = a - 3;" << std::endl;
	std::cout << "   // e = " << e << std::endl;
	std::cout << "   a -= b;" << std::endl;
	std::cout << "   // a = " << a << std::endl;
	std::cout << "   b -= 3 + 3-7;" << std::endl;
	std::cout << "   // b = " << b << std::endl;

	//Modulo
	a = 20;
	b = 3;
	c = a % b;
	d = 20 % b;
	e = a % 3;
	a %= b;
	b %= 2;
	std::cout << "Modulo :" << std::endl;
	std::cout << "   a = 20;" << std::endl;
	std::cout << "   b = 3;" << std::endl;
	std::cout << "   c = a % b;" << std::endl;
	std::cout << "   // c = " << c << std::endl;
	std::cout << "   d = 20 % b;" << std::endl;
	std::cout << "   // d = " << d << std::endl;
	std::cout << "   e = a % 3;" << std::endl;
	std::cout << "   // e = " << e << std::endl;
	std::cout << "   a %= b;" << std::endl;
	std::cout << "   // a = " << a << std::endl;
	std::cout << "   b %= 2;" << std::endl;
	std::cout << "   // b = " << b << std::endl;


	//Negative
	a = 42;
	b = -a;
	std::cout << "Negative :" << std::endl;
	std::cout << "   a = 42;" << std::endl;
	std::cout << "   b = -a;" << std::endl;
	std::cout << "   // a = " << a << std::endl;
	std::cout << "   // b = " << b << std::endl;

	//Abs
	a = -42;
	b = a.abs();
	std::cout << "Abs :" << std::endl;
	std::cout << "   a = -42;" << std::endl;
	std::cout << "   b = a.abs();" << std::endl;
	std::cout << "   // a = " << a << std::endl;
	std::cout << "   // b = " << b << std::endl;

	//Divisible
	a = 10;
	b = 9;
	c = a.divisible(3);
	d = b.divisible(3);
	std::cout << "Divisible test :" << std::endl;
	std::cout << "   a = 10;" << std::endl;
	std::cout << "   b = 9;" << std::endl;
	std::cout << "   c = a.divisible(3);" << std::endl;
	std::cout << "   d = b.divisible(3);" << std::endl;
	std::cout << "   // c = " << c << std::endl;
	std::cout << "   // d = " << d << std::endl;

	//Congruent tp
	a = 10;
	b = a.congruent(2, 8);
	c = a.congruent(1, 8);
	std::cout << "Congruent test :" << std::endl;
	std::cout << "   a = 10;" << std::endl;
	std::cout << "   b = a.congruent(2, 8);" << std::endl;
	std::cout << "   c = a.congruent(1, 8);" << std::endl;
	std::cout << "   // b = " << b << std::endl;
	std::cout << "   // c = " << c << std::endl;


	//Pow
	a = 2;
	b = a.pow(2);
	std::cout << "Pow :" << std::endl;
	std::cout << "   a = 2;" << std::endl;
	std::cout << "   b = a.pow(2);" << std::endl;
	std::cout << "   // b = " << b << std::endl;
	std::cout << "   // Warning : You cannot use a mpz2_class with pow. Use powmod instead." << std::endl;

	//Pow mod
	a = 2;
	b = a.powmod(2, 3);
	std::cout << "Pow mod :" << std::endl;
	std::cout << "   a = 2;" << std::endl;
	std::cout << "   b = a.powmod(2, 3);" << std::endl;
	std::cout << "   // b = " << b << std::endl;

	//Root
	bool a_bool;
	a = 243;
	b = a.root(5, a_bool);
	c = a.root(4, d);
	std::cout << "Root :" << std::endl;
	std::cout << "   a = 243;" << std::endl;
	std::cout << "   b = a.root(5, a_bool);" << std::endl;
	std::cout << "   // b = " << b << std::endl;
	std::cout << "   // a_bool = " << a_bool << std::endl;
	std::cout << "   c = a.root(4, d);" << std::endl;
	std::cout << "   // c = " << c << std::endl;
	std::cout << "   // d = " << d << std::endl;

	//Sqrt
	a = 82;
	b = a.sqrt();
	c = a.sqrt(d);
	std::cout << "Sqrt :" << std::endl;
	std::cout << "   a = 82;" << std::endl;
	std::cout << "   b = a.sqrt();" << std::endl;
	std::cout << "   c = a.sqrt(d);" << std::endl;
	std::cout << "   // b = " << b << std::endl;
	std::cout << "   // c = " << c << std::endl;
	std::cout << "   // d = " << d << std::endl;


	//Perferct power test
	std::cout << "Perfect power test :" << std::endl;
	a = 10;
	b = a.perfect_power();
	c = a.perfect_square();
	std::cout << "   a = 10;" << std::endl;
	std::cout << "   b = a.perfect_power();" << std::endl;
	std::cout << "   c = a.perfect_square();" << std::endl;
	std::cout << "   // b = " << b << std::endl;
	std::cout << "   // c = " << c << std::endl;

	a = 8;
	b = a.perfect_power();
	c = a.perfect_square();
	std::cout << "   a = 8;" << std::endl;
	std::cout << "   b = a.perfect_power();" << std::endl;
	std::cout << "   c = a.perfect_square();" << std::endl;
	std::cout << "   // b = " << b << std::endl;
	std::cout << "   // c = " << c << std::endl;

	a = 4;
	b = a.perfect_power();
	c = a.perfect_square();
	std::cout << "   a = 4;" << std::endl;
	std::cout << "   b = a.perfect_power();" << std::endl;
	std::cout << "   c = a.perfect_square();" << std::endl;
	std::cout << "   // b = " << b << std::endl;
	std::cout << "   // c = " << c << std::endl;

	//Prime numbers
	a = 8;
	b = 7;
	c = a.probab_prime(30);
	d = b.probab_prime(30);
	e = a.nextprime();
	f = b.nextprime();
	std::cout << "Find and test prime numbers :" << std::endl;
	std::cout << "   a = 8;" << std::endl;
	std::cout << "   b = 7;" << std::endl;
	std::cout << "   c = a.probab_prime(30);" << std::endl;
	std::cout << "   d = b.probab_prime(30);" << std::endl;
	std::cout << "   // c = " << c << std::endl;
	std::cout << "   // d = " << d << std::endl;
	std::cout << "   e = a.nextprime();" << std::endl;
	std::cout << "   f = b.nextprime();" << std::endl;
	std::cout << "   // e = " << e << std::endl;
	std::cout << "   // f = " << f << std::endl;

	//GCD and LCM
	a = 10;
	b = 15;
	c = a.gcd(15, d, e);
	f = a.lcm(15);
	std::cout << "GCD and LCM :" << std::endl;
	std::cout << "   a = 10;" << std::endl;
	std::cout << "   b = 15;" << std::endl;
	std::cout << "   c = a.gcd(15, d, e);" << std::endl;
	std::cout << "   // c = " << c << std::endl;
	std::cout << "   // d = " << d << std::endl;
	std::cout << "   // e = " << e << std::endl;
	std::cout << "   f = a.lcm(15);" << std::endl;
	std::cout << "   // f = " << f << std::endl;
        
	// Invert mod
	a = 3;
	b = a.invertmod(10);
	std::cout << "Invert modulo :" << std::endl;
	std::cout << "   a = 3;" << std::endl;
	std::cout << "   b = a.invertmod(10);" << std::endl;
	std::cout << "   // b = " << b << std::endl;
	std::cout << "   // 3*7=21 ; 21%10=1" << std::endl;

	// Bitwise
	a = "0b0011";
	b = "0b0110";
	c = a & b;
	d = a | b;
	e = a ^ b;
	f = ~a;
	g = a>>1;
	std::cout << "Bitwise :" << std::endl;
	std::cout << "   a = \"0b0011\";" << std::endl;
	std::cout << "   b = \"0b0110\";" << std::endl;
	std::cout << "   c = a & b;" << std::endl;
	std::cout << "   d = a | b;" << std::endl;
	std::cout << "   e = a ^ b;" << std::endl;
	std::cout << "   f = ~a;" << std::endl;
	std::cout << "   g = a>>1;" << std::endl;
	std::cout << "   // c = 0x" << std::hex << c << std::endl;
	std::cout << "   // d = 0x" << std::hex << d << std::endl;
	std::cout << "   // e = 0x" << std::hex << e << std::endl;
	std::cout << "   // f = 0x" << std::hex << f << std::endl;
	std::cout << "   // g = 0x" << std::hex << g << std::endl;
	std::cout << std::dec;

	// Use files
	a = 0x1234567890AbCdEf;
	FILE *strFile;
	strFile = fopen("test-str.tmp", "w");
	a.out_str(strFile, 16);
	fclose(strFile);
	strFile = fopen("test-str.tmp", "r");
	b.inp_str(strFile, 16);
	FILE *rawFile;
	rawFile = fopen("test-raw.tmp", "w");
	a.out_raw(rawFile);
	fclose(rawFile);
	rawFile = fopen("test-raw.tmp", "r");
	c.inp_raw(rawFile);

	std::cout << "Write and read from files :" << std::endl;
	std::cout << "   a = 0x1234567890AbCdEf;" << std::endl;
	std::cout << "   FILE strFile;" << std::endl;
	std::cout << "   strFile = fopen(\"test-str.tmp\", \"w\");" << std::endl;
	std::cout << "   a.out_str(strFile, 16);" << std::endl;
	std::cout << "   fclose(strFile);" << std::endl;
	std::cout << "   strFile = fopen(\"test-str.tmp\", \"r\");" << std::endl;
	std::cout << "   b.inp_str(strFile, 16);" << std::endl;
	std::cout << "   // b = " << std::hex << b << std::endl;
	std::cout << "   FILE rawFile;" << std::endl;
	std::cout << "   rawFile = fopen(\"test-raw.tmp\", \"w\");" << std::endl;
	std::cout << "   a.out_raw(rawFile);" << std::endl;
	std::cout << "   fclose(rawFile);" << std::endl;
	std::cout << "   rawFile = fopen(\"test-raw.tmp\", \"r\");" << std::endl;
	std::cout << "   c.inp_raw(rawFile);" << std::endl;
	std::cout << "   // c = " << c << std::endl;
	std::cout << std::dec;

	//Random
	a.setRandom(10,12);
	b.setRandom(1,"1000000");
	std::cout << "Random :" << std::endl;
	std::cout << "   a.setRandom(10,12);" << std::endl;
	std::cout << "   b.setRandom(1,\"1000000\");" << std::endl;
	std::cout << "   // a = " << a << std::endl;
	std::cout << "   // b = " << b << std::endl;

	return 0;
}