#include "../cryptoLib.h"
#include "iostream"

int main(int argc, char const *argv[])
{
	mpz2_class a, b, a_pub, b_pub, message, encryptedMsg, decryptedMsg;
	mpz2_class randStart, randEnd;

	std::cout << "\nEnter the integer number message to send from Alice to Bob" << std::endl;
	std::cin >> message;

	//Alice number
	randStart = mpz2_class(1) << (1023);
	randEnd = (mpz2_class(1) << 1024) - 1;
	a.setRandom(randStart, randEnd);

	//Bob number
	b.setRandom(randStart, randEnd);

	std::cout << std::endl << "===================== Step 0 =====================" << std::endl;
	std::cout << "This algorithm use two parameters common for the two users and known by everyone :" << std::endl;
	std::cout << "A prime number \"p\" :" << std::endl;
	std::cout <<"    p = 0x"<< std::hex << Crypto::dh_p << std::endl;
	std::cout << std::endl << "A generator of the cyclic group Z/pZ \"g\" :" << std::endl;
	std::cout <<"    g = 0x"<< std::hex << Crypto::dh_g << std::endl;

	std::cout << std::endl << "===================== Step 1 =====================" << std::endl;
	std::cout << "Alice :" << std::endl;
	std::cout << "   Alice take a random number" << std::endl;
	std::cout << "   A = 0x" << std::hex << a << std::endl;
	std::cout << "   Then Alice calculate her public key :" << std::endl;
	a_pub = Crypto::eg_generateKey(a);
	std::cout << "   0x" << std::hex << a_pub << std::endl;
	std::cout << std::endl << "Bob :" << std::endl;
	std::cout << "   Bob take also a random number" << std::endl;
	std::cout << "   B = 0x" << std::hex << b << std::endl;
	std::cout << "   Then Bob calculate his public key :" << std::endl;
	b_pub = Crypto::eg_generateKey(b);
	std::cout << "   0x" << std::hex << b_pub << std::endl;

	std::cout << std::endl << "===================== Step 2 =====================" << std::endl;
	std::cout << "Then Alice and Bob exchange their public keys" << std::endl;

	std::cout << std::endl << "===================== Step 3 =====================" << std::endl;
	std::cout << "Alice :" << std::endl;
	std::cout << "   Alice send a number : 0x" << std::hex << message << std::endl;
	encryptedMsg = Crypto::eg_encrypt(a, b_pub, message);
	std::cout << "   Crypted number : 0x" << std::hex << encryptedMsg << std::endl;

	std::cout << std::endl << "===================== Step 4 =====================" << std::endl;
	std::cout << "Bob :" << std::endl;
	std::cout << "   Bob decrypt alice's message :" << std::endl;
	decryptedMsg = Crypto::eg_decrypt(b, a_pub, encryptedMsg);
	std::cout << "   " << std::dec << decryptedMsg << std::endl;

	return 0;
}