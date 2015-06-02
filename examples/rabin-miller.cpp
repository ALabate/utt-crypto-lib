#include "../cryptoLib.h"
#include "iostream"


int main(int argc, char const *argv[])
{
	int k;
	std::string nb;
	std::cout << "Entrer un nombre a tester" << std::endl;
	std::cin >> nb;

	std::cout << "Entrer le nombre de test à faire" << std::endl;
	std::cin >> k;

	if (crypto_primality_test(mpz2_class(nb), k))
	{
		std::cout << "Le nombre est très probablement premier" << std::endl;
		probability= pow(4,-k);
	std::cout << "La probabilité d'avoir déclaré " << n << " probablement premier alors qu'il ne l'est pas est de " << probability << std::endl;
	}
	else
	{
		std::cout << "Le nombre n'est pas premier" << std::endl;
	}
	return 0;
}
