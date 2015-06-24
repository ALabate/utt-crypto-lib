#include "../cryptoLib.h"
#include "iostream"
#include <unistd.h>
#include <linux/limits.h>

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
	std::getline(std::cin, filename);


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

    int count = length / Crypto::rsa_cryptedBlockBytes;
	char* message = new char [count * Crypto::rsa_blockBytes];

	//decrypt
	std::string filename_clear = filename + ".cl.tmp";
	std::ofstream file_clear (filename_clear.c_str(), std::ifstream::binary | std::ofstream::trunc);
	for (int i = 0; i < count; ++i)
	{
		encryptedMessage = Crypto::file_split(file2, Crypto::rsa_cryptedBlockBytes);
		decryptedMessage = Crypto::rsa_decrypt(encryptedMessage, a_pub, a_priv);
		Crypto::file_append(file_clear, Crypto::rsa_blockBytes, decryptedMessage);
	}
	file2.close();
	file_clear.close();

	std::cout << "Votre fichier déchiffré est : " << std::endl << filename_clear << std::endl;
	delete[] message;

	return 0;
}