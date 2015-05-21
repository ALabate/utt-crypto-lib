/**
 * @brief This show how much the exponentiation by squaring algorithme is better with powers
 */

#include <stdio.h>
#include <gmp.h>
#include <sys/time.h>


void checksum(mpz_t dest, mpz_t input)
{
	mpz_mod_ui(dest, input, 0xffffffff);
}
 
int main(int argc, char *argv[])
{
	//Init the two big numbers (integer) that we will manipulate
	mpz_t a, res, chk;
	unsigned long power;

	//Init vars that will contain string value of our big numbers (NULL is important)
	char *a_str = NULL;

	//Time init
	struct timeval t1, t2;

	//Set numbers
	mpz_init_set_str(a, "148189247128974289127484021983013239823", 10);
	power = 20000;

	//Show operation
	a_str = mpz_get_str(NULL, 10, a);
	printf("Operation : \n  %s ^ %ld\n", a_str, power);

	//Set you have to init res to 0 before using it
	mpz_init(res);
	mpz_init(chk);

	//Classic way of doing res=a^power
	printf("Classic :\n");
	gettimeofday(&t1, NULL);
	crypto_pow_classic(res, a, power);
	gettimeofday(&t2, NULL);
	printf("  Duration : %lf s\n", (double)(t2.tv_usec-t1.tv_usec)/1000000 + (t2.tv_sec-t1.tv_sec));
	checksum(chk, res);
	printf("  Checksum : %s\n", mpz_get_str(NULL, 10, chk));

	//Squaring
	printf("Squaring :\n");
	gettimeofday(&t1, NULL);
	crypto_pow(res, a, power);
	gettimeofday(&t2, NULL);
	printf("  Duration : %lf s\n", (double)(t2.tv_usec-t1.tv_usec)/1000000 + (t2.tv_sec-t1.tv_sec));
	checksum(chk, res);
	printf("  Checksum : %s\n", mpz_get_str(NULL, 10, chk));

	//Internal
	printf("Internal :\n");
	gettimeofday(&t1, NULL);
	mpz_pow_ui(res, a, power);
	gettimeofday(&t2, NULL);
	printf("  Duration : %lf s\n", (double)(t2.tv_usec-t1.tv_usec)/1000000 + (t2.tv_sec-t1.tv_sec));
	checksum(chk, res);
	printf("  Checksum : %s\n", mpz_get_str(NULL, 10, chk));


	//Convert to strings


	return 0;
}