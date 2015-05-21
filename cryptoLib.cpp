#include "cryptoLib.hpp"


mpz_class crypto_pow(mpz_class a, unsigned long p)
{

	if(p <= 1) //If finished
	{
		return a;
	}
	else if(p%2 == 0) //If p is even
	{
		return crypto_pow(a*a, p/2);
	}
	else //If p is odd
	{
		return crypto_pow(a*a, (p-1)/2) * a;
	}

}
mpz_class crypto_pow_classic(mpz_class a, unsigned long p)
{
	mpz_class rtn;
	rtn = 1;
	// Loop p times
	for ( ; p > 0 ; p--)
	{
		rtn = rtn * a;
	}
	return rtn;
}
