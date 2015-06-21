#include "../cryptoLib.h"
#include "iostream"

int main(int argc, char const *argv[])
{
	mpz2_class a, b_pub, p, encryptedMessage, decryptedMessage;

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

	//Get encrypted message
	filename = std::string("eg-txt-msg-") + usr_b + ".tmp";
	std::ifstream file2 (filename.c_str(), std::ifstream::binary);
	if(!file2.is_open())
	{
		std::cout << std::endl << "Error : " << filename <<" not found" << std::endl;
		return 1;
	}

    // get length of file:
    file2.seekg (0, file2.end);
    int length = file2.tellg();
    file2.seekg (0, file2.beg);

    int count = length / Crypto::dh_cryptedBlockBytes;
	char* message = new char [count * Crypto::dh_blockBytes];

	//decrypt
	int i = 0;
	for (int i = 0; i < count; ++i)
	{
		encryptedMessage = Crypto::file_split(file2, Crypto::dh_cryptedBlockBytes);
		decryptedMessage = Crypto::eg_decrypt(a, b_pub, encryptedMessage, p);
		Crypto::buf_append(message, i, Crypto::dh_blockBytes, decryptedMessage);
	}
	file2.close();

	std::cout << "Le nombre chiffré est : 0x" << std::hex << encryptedMessage << std::endl;
	std::cout << "Le nombre déchiffré est : 0x" << std::hex << decryptedMessage << std::endl;
	std::cout << "Le message déchiffré est : " << message << std::endl;
	delete[] message;

	return 0;
}