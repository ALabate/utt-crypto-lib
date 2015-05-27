#include "mpz2_class.h"

mpz2_class::mpz2_class() : mpz_class() {}
mpz2_class::mpz2_class(const short a) : mpz_class(a) {}
mpz2_class::mpz2_class(const unsigned short a) : mpz_class(a) {}
mpz2_class::mpz2_class(const int a) : mpz_class(a) {}
mpz2_class::mpz2_class(const unsigned int a) : mpz_class(a) {}
mpz2_class::mpz2_class(const long a) : mpz_class(a) {}
mpz2_class::mpz2_class(const unsigned long a) : mpz_class(a) {}
mpz2_class::mpz2_class(const float a) : mpz_class(a) {}
mpz2_class::mpz2_class(const double a) : mpz_class(a) {}
mpz2_class::mpz2_class(const mpz_t a) : mpz_class(a) {}
mpz2_class::mpz2_class(const mpz_class& a) : mpz_class(a) {}
mpz2_class::mpz2_class(const mpz2_class& a) : mpz_class(a) {}
mpz2_class::mpz2_class(const char *a, int base) : mpz_class(a, base) {}
mpz2_class::mpz2_class(const std::string& a, int base) : mpz_class(a, base) {}

mpz2_class& mpz2_class::operator=(const short a) { mpz_class::operator=(a); return *this; }
mpz2_class& mpz2_class::operator=(const unsigned short a) { mpz_class::operator=(a); return *this; }
mpz2_class& mpz2_class::operator=(const int a) { mpz_class::operator=(a); return *this; }
mpz2_class& mpz2_class::operator=(const unsigned int a) { mpz_class::operator=(a); return *this; }
mpz2_class& mpz2_class::operator=(const long a) { mpz_class::operator=(a); return *this; }
mpz2_class& mpz2_class::operator=(const unsigned long a) { mpz_class::operator=(a); return *this; }
mpz2_class& mpz2_class::operator=(const float a) { mpz_class::operator=(a); return *this; }
mpz2_class& mpz2_class::operator=(const double a) { mpz_class::operator=(a); return *this; }
mpz2_class& mpz2_class::operator=(const mpz_class& a) { mpz_class::operator=(a); return *this; }
mpz2_class& mpz2_class::operator=(const mpz2_class& a) { mpz_class::operator=(a); return *this; }
mpz2_class& mpz2_class::operator=(const char *a) { mpz_class::operator=(a); return *this; }
mpz2_class& mpz2_class::operator=(const std::string& a) { mpz_class::operator=(a); return *this; }


mpz2_class mpz2_class::operator*(const mpz2_class& b) {
	return (mpz2_class)(((mpz_class)*this) * b);
}

mpz2_class mpz2_class::operator%(const unsigned int b) {
	return (mpz2_class)(((mpz_class)*this) % b);
}
mpz2_class mpz2_class::operator+(const mpz2_class& b) {
	return (mpz2_class)(((mpz_class)*this) + b);
}