#include "../cryptoLib.h"
#include <iostream>
#include <cmath>


int main(int argc, char const *argv[])
{

	std::string strMessage;
	std::cout << "Entrer un nombre à chiffrer" << std::endl;
	std::cin >> strMessage;

	mpz2_class n, d, e;

	rsa_keyGenerator(n, d, e);
	std::cout << "n=" << n << std::endl;


	mpz2_class encryptedMessage = rsa_encrypt(mpz2_class(strMessage), e, n);

	std::cout << "Nombre chiffré : " << encryptedMessage << std::endl;
	std::cout << "Nombre déchiffré : " << rsa_decrypt(encryptedMessage, d, n) << std::endl;

	return 0;
}
