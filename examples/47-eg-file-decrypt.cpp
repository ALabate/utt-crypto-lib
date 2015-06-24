#include "../cryptoLib.h"
#include "iostream"
#include <unistd.h>
#include <linux/limits.h>

int main(int argc, char const *argv[])
{
	mpz2_class a, b_pub, p, encryptedMessage, decryptedMessage;

	char reponse, usr_a, usr_b;
	std::string filename;


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
	std::getline(std::cin, filename);


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
	filename = std::string("eg-priv-") + usr_a + ".tmp";
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




	//Get current path
    char buff[PATH_MAX];
    getcwd(buff, PATH_MAX);
	std::cout << "Sachant que nous sommes ici : " << buff << std::endl;

	std::cout << "Quel fichier voullez vous déchiffrer ?" << std::endl;
	std::getline(std::cin, filename);


	//Get encrypted message
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
	std::string filename_clear = filename + ".cl.tmp";
	std::ofstream file_clear (filename_clear.c_str(), std::ifstream::binary | std::ofstream::trunc);
	for (int i = 0; i < count; ++i)
	{
		encryptedMessage = Crypto::file_split(file2, Crypto::dh_cryptedBlockBytes);
		decryptedMessage = Crypto::eg_decrypt(a, b_pub, encryptedMessage, p);
		Crypto::file_append(file_clear, Crypto::dh_blockBytes, decryptedMessage);
	}
	file2.close();
	file_clear.close();

	std::cout << "Votre fichier déchiffré est : " << std::endl << filename_clear << std::endl;
	delete[] message;

	return 0;
}