#include "../cryptoLib.h"
#include "iostream"

int main(int argc, char const *argv[])
{
	mpz2_class a, g, p, a_pub, randStart, randEnd;
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
		usr_a = 'a';
		usr_b = 'b';
	}

	// std::cout << "Voulez-vous choisir votre nombre secret  N/o?(par défaut le programme choisi un nombre aléatoire)" << std::endl;
	// std::cin >> reponse;
	// if (reponse == 'o' || reponse == 'O')
	// {
	// 	std::cout << "Quel est votre nombre secret?" << std::endl;
	// 	std::cin >> a;
	// }
	// else 
	// {
		randStart = mpz2_class(1) << (1023);
		randEnd = (mpz2_class(1) << 1024) - 1;
		a.setRandom(randStart, randEnd);
		std::cout << "Votre nombre secret est : 0x" << std::hex << a << std::endl;
	// }

	// std::cout << "Voulez-vous choisir un nombre premier et son générateur  N/o? (si non, les paramètres par défaut seront utilisés)" << std::endl;
	// std::cin >> reponse;
	// if (reponse == 'o' || reponse == 'O')
	// {
	// 	std::cout << "Quel est alors le nombre premier?" << std::endl;
	// 	std::cin >> p;
	// 	std::cout << "Quel est son gnénérateur?" << std::endl;
	// 	std::cin >> g;
	// }
	// else 
	// {
		p = 0;
		g = 0;
	// }

	a_pub = Crypto::eg_generateKey(a, p, g);

	FILE *file;
	std::string filename = std::string("eg-pub-") + usr_a + ".tmp";
	file = fopen(filename.c_str(), "w");
	a_pub.out_str(file, 16);
	fclose(file);

	std::cout << "Votre clé publique est : 0x" << std::hex << a_pub << std::endl;
	std::cout << "Elle a été stocké dans le fichier : " << filename << std::endl;


	filename = std::string("eg-priv-") + usr_a + ".tmp";
	file = fopen(filename.c_str(), "w");
	a.out_str(file, 16);
	fclose(file);

	std::cout << "Votre clé privée est dans le fichier : " << filename << std::endl;

	return 0;
}