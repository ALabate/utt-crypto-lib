#include <iostream>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	std::string input;
	std::cout << "Que souhaitez vous faire ?" << std::endl;
	std::cout << " 1-Comparer les performances des algorithmes" << std::endl;
	std::cout << " 2-Jouer avec les nombres premiers" << std::endl;
	std::cout << " 3-Echanger une clé avec Diffie-Hellman" << std::endl;
	std::cout << " 4-Chiffrer un message avec ElGamal" << std::endl;
	std::cout << " 5-Chiffre un message avec RSA" << std::endl;
	std::cout << " 6-Générer la signature d'un message avec ElGamal" << std::endl;
	std::cout << " 7-Générer la signature d'un message avec RSA" << std::endl;
	std::cin >> input;

	switch(input[0])
	{
		case '1': //Perf
			std::cout << "Quels algorithmes souhaitez vous tester ?" << std::endl;
			std::cout << " 1-Algorithmes de calcul de puissance" << std::endl;
			std::cout << " 2-Test de primalité avec Rabin-Miller" << std::endl;
			std::cin >> input;
			switch(input[0])
			{
				case '1': //Power
					system("make example run src=10-power");
					break;
				case '2': //Rabin miller prime test
					system("make example run src=11-prime");
					break;
			}
			break;
		case '2': //Play with prime numbers
			std::cout << "Que souhaitez vous faire ?" << std::endl;
			std::cout << " 1-Tester si un nombre est premier avec Rabin-Miller" << std::endl;
			std::cout << " 2-Afficher la liste des nombres premiers" << std::endl;
			std::cout << " 3-Trouver un nombre premier de n bits" << std::endl;
			std::cin >> input;
			switch(input[0])
			{
				case '1': //Simple rabin miller
					system("make example run src=20-rabin-miller");
					break;
				case '2': //Show prime number list
					system("make example run src=21-prime-list");
					break;
				case '3': //Find a prime number
					system("make example run src=22-found-prime");
					break;
			}
			break;
	}
	return 0;
}
