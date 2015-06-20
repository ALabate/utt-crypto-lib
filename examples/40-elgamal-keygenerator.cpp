#include "../cryptoLib.h"
#include "iostream"

int main(int argc, char const *argv[])
{
	mpz2_class a, g, p, ga, randStart, randEnd;
	char reponse[1];

	std::cout << "Voulez-vous choisir votre nombre secret  N/o?(par défaut le programme choisi un nombre aléatoire)" << std::endl;
	std::cin >> reponse;
	if (reponse[0]== 'o' || reponse[0]== 'O')
	{
		std::cout << "Quel est votre nombre secret?" << std::endl;
		std::cin >> a;
	}
	else 
	{
		randStart = mpz2_class(1) << (1023);
		randEnd = (mpz2_class(1) << 1024) - 1;
		a.setRandom(randStart, randEnd);
		std::cout << "Votre nombre secret est : " << a << std::endl;
	}

	std::cout << "Voulez-vous choisir un nombre premier et son générateur  N/o? (si non, les paramètres par défaut seront utilisés)" << std::endl;
	std::cin >> reponse;
	if (reponse[0]== 'o' || reponse[0]== 'O')
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

	ga = elGamal_keyGenerator(a, p, g);

	std::cout << "Votre clé publique est : " << ga << std::endl;

	return 0;
}