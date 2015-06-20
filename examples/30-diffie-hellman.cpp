#include "../cryptoLib.h"
#include "iostream"

int main(int argc, char const *argv[])
{
	mpz2_class a,b,A,B,p,g,S_A,S_B;
	p="0xB10B8F96A080E01DDE92DE5EAE5D54EC52C99FBCFB06A3C69A6A9DCA52D23B616073E28675A23D189838EF1E2EE652C013ECB4AEA906112324975C3CD49B83BFACCBDD7D90C4BD7098488E9C219A73724EFFD6FAE5644738FAA31A4FF55BCCC0A151AF5F0DC8B4BD45BF37DF365C1A65E68CFDA76D4DA708DF1FB2BC2E4A4371";
	g="0xA4D1CBD5C3FD34126765A442EFB99905F8104DD258AC507FD6406CFF14266D31266FEA1E5C41564B777E690F5504F213160217B4B01B886A5E91547F9E2749F4D7FBD7D3B9A92EE1909D0D2263F80A76A6A24C087A091F531DBF0A0169B6A28AD662A4D18E73AFA32D779D5918D08BC8858F4DCEF97C2A24855E6EEB22B3B2E5";
	std::cout <<"\nThe Diffie_Hellman algorithm use two parameters common for the two users, a prime number \"p\" and a generator of the cyclic group Z/pZ \n "<< std::endl;
	std::cout <<"We will use here default settings that are:" << std::endl;
	std::cout <<"p = "<< p << std::endl;
	std::cout <<"\nAnd as a generator g = "<< g << std::endl;


	std::cout << "\nEnter the integer secret number from Alice" << std::endl;
	std::cin >> a;
	std::cout << "Enter the interger secret number from Bob" << std::endl;
	std::cin >> b;
	std::cout << "\nFirstly Alice will calculate g^A mod p" << std::endl;
	A = diffieHellmann_step1(a, p, g);
	std::cout << "g^a mod p = " << A << std::endl;
	std::cout << "\nAt the same time Bob will calculate g^B mod p" << std::endl;
	B = diffieHellmann_step1(b, p, g);
	std::cout << "g^b mod p = " << B << std::endl;
	std::cout << "\nThen Alice send g^a mod p to Bob and Bob send g^b mod p to Alice";
	std::cout << "\nAt this point Alice knows her secret number \"a\" , \"g^a mod p\" and \"g^b mod p\" " << std::endl;
	std::cout << "And Bob knows his secret number \"b\" , \"g^b mod p\" and  \"g^a mod p\" " << std::endl;
	std::cout << "\nSo last step, Alice does S_A=(g^b)^a mod p" << std::endl;
	S_A = diffieHellmann_step2(a, p, B);
	std::cout << "S_A = " << S_A << std::endl;
	S_B = diffieHellmann_step2(b,p,A);
	std::cout << "\nAt the same time Bob does S_B=(g^a)^b mod p" << std::endl;
	std::cout << "S_B = " << S_A << std::endl;
	std::cout << "\nAs you can see S_A = S_B so now Alice and Bob have a common key S = " << S_A <<std::endl;
	return 0;
}