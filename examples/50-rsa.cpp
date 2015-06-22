#include "../cryptoLib.h"
#include <iostream>
#include <cmath>


int main(int argc, char const *argv[])
{
	mpz2_class a_pub, a_priv, b_pub, b_priv, a_msg, b_msg, encryptedMsg, decryptedMsg;
	mpz2_class randStart, randEnd;

	std::cout << "\nEnter the integer number message to send from Alice to Bob" << std::endl;
	std::cin >> a_msg;
	std::cout << "\nEnter the integer number message to send from Bob to Alice" << std::endl;
	std::cin >> b_msg;

	std::cout << std::endl << "===================== Step 0 =====================" << std::endl;
	std::cout << "This algorithm use a parameter common for the two users and known by everyone :" << std::endl;
	std::cout << std::endl << "The encryption exponent :" << std::endl;
	std::cout <<"    e = 0x"<< std::hex << Crypto::rsa_e << std::endl;
	std::cout << std::endl << "===================== Step 1 =====================" << std::endl;
	std::cout << "Alice :" << std::endl;
	std::cout << "   Alice generate a public and a private key" << std::endl;
	Crypto::rsa_generateKey(a_pub, a_priv);
	std::cout << "   a_pub = 0x" << std::hex << a_pub << std::endl;
	std::cout << "   a_priv = 0x" << std::hex << a_priv << std::endl;
	std::cout << "Bob :" << std::endl;
	std::cout << "   Bob generate a public and a private key" << std::endl;
	Crypto::rsa_generateKey(b_pub, b_priv);
	std::cout << "   b_pub = 0x" << std::hex << b_pub << std::endl;
	std::cout << "   b_priv = 0x" << std::hex << b_priv << std::endl;
	std::cout << std::endl << "===================== Step 2 =====================" << std::endl;
	std::cout << "Then Alice and Bob exchange their public keys" << std::endl;
	std::cout << std::endl << "===================== Step 3 =====================" << std::endl;
	std::cout << "Alice :" << std::endl;
	std::cout << "   Alice send a number : 0x" << std::hex << a_msg << std::endl;
	a_msg = Crypto::rsa_encrypt(a_msg, b_pub);
	std::cout << "   Crypted number (with Bob's public key) : 0x" << std::hex << a_msg << std::endl;
	std::cout << "Bob :" << std::endl;
	std::cout << "   Bob send a number : 0x" << std::hex << b_msg << std::endl;
	b_msg = Crypto::rsa_encrypt(b_msg, a_pub);
	std::cout << "   Crypted number (with Alice's public key) : 0x" << std::hex << b_msg << std::endl;
	std::cout << std::endl << "===================== Step 4 =====================" << std::endl;
	std::cout << "Alice :" << std::endl;
	std::cout << "   Alice decrypt bob's message (with alice's public and private key) :" << std::endl;
	b_msg = Crypto::rsa_decrypt(b_msg, a_pub, a_priv);
	std::cout << "   " << std::dec << b_msg << std::endl;
	std::cout << "Bob :" << std::endl;
	std::cout << "   Bob decrypt alice's message (with bob's public and private key) :" << std::endl;
	a_msg = Crypto::rsa_decrypt(a_msg, b_pub, b_priv);
	std::cout << "   " << std::dec << a_msg << std::endl;

	return 0;
}


