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

bool crypto_primality_test(mpz2_class n, int k)
{
	int compteur=0;
	mpz2_class a, s=0, d, x;
	bool do_small_loop=true;

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
		a.setRandom(2, n-1);
		x=a.powmod(d,n);
		do_small_loop=true;
		
		if (x!=1 && x!=n-1)
		{
			for (int j = 1; j < s; ++j)
			{
				x=x.powmod(2,n);
				if (x==1)
				{
					return false;
				}
				else if (x==n-1)
				{
					break;
				}
			}
			if(x != n-1)
			{
				return false;
			}
		}
		
	}
	return true;
	
}

mpz2_class diffieHellmann_step1(mpz2_class a, mpz2_class p, mpz2_class g)
{
	if (p == 0)
	{
		p = "0xB10B8F96A080E01DDE92DE5EAE5D54EC52C99FBCFB06A3C69A6A9DCA52D23B616073E28675A23D189838EF1E2EE652C013ECB4AEA906112324975C3CD49B83BFACCBDD7D90C4BD7098488E9C219A73724EFFD6FAE5644738FAA31A4FF55BCCC0A151AF5F0DC8B4BD45BF37DF365C1A65E68CFDA76D4DA708DF1FB2BC2E4A4371";
	}

	if (g == 0)
	{
		g = "0xA4D1CBD5C3FD34126765A442EFB99905F8104DD258AC507FD6406CFF14266D31266FEA1E5C41564B777E690F5504F213160217B4B01B886A5E91547F9E2749F4D7FBD7D3B9A92EE1909D0D2263F80A76A6A24C087A091F531DBF0A0169B6A28AD662A4D18E73AFA32D779D5918D08BC8858F4DCEF97C2A24855E6EEB22B3B2E5";
	}

	// We compute g^a mod p.
	mpz2_class A;
	A = g.powmod(a,p);
	return A;
}

mpz2_class diffieHellmann_step2(mpz2_class a, mpz2_class B, mpz2_class p)
{
	if (p == 0)
	{
		p = "0xB10B8F96A080E01DDE92DE5EAE5D54EC52C99FBCFB06A3C69A6A9DCA52D23B616073E28675A23D189838EF1E2EE652C013ECB4AEA906112324975C3CD49B83BFACCBDD7D90C4BD7098488E9C219A73724EFFD6FAE5644738FAA31A4FF55BCCC0A151AF5F0DC8B4BD45BF37DF365C1A65E68CFDA76D4DA708DF1FB2BC2E4A4371";
	}

	// We compute B^a mod p.
	mpz2_class S;
	S = B.powmod(a,p);
	return S;
}

void rsa_keyGenerator(mpz2_class &n, mpz2_class &d, mpz2_class &e, unsigned long bitlength)
{
	//Find prime numbers
	mpz2_class p, q;
	mpz2_class randStart, randEnd;

	if(e == 0) {
		e = 65537;
	}

	randStart = mpz2_class(1) << (bitlength - 1);
	randEnd = (mpz2_class(1) << bitlength) - 1;
	do {
		p.setRandom(randStart, randEnd);
	} while((p%2 == 0) || !p.isPrime(25));

	do {
		q.setRandom(randStart, randEnd);
	} while((q%2 == 0) || (q == p) || !q.isPrime(25));

	d = e.invertmod((p-1)*(q-1));
	n = p*q;
}

mpz2_class rsa_encrypt(mpz2_class message, mpz2_class e, mpz2_class n)
{
	return message.powmod(e, n);
}

mpz2_class rsa_decrypt(mpz2_class encryptedMessage, mpz2_class d, mpz2_class n)
{
	return encryptedMessage.powmod(d, n);
}

mpz2_class elGamal_keyGenerator(mpz2_class a, mpz2_class p, mpz2_class g)
{
	return diffieHellmann_step1(a, p, g);
}

mpz2_class elGamal_encryption(mpz2_class& B, mpz2_class b, mpz2_class A, mpz2_class m, mpz2_class p, mpz2_class g)
{
	if (p == 0)
	{
		p = "0xB10B8F96A080E01DDE92DE5EAE5D54EC52C99FBCFB06A3C69A6A9DCA52D23B616073E28675A23D189838EF1E2EE652C013ECB4AEA906112324975C3CD49B83BFACCBDD7D90C4BD7098488E9C219A73724EFFD6FAE5644738FAA31A4FF55BCCC0A151AF5F0DC8B4BD45BF37DF365C1A65E68CFDA76D4DA708DF1FB2BC2E4A4371";
	}
	mpz2_class encryptedMessage;
	B = diffieHellmann_step1(b, p, g);
	encryptedMessage = m*A.powmod(b,p);
	return encryptedMessage;
}

mpz2_class elGamal_decryption(mpz2_class& B, mpz2_class a, mpz2_class encryptedMessage, mpz2_class p)
{
	mpz2_class commonKey, decryptedMessage; 
	if (p == 0)
	{
		p = "0xB10B8F96A080E01DDE92DE5EAE5D54EC52C99FBCFB06A3C69A6A9DCA52D23B616073E28675A23D189838EF1E2EE652C013ECB4AEA906112324975C3CD49B83BFACCBDD7D90C4BD7098488E9C219A73724EFFD6FAE5644738FAA31A4FF55BCCC0A151AF5F0DC8B4BD45BF37DF365C1A65E68CFDA76D4DA708DF1FB2BC2E4A4371";
	}
	commonKey = B.powmod(a,p);
	decryptedMessage = encryptedMessage/commonKey;
	return decryptedMessage;
}
