/**
 * @brief This show how much the exponentiation by squaring algorithme is better with powers
 */

#include <stdio.h>
#include <gmp.h>
#include <sys/time.h>
 
int main(int argc, char *argv[])
{
	//Init the two big numbers (integer) that we will manipulate
	mpz_t a, c;
	unsigned long b;

	//Init vars that will contain string value of our big numbers (NULL is important)
	char *a_str = NULL, *c_str = NULL;

	//Other init
	struct timeval t1, t2;

	//Set a to a big number in base 10
	mpz_init_set_str(a, "148189247128974289127484021983013239823", 10);

	//Set a to a small number to the power
	b = 20000;

	//Set you have to init c to 0 before using it
	mpz_init(c);

	//Classic way of doing c=a^b
	printf("Classic : ");
	gettimeofday(&t1, NULL);
	crypto_pow_classic(c, a, b);
	gettimeofday(&t2, NULL);
	printf("%lf s\n", (double)(t2.tv_usec-t1.tv_usec)/1000000 + (t2.tv_sec-t1.tv_sec));

	//Squaring
	printf("Squaring : ");
	gettimeofday(&t1, NULL);
	crypto_pow(c, a, b);
	gettimeofday(&t2, NULL);
	printf("%lf s\n", (double)(t2.tv_usec-t1.tv_usec)/1000000 + (t2.tv_sec-t1.tv_sec));

	//Internal
	printf("Internal : ");
	gettimeofday(&t1, NULL);
	mpz_pow_ui(c, a, b);
	gettimeofday(&t2, NULL);
	printf("%lf s\n", (double)(t2.tv_usec-t1.tv_usec)/1000000 + (t2.tv_sec-t1.tv_sec));


	//Convert to strings
	a_str = mpz_get_str(NULL, 10, a);
	// c_str = mpz_get_str(NULL, 10, c); // Too long ..

	//Print output
	printf("Operation : %s^%ld\n", a_str, b);


	return 0;
}