#include "../cryptoLib.h"
#include "iostream"

int main(int argc, char const *argv[])
{
	mpz2_class a_pub, a_priv, encryptedMessage, decryptedMessage;
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

	//Get back a private key
	filename = std::string("rsa-priv-") + usr_a + ".tmp";
	file = fopen(filename.c_str(), "r");
	if(file == NULL)
  	{
		std::cout << std::endl << "Error : " << filename << " not found" << std::endl;
		return 1;
	}
	a_priv.inp_str(file, 16);
	fclose(file);
	std::cout << "Votre clé privée est : 0x" << std::hex << a_priv << std::endl;

	//Get b public key
	filename = std::string("rsa-pub-") + usr_a + ".tmp";
	file = fopen(filename.c_str(), "r");
	if(file == NULL)
  	{
		std::cout << std::endl << "Error : " << filename <<" not found" << std::endl;
		return 1;
	}
	a_pub.inp_str(file, 16);
	fclose(file);
	std::cout << std::endl << "La cle publique de " << usr_a << " est : 0x" << std::hex << a_pub << std::endl;

	//Get encrypted message
	filename = std::string("rsa-msg-") + usr_b + ".tmp";
	file = fopen(filename.c_str(), "r");
	if(file == NULL)
  	{
		std::cout << std::endl << "Error : " << filename <<" not found" << std::endl;
		return 1;
	}
	encryptedMessage.inp_str(file, 16);
	fclose(file);
	std::cout << std::endl << "Le message chiffré de " << usr_b << " est : 0x" << std::hex << encryptedMessage << std::endl;

	decryptedMessage = Crypto::rsa_decrypt(encryptedMessage, a_pub, a_priv);
	std::cout << "Le message déchiffré est : " << std::dec << decryptedMessage << std::endl;

	return 0;
}