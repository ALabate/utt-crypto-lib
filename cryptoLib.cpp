#include "cryptoLib.h"


// mpz2_class crypto_pow(mpz2_class a, unsigned long p)
// {

// 	if(p <= 1) //If finished
// 	{
// 		if(p == 0)
// 			return 1;
// 		else
// 			return a;
// 	}
// 	else if(p%2 == 0) //If p is even
// 	{
// 		return crypto_pow(a*a, p/2);
// 	}
// 	else //If p is odd
// 	{
// 		return crypto_pow(a*a, (p-1)/2) * a;
// 	}
// }

// mpz2_class crypto_pow_classic(mpz2_class a, unsigned long p)
// {
// 	mpz2_class rtn;
// 	rtn = 1;

// 	// Loop p times
// 	for ( ; p > 0 ; p--)
// 	{
// 		rtn = rtn * a;
// 	}
// 	return rtn;
// }
