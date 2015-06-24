#include "../cryptoLib.h"
#include "iostream"

int main(int argc, char const *argv[])
{
	mpz2_class a_pub, a_priv;
	char reponse, usr_a, usr_b;

	std::cout << "\nEtes vous a ou b ?" << std::endl;
	std::cin >> usr_a;
	if(usr_a == 'a') {
		usr_b = 'b';
	}
	else if(usr_a == 'b') {
		usr_b = 'a';
	}
	else {
		usr_a = 'a';
		usr_b = 'b';
	}

	Crypto::rsa_generateKey(a_pub, a_priv);

	FILE *file;
	std::string filename = std::string("rsa-pub-") + usr_a + ".tmp";
	file = fopen(filename.c_str(), "w");
	a_pub.out_str(file, 16);
	fclose(file);

	std::cout << "Votre clé publique est : 0x" << std::hex << a_pub << std::endl;
	std::cout << "Elle a été stocké dans le fichier : " << filename << std::endl;


	filename = std::string("rsa-priv-") + usr_a + ".tmp";
	file = fopen(filename.c_str(), "w");
	a_priv.out_str(file, 16);
	fclose(file);

	std::cout << "Votre clé publique est : 0x" << std::hex << a_priv << std::endl;
	std::cout << "Votre clé privée est dans le fichier : " << filename << std::endl;

	return 0;
}