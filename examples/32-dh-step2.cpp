#include "../cryptoLib.h"
#include "iostream"

int main(int argc, char const *argv[])
{
	mpz2_class a, a_pub, b_pub, commonKey;
	char usr_a, usr_b;

	std::cout << "\nAre you a or b" << std::endl;
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

	std::cout << "\nEnter your integer secret key" << std::endl;
	std::cin >> a;

	std::cout << std::endl << "===================== Step 0 =====================" << std::endl;
	std::cout << "This algorithm use two parameters common for the two users and known by everyone :" << std::endl;
	std::cout << "A prime number \"p\" :" << std::endl;
	std::cout <<"    p = 0x"<< std::hex << Crypto::dh_p << std::endl;
	std::cout << std::endl << "A generator of the cyclic group Z/pZ \"g\" :" << std::endl;
	std::cout <<"    g = 0x"<< std::hex << Crypto::dh_g << std::endl;

	std::cout << std::endl << "===================== Step 1 =====================" << std::endl;
	std::cout << "   You choose a secret key" << std::endl;
	std::cout << "   " << usr_a << " = 0x" << std::hex << a << std::endl;
	std::cout << "   Then you calculate " << usr_a << "_pub = g^" << usr_a << " mod p" << std::endl;
	a_pub = Crypto::dh_step1(a);
	std::cout << "   " << usr_a << "_pub = 0x" << std::hex << a_pub << std::endl;

	std::cout << std::endl << "===================== Step 2 =====================" << std::endl;
	std::cout << "You have to send " << usr_a << "_pub to Bob and bob have to send you his " << usr_b << "_pub" << std::endl;

	std::cout << "You have send " << usr_a << "_pub to Bob and you have received " << usr_b << "_pub from bob in the file \"dh-pub-" << usr_b << ".tmp\"" << std::endl;

	FILE *file;
	std::string filename = std::string("dh-pub-") + usr_b + ".tmp";
	file = fopen(filename.c_str(), "r");
	if(file == NULL)
  	{
		std::cout << std::endl << "Error : " << filename <<" not found" << std::endl;
		return 1;
	}
	b_pub.inp_str(file, 16);
	fclose(file);
	std::cout << "   " << usr_b << "_pub = g^" << usr_b << " mod p = 0x" << std::hex << b_pub << std::endl;

	std::cout << std::endl << "===================== Step 4 =====================" << std::endl;
	std::cout << "   You calculate commonKey = (g^" << usr_b << ")^" << usr_a << " mod p" << std::endl;
	commonKey = Crypto::dh_step2(a, b_pub);
	std::cout << "   commonKey = 0x" << std::hex << commonKey << std::endl;
	std::cout << std::endl << "===================== Conclusion =====================" << std::endl;
	std::cout << usr_b << " should have exactly the same key" <<std::endl;
	return 0;
}