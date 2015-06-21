#include "../cryptoLib.h"
#include "iostream"

int main(int argc, char const *argv[])
{
	mpz2_class a, b, a_pub, b_pub, a_common, b_common;

	std::cout << "\nEnter the integer secret number from Alice" << std::endl;
	std::cin >> a;
	std::cout << "Enter the interger secret number from Bob" << std::endl;
	std::cin >> b;

	std::cout << std::endl << "===================== Step 0 =====================" << std::endl;
	std::cout << "This algorithm use two parameters common for the two users and known by everyone :" << std::endl;
	std::cout << "A prime number \"p\" :" << std::endl;
	std::cout <<"    p = 0x"<< std::hex << Crypto::dh_p << std::endl;
	std::cout << std::endl << "A generator of the cyclic group Z/pZ \"g\" :" << std::endl;
	std::cout <<"    g = 0x"<< std::hex << Crypto::dh_g << std::endl;

	std::cout << std::endl << "===================== Step 1 =====================" << std::endl;
	std::cout << "Alice :" << std::endl;
	std::cout << "   Alice choose a secret number" << std::endl;
	std::cout << "   a = 0x" << std::hex << a << std::endl;
	std::cout << "   Then Alice calculate a_pub = g^a mod p" << std::endl;
	a_pub = Crypto::dh_step1(a);
	std::cout << "   a_pub = 0x" << std::hex << a_pub << std::endl;
	std::cout << std::endl << "Bob :" << std::endl;
	std::cout << "   Bob choose also a secret number" << std::endl;
	std::cout << "   b = 0x" << std::hex << b << std::endl;
	std::cout << "   Then Bob calculate b_pub = g^b mod p" << std::endl;
	b_pub = Crypto::dh_step1(b);
	std::cout << "   b_pub = 0x" << std::hex << b_pub << std::endl;

	std::cout << std::endl << "===================== Step 2 =====================" << std::endl;
	std::cout << "Then Alice send a_pub to Bob and Bob send b_pub to Alice" << std::endl;
	std::cout << "At this point Alice knows her secret number \"a\" , \"a_pub\" and \"b_pub\" " << std::endl;
	std::cout << "And Bob knows his secret number \"b\" , \"b_pub\" and  \"a_pub\" " << std::endl;

	std::cout << std::endl << "===================== Step 3 =====================" << std::endl;
	std::cout << "Alice :" << std::endl;
	std::cout << "   Alice calculate common_a = (g^b)^a mod p" << std::endl;
	a_common = Crypto::dh_step2(a, b_pub);
	std::cout << "   a_common = 0x" << std::hex << a_common << std::endl;
	std::cout << std::endl << "Bob :" << std::endl;
	std::cout << "   Bob calculate S_B = (g^a)^b mod p" << std::endl;
	b_common = Crypto::dh_step2(b, a_pub);
	std::cout << "   b_common = 0x" << std::hex << b_common << std::endl;

	std::cout << std::endl << "===================== Conclusion =====================" << std::endl;
	std::cout << "As you can see a_common = b_common so now Alice and Bob have a common key" <<std::endl;
	std::cout << "   commonKey = 0x" << std::hex << a_common <<std::endl;
	return 0;
}