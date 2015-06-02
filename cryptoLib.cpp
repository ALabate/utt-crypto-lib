#include "cryptoLib.h"
#include "iostream"
#include "cmath"


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

bool crypto_primality_test(mpz2_class n, int k)
{
	int compteur=0;
	mpz2_class a, s=0, d, x, m=n-2;
	bool do_small_loop=true;
	gmp_randstate_t state;
	gmp_randinit_default (state);

	if (k<1)
	{
		return false;
	}

	if (n==1 || n==2 || n==3) //We check if n is a prime number lower than 3
	{
		return true;
	}
	if (n<2 || n%2 == 0) //If p is even it can't be prime.
	{
		return false;
	}
	
	/* s is the number of times that 2 divide n-1.
		so we will have 2^s*d=n-1 */
	d = n-1;
	while (d%2==0)
	{
		d/=2;
		s++;
	}
	/* We pick some a in range [2,n-1] and then check whether a^s = 1 ( mod p ) or a(s*(2r)) = -1 ( mod p ). 
		If both of them fail, then p is definitely composite. Otherwise p is probably prime. 
		We choose another a and repeat the same test.*/
	for (int i = 0; i < k; ++i)
	{
		mpz_urandomm (a.get_mpz_t(), state, m.get_mpz_t());
		x=a.powmod(d,n);
		do_small_loop=true;
		
		if (x!=1 && x!=n-1)
		{
			for (int j = 0; j < s; ++j)
			{
				x=(x*x)%n;
				if (x==1)
				{
					return false;
				}
				if (x==n-1)
				{
					break;
				}
				return false;
			}
			
		}
		
	}
	return true;
	
}

