#include "../cryptoLib.h"
#include "iostream"

int main(int argc, char const *argv[])
{
	mpz2_class b_pub, message, encryptedMessage;
	char usr_a, usr_b;
	std::string filename;
	FILE *file;

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

	//Get b public key
	filename = std::string("rsa-pub-") + usr_b + ".tmp";
	file = fopen(filename.c_str(), "r");
	if(file == NULL)
  	{
		std::cout << std::endl << "Error : " << filename <<" not found" << std::endl;
		return 1;
	}
	b_pub.inp_str(file, 16);
	fclose(file);
	std::cout << std::endl << "La cle publique de " << usr_b << " est : 0x" << std::hex << b_pub << std::endl;

	std::cout << "Quel est votre message (un entier) à chiffrer?" << std::endl;
	std::cin >> message;

	encryptedMessage = Crypto::rsa_encrypt(message, b_pub);

	filename = std::string("rsa-msg-") + usr_a + ".tmp";
	file = fopen(filename.c_str(), "w");
	encryptedMessage.out_str(file, 16);
	fclose(file);

	std::cout << "Votre message codé est : 0x" << std::hex << encryptedMessage << std::endl;
	std::cout << "Il a été stocké dans : " << filename << std::endl;


	return 0;
}