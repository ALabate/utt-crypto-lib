#include <iostream>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	std::string input;
	input[0] = ' ';
	while(input[0] != '0')
	{
		std::cout << "=== Menu principal ===" << std::endl;
		std::cout << "Que souhaitez vous faire ?" << std::endl;
		std::cout << " 1-Comparer les performances des algorithmes" << std::endl;
		std::cout << " 2-Jouer avec les nombres premiers" << std::endl;
		std::cout << " 3-Echanger une clé avec Diffie-Hellman" << std::endl;
		std::cout << " 4-Chiffrer un message avec ElGamal" << std::endl;
		std::cout << " 5-Chiffre un message avec RSA" << std::endl;
		std::cout << " 6-Générer la signature d'un message avec ElGamal" << std::endl;
		std::cout << " 7-Générer la signature d'un message avec RSA" << std::endl;
		std::cout << std::endl << " 0-Quitter" << std::endl;
		std::cin >> input;

		switch(input[0])
		{
			case '1': //Perf
				while(input[0] != '0')
				{
					std::cout << "=== Comparer les performances des algorithmes ===" << std::endl;
					std::cout << "Quels algorithmes souhaitez vous tester ?" << std::endl;
					std::cout << " 1-Algorithmes de calcul de puissance" << std::endl;
					std::cout << " 2-Test de primalité avec Rabin-Miller" << std::endl;
					std::cout << std::endl << " 0-Menu principal" << std::endl;
					std::cin >> input;
					switch(input[0])
					{
						case '1': //Power
							system("make example run src=10-power --no-print-directory");
							break;
						case '2': //Rabin miller prime test
							system("make example run src=11-prime --no-print-directory");
							break;
					}
					std::cout << std::endl << std::endl;
				}
				input[0] = ' ';
				break;
			case '2': //Play with prime numbers
				while(input[0] != '0')
				{
					std::cout << "=== Jouer avec les nombres premiers ===" << std::endl;
					std::cout << "Que souhaitez vous faire ?" << std::endl;
					std::cout << " 1-Tester si un nombre est premier avec Rabin-Miller" << std::endl;
					std::cout << " 2-Afficher la liste des nombres premiers" << std::endl;
					std::cout << " 3-Trouver un nombre premier de n bits" << std::endl;
					std::cout << std::endl << " 0-Menu principal" << std::endl;
					std::cin >> input;
					switch(input[0])
					{
						case '1': //Simple rabin miller
							system("make example run src=20-rabin-miller --no-print-directory");
							break;
						case '2': //Show prime number list
							system("make example run src=21-prime-list --no-print-directory");
							break;
						case '3': //Find a prime number
							system("make example run src=22-found-prime --no-print-directory");
							break;
					}
					std::cout << std::endl << std::endl;
				}
				input[0] = ' ';
				break;
			case '3': //Diffie hellman
				while(input[0] != '0')
				{
					std::cout << "=== Echanger une clé avec Diffie-Hellman ===" << std::endl;
					std::cout << "Que souhaitez vous faire ?" << std::endl;
					std::cout << " 1-Afficher l'ensemble de l'echange de clés" << std::endl;
					std::cout << " 2-Etape 1 de l'algorithme" << std::endl;
					std::cout << " 3-Etape 2 de l'algorithme" << std::endl;
					std::cout << std::endl << " 0-Menu principal" << std::endl;
					std::cin >> input;
					switch(input[0])
					{
						case '1':
							system("make example run src=30-diffie-hellman --no-print-directory");
							break;
						case '2':
							system("make example run src=31-dh-step1 --no-print-directory");
							break;
						case '3':
							system("make example run src=32-dh-step2 --no-print-directory");
							break;
					}
					std::cout << std::endl << std::endl;
				}
				input[0] = ' ';
				break;
			case '4': //ElGamal
				while(input[0] != '0')
				{
					std::cout << "=== Chiffrer un message avec ElGamal ===" << std::endl;
					std::cout << "Que souhaitez vous faire ?" << std::endl;
					std::cout << " 1-Afficher l'ensemble de l'echange de message" << std::endl;
					std::cout << " 2-Generer des cles" << std::endl;
					std::cout << " 3-Chiffre un nombre" << std::endl;
					std::cout << " 4-Déchiffrer un nombre" << std::endl;
					std::cout << " 5-Chiffre un fichier" << std::endl;
					std::cout << " 6-Déchiffrer un fichier" << std::endl;
					std::cout << std::endl << " 0-Menu principal" << std::endl;
					std::cin >> input;
					switch(input[0])
					{
						case '1':
							system("make example run src=40-elgamal --no-print-directory");
							break;
						case '2':
							system("make example run src=41-eg-generatekey --no-print-directory");
							break;
						case '3':
							system("make example run src=42-eg-encrypt --no-print-directory");
							break;
						case '4':
							system("make example run src=43-eg-decrypt --no-print-directory");
							break;
					}
					std::cout << std::endl << std::endl;
				}
				input[0] = ' ';
				break;
		}
	}
	return 0;
}
