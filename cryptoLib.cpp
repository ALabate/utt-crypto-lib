#include "cryptoLib.h"
#include <iostream>

const mpz2_class Crypto::dh_p = "0xB10B8F96A080E01DDE92DE5EAE5D54EC52C99FBCFB06A3C69A6A9DCA52D23B616073E28675A23D189838EF1E2EE652C013ECB4AEA906112324975C3CD49B83BFACCBDD7D90C4BD7098488E9C219A73724EFFD6FAE5644738FAA31A4FF55BCCC0A151AF5F0DC8B4BD45BF37DF365C1A65E68CFDA76D4DA708DF1FB2BC2E4A4371";
const mpz2_class Crypto::dh_g = "0xA4D1CBD5C3FD34126765A442EFB99905F8104DD258AC507FD6406CFF14266D31266FEA1E5C41564B777E690F5504F213160217B4B01B886A5E91547F9E2749F4D7FBD7D3B9A92EE1909D0D2263F80A76A6A24C087A091F531DBF0A0169B6A28AD662A4D18E73AFA32D779D5918D08BC8858F4DCEF97C2A24855E6EEB22B3B2E5";
const unsigned long Crypto::dh_blockBytes = 127;
const unsigned long Crypto::dh_cryptedBlockBytes = 255;

mpz2_class Crypto::pow(mpz2_class a, unsigned long p)
{

	if(p <= 1) //If finished
	{
		if(p == 0)
			return 1;
		else
			return a;
	}
	else if(p%2 == 0) //If p is even
	{
		return Crypto::pow(a*a, p/2);
	}
	else //If p is odd
	{
		return Crypto::pow(a*a, (p-1)/2) * a;
	}
}

mpz2_class Crypto::pow_classic(mpz2_class a, unsigned long p)
{
	mpz2_class rtn;
	rtn = 1;

	// Loop p times
	for ( ; p > 0 ; p--)
	{
		rtn = rtn * a;
	}
	return rtn;
}

bool Crypto::rm_probabPrime(mpz2_class n, int k)
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




mpz2_class Crypto::dh_step1(mpz2_class a, mpz2_class p, mpz2_class g)
{
	if (p == 0)
	{
		p = Crypto::dh_p;
	}
	if (g == 0)
	{
		g = Crypto::dh_g;
	}

	// We compute g^a mod p.
	mpz2_class A;
	A = g.powmod(a,p);
	return A;
}

mpz2_class Crypto::dh_step2(mpz2_class a, mpz2_class b_pub, mpz2_class p)
{
	if (p == 0)
	{
		p = Crypto::dh_p;
	}

	// We compute B^a mod p.
	mpz2_class S;
	S = b_pub.powmod(a,p);
	return S;
}




mpz2_class Crypto::eg_generateKey(mpz2_class a, mpz2_class p, mpz2_class g)
{
	return Crypto::dh_step1(a, p, g);
}

mpz2_class Crypto::eg_encrypt(mpz2_class a, mpz2_class b_pub, mpz2_class message, mpz2_class p)
{
	if(p == 0) {
		p = Crypto::dh_p;
	}

	mpz2_class commonKey, encryptedMessage;

	commonKey = Crypto::dh_step2(a, b_pub, p);
	encryptedMessage = message * commonKey;
	return encryptedMessage;
}

mpz2_class Crypto::eg_decrypt(mpz2_class a, mpz2_class b_pub, mpz2_class encryptedMessage, mpz2_class p)
{
	if (p == 0) {
		p = Crypto::dh_p;
	}

	mpz2_class commonKey, decryptedMessage; 

	commonKey = Crypto::dh_step2(a, b_pub, p);
	decryptedMessage = encryptedMessage/commonKey;
	return decryptedMessage;
}




void Crypto::rsa_generateKey(mpz2_class &n, mpz2_class &d, mpz2_class &e, unsigned long bitlength)
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
	} while((p%2 == 0) || !p.probab_prime(25));

	do {
		q.setRandom(randStart, randEnd);
	} while((q%2 == 0) || (q == p) || !q.probab_prime(25));

	d = e.invertmod((p-1)*(q-1));
	n = p*q;
}

mpz2_class Crypto::rsa_encrypt(mpz2_class message, mpz2_class e, mpz2_class n)
{
	return message.powmod(e, n);
}

mpz2_class Crypto::rsa_decrypt(mpz2_class encryptedMessage, mpz2_class d, mpz2_class n)
{
	return encryptedMessage.powmod(d, n);
}



mpz2_class Crypto::file_split(std::ifstream& file, unsigned long n)
{
	if(!file.is_open())
	{
		fprintf(stderr, "Error : file not found/not opened\n");
		return -1;
	}

	mpz2_class out;
	char* buf = new char [n];
	file.read(buf, n);
	n = file.gcount();

	out.bufImport(buf, n);
	delete[] buf;
	return out;
}

void Crypto::file_append(std::ofstream& file, unsigned long n, mpz2_class value)
{
	if(!file.is_open())
	{
		fprintf(stderr, "Error : file not found/not opened\n");
		return;
	}

	char* buf = new char [n];
	value %= mpz2_class(256).pow(n);
	size_t length = value.bufExport(buf);
	if(length < n)
	{
		char zero = 0;
		for (int i = 0; i < (n-length); ++i)
		{
			file.write(&zero, 1);
		}
	}
	file.write(buf, length);
	delete[] buf;
}

mpz2_class Crypto::buf_split(const char* buf, unsigned long pos, unsigned long n, unsigned long size)
{
	if(size != 0 && size < n*(pos+1))
	{
		n = size - n*pos;
	}

	mpz2_class out;
	char* buf2 = new char [n];

	memcpy(buf2, &buf[pos*n], n);
	out.bufImport(buf2, n);
	delete[] buf2;
	return out;
}

void Crypto::buf_append(const char* buf, unsigned long pos, unsigned long n, mpz2_class value)
{
	char* buf2 = new char [n];
	value %= (mpz2_class(256).pow(n));
	value.bufExport(buf2);
	memcpy((char*) &buf[pos*n], buf2, n);
	delete[] buf2;
}
