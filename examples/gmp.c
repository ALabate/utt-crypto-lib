#include <stdio.h>
#include <gmp.h>
 
int main(int argc, char *argv[])
{
	//Init the three big numbers (integer) that we will manipulate
	mpz_t a, b, c;

	//Init vars that will contain string value of our big numbers (NULL is important)
	char *a_str = NULL, *b_str = NULL, *c_str = NULL;

	//Set a to a big number in base 10
	mpz_init_set_str(a, "148189247128974289127484021983013239823", 10);

	//Set a to a small number in hexadecimal
	mpz_init_set_str(b, "A", 16);

	//c=a+b
	mpz_add(c, a, b);

	//Convert to strings
	a_str = mpz_get_str(NULL, 10, a);
	b_str = mpz_get_str(NULL, 10, b);
	c_str = mpz_get_str(NULL, 10, c);

	//Print output
	printf("%s + %s = %s\n", a_str, b_str, c_str);


	return 0;
}