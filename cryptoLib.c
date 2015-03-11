#include "cryptoLib.h"


void crypto_pow(mpz_t dest, mpz_t a, unsigned long p)
{
	//Init vars
	mpz_t newA;

	//We cannot deal with negatif power in this algo
	if(p < 0)
		return;

	//Duplicate a to be sure it will not be modified (nether re allocate at each recursive level)
	mpz_init_set(newA, a);

	//Start the recursiv loop
	crypto_pow_recur(dest, newA, p);

}

void crypto_pow_recur(mpz_t dest, mpz_t a, unsigned long p)
{
	if(p%2 == 0) //If p is even
	{
		//a = a*a
		mpz_mul(a, a, a);
		crypto_pow_recur(dest, a, p/2);
	}
	else if(p <= 1) //If not (any) operations needed
	{
		mpz_set(dest, a);
	}
	else //If p is odd
	{
		//We duplicate `a` because we need it after crypto_pow_recur that will edit our `a`
		mpz_t newA;
		mpz_init_set(newA, a);

		//a = a*a
		mpz_mul(a, a, a);
		crypto_pow_recur(dest, a, (p-1)/2);
		mpz_mul(dest, dest, newA);
	}

}

void crypto_pow_classic(mpz_t dest, mpz_t a, unsigned long p)
{
	unsigned long i;

	//We cannot deal with negatif power
	if(p < 0)
		return;
	if(p == 1)
		mpz_set(dest, a);
	else
	{
		mpz_mul(dest, a, a);
		for (i = 2; i < p; ++i)
		{
			mpz_mul(dest, dest, a);
		}
	}
}