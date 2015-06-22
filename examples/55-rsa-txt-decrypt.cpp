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
	filename = std::string("rsa-txt-msg-") + usr_b + ".tmp";
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
	int i = 0;
	for (int i = 0; i < count; ++i)
	{
		encryptedMessage = Crypto::file_split(file2, Crypto::rsa_cryptedBlockBytes);
		decryptedMessage = Crypto::rsa_decrypt(encryptedMessage, a_pub, a_priv);
		Crypto::buf_append(message, i, Crypto::rsa_blockBytes, decryptedMessage);
	}
	file2.close();

	std::cout << "Le nombre chiffré est : 0x" << std::hex << encryptedMessage << std::endl;
	std::cout << "Le nombre déchiffré est : 0x" << std::hex << decryptedMessage << std::endl;
	std::cout << "Le message déchiffré est : " << message << std::endl;
	delete[] message;

	return 0;
}