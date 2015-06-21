#include "../cryptoLib.h"
#include "iostream"

int main(int argc, char const *argv[])
{
	mpz2_class a, b_pub, p, randStart, randEnd, message, encryptedMessage;
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
		usr_a = 'b';
		usr_b = 'b';
	}


	// std::cout << "Voulez-vous choisir un nombre premier et son générateur N/o? (si non, les paramètres par défaut seront utilisés)" << std::endl;
	// std::cin >> reponse;
	// if (reponse == 'o' || reponse == 'O')
	// {
	// 	std::cout << "Quel est alors le nombre premier?" << std::endl;
	// 	std::cin >> p;
	// }
	// else 
	// {
		p = 0;
	// }

	//Get back a private key
	FILE *file;
	std::string filename = std::string("eg-priv-") + usr_a + ".tmp";
	file = fopen(filename.c_str(), "r");
	if(file == NULL)
  	{
		std::cout << std::endl << "Error : " << filename << " not found" << std::endl;
		return 1;
	}
	a.inp_str(file, 16);
	fclose(file);
	std::cout << "Votre nombre secret est : 0x" << std::hex << a << std::endl;

	//Get b public key
	filename = std::string("eg-pub-") + usr_b + ".tmp";
	file = fopen(filename.c_str(), "r");
	if(file == NULL)
  	{
		std::cout << std::endl << "Error : " << filename <<" not found" << std::endl;
		return 1;
	}
	b_pub.inp_str(file, 16);
	fclose(file);
	std::cout << std::endl << "La cle publique de " << usr_b << " est : 0x" << std::hex << b_pub << std::endl;

	std::cout << "Quel est votre message (un entier) à coder?" << std::endl;
	std::cin >> message;

	encryptedMessage = Crypto::eg_encrypt(a, b_pub, message, p);


	filename = std::string("eg-msg-") + usr_a + ".tmp";
	file = fopen(filename.c_str(), "w");
	encryptedMessage.out_str(file, 16);
	fclose(file);

	std::cout << "Votre message codé est : 0x" << std::hex << encryptedMessage << std::endl;
	std::cout << "Il a été stocké dans : " << filename << std::endl;


	return 0;
}