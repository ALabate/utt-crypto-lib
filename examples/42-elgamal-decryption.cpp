#include "../cryptoLib.h"
#include "iostream"

int main(int argc, char const *argv[])
{
	mpz2_class a, p, g, gb, encryptedMessage, decryptedMessage;

	char reponse[1];
	
	std::cout << "Quel est la clé publique de votre correspondant?" << std::endl;
	std::cin >> gb;

	std::cout << "Quel est le message crypté?" << std::endl;
	std::cin >> encryptedMessage;

	std::cout << "Quel est votre clé secrète?" << std::endl;
	std::cin >> a;

	std::cout << "Le nombre premier et son générateur sont ils ceux par défaut? O/n " << std::endl;
	std::cin >> reponse;
	if (reponse[0] == 'n' || reponse[0] == 'N')
	{
		std::cout << "Quel est alors le nombre premier?" << std::endl;
		std::cin >> p;
		std::cout << "Quel est son gnénérateur?" << std::endl;
		std::cin >> g;
	}
	else 
	{
		p = "0xB10B8F96A080E01DDE92DE5EAE5D54EC52C99FBCFB06A3C69A6A9DCA52D23B616073E28675A23D189838EF1E2EE652C013ECB4AEA906112324975C3CD49B83BFACCBDD7D90C4BD7098488E9C219A73724EFFD6FAE5644738FAA31A4FF55BCCC0A151AF5F0DC8B4BD45BF37DF365C1A65E68CFDA76D4DA708DF1FB2BC2E4A4371";

	}

	decryptedMessage = (encryptedMessage / gb.powmod(a,p)) % p ;

	std::cout << "Le message décrypté est : " << decryptedMessage << std::endl;

	return 0;
}