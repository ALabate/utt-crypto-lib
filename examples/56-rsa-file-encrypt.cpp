#include "../cryptoLib.h"
#include "iostream"
#include <unistd.h>
#include <linux/limits.h>


int main(int argc, char const *argv[])
{
	mpz2_class b_pub, encryptedMessage, m;
	char usr_a, usr_b;
	std::string message, filename;
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
	std::getline(std::cin, message);

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

	//Get current path
    char buff[PATH_MAX];
    getcwd(buff, PATH_MAX);
	std::cout << "Sachant que nous sommes ici : " << buff << std::endl;

   	std::string filename_clear;
	std::cout << "Quel fichier voullez vous chiffrer ?" << std::endl;
	std::getline(std::cin, filename_clear);

	//Get clear file
	std::ifstream file_clear (filename_clear.c_str(), std::ifstream::binary);
	if(!file_clear.is_open())
	{
		std::cout << std::endl << "Error : " << filename_clear <<" not found" << std::endl;
		return 1;
	}

    // get length of file:
    file_clear.seekg (0, file_clear.end);
    int length = file_clear.tellg();
    file_clear.seekg (0, file_clear.beg);


	//Chiffrement
	filename = filename_clear + ".rsa.tmp";
	std::ofstream file2 (filename.c_str(), std::ifstream::binary | std::ofstream::trunc);
	unsigned long count =  (length + Crypto::rsa_blockBytes - 1) / Crypto::rsa_blockBytes;
	for (int i = 0; i < count; ++i)
	{
		m = Crypto::file_split(file_clear, Crypto::rsa_blockBytes);
		encryptedMessage = Crypto::rsa_encrypt(m, b_pub);
		Crypto::file_append(file2, Crypto::rsa_cryptedBlockBytes, encryptedMessage);
	}
	file_clear.close();
	file2.close();

	std::cout << "Votre fichier chiffré est : " << std::endl << filename << std::endl;


	return 0;
}