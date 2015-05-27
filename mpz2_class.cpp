#include "mpz2_class.h"


mpz2_class::mpz2_class() : mpz_class() {}
mpz2_class::mpz2_class(const unsigned int a) : mpz_class(a) {}
mpz2_class::mpz2_class(const char* a) : mpz_class(a) {}
mpz2_class::mpz2_class(const mpz2_class& a) : mpz_class(a) {}
mpz2_class::mpz2_class(const mpz_class& a) : mpz_class(a) {}

mpz2_class& mpz2_class::operator=(const mpz2_class& b)
{
	mpz_class::operator=(b);
	return *this;
}

mpz2_class mpz2_class::operator*(const mpz2_class& b)
{
	return (mpz2_class)(((mpz_class)*this) * b);
}

mpz2_class mpz2_class::operator%(const unsigned int b)
{
	return (mpz2_class)(((mpz_class)*this) % b);
}
mpz2_class mpz2_class::operator+(const mpz2_class& b)
{
	return (mpz2_class)(((mpz_class)*this) + b);
}