#include "../cryptoLib.h"
#include "iostream"

int main(int argc, char const *argv[])
{
	mpz2_class b,ga, g, p, gb, randStart, randEnd, message, encryptedMessage;
	char reponse[1];

	std::cout << "Voulez-vous choisir votre nombre secret  N/o?(par défaut le programme choisi un nombre aléatoire)" << std::endl;
	std::cin >> reponse;
	if (reponse[0] == 'o' || reponse[0] == 'O')
	{
		std::cout << "Quel est votre nombre secret?" << std::endl;
		std::cin >> b;
	}
	else 
	{
		randStart = mpz2_class(1) << (1023);
		randEnd = (mpz2_class(1) << 1024) - 1;
		b.setRandom(randStart, randEnd);
		std::cout << "Votre nombre secret est : "<< b << std::endl;
	}

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
		p = 0;
		g = 0;
	}
	
	gb = elGamal_keyGenerator(b, p, g);

	std::cout << "Quel est la clé publique de votre correspondant?" << std::endl;
	std::cin >> ga;

	std::cout << "Quel est votre message à coder?" << std::endl;
	std::cin >> message;

	encryptedMessage = elGamal_encryption(gb, b, ga, message, p, g);

	std::cout << "Votre clé publique est : " << gb << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Votre message codé est : " << encryptedMessage << std::endl;
	std::cout << std::endl;


	return 0;
}