#include "../cryptoLib.h"
#include "iostream"

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

	std::cout << "Quel est votre message text à coder?" << std::endl;
	std::getline(std::cin, message);

	//Chiffrement
	filename = std::string("rsa-txt-msg-") + usr_a + ".tmp";
	std::ofstream file2 (filename.c_str(), std::ifstream::binary | std::ofstream::trunc);
	unsigned long count =  (message.length() + Crypto::rsa_blockBytes - 1) / Crypto::rsa_blockBytes;
	for (int i = 0; i < count; ++i)
	{
		m = Crypto::buf_split(message.c_str(), i, Crypto::rsa_blockBytes, message.length()+1);
		encryptedMessage = Crypto::rsa_encrypt(m, b_pub);
		Crypto::file_append(file2, Crypto::rsa_cryptedBlockBytes, encryptedMessage);
	}
	file2.close();

	std::cout << "Le nombre non-chiffré est : 0x" << std::hex << m << std::endl;
	std::cout << "Le nombre chiffré est : 0x" << std::hex << encryptedMessage << std::endl;
	std::cout << "Votre message codé est stocké dans : " << std::endl << filename << std::endl;


	return 0;
}

