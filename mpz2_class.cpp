#include "mpz2_class.h"

gmp_randstate_t mpz2_class::randState = {};
bool mpz2_class::randInit = false;

//Constructors
mpz2_class::mpz2_class() : mpz_class() {}
mpz2_class::mpz2_class(const short a) : mpz_class(a) {}
mpz2_class::mpz2_class(const unsigned short a) : mpz_class(a) {}
mpz2_class::mpz2_class(const int a) : mpz_class(a) {}
mpz2_class::mpz2_class(const unsigned int a) : mpz_class(a) {}
mpz2_class::mpz2_class(const long a) : mpz_class(a) {}
mpz2_class::mpz2_class(const unsigned long a) : mpz_class(a) {}
mpz2_class::mpz2_class(const float a) : mpz_class(a) {}
mpz2_class::mpz2_class(const double a) : mpz_class(a) {}
mpz2_class::mpz2_class(const mpq_t a) : mpz_class() { mpz_set_q((*this).get_mpz_t(), a);}
mpz2_class::mpz2_class(const mpf_t a) : mpz_class() { mpz_set_f((*this).get_mpz_t(), a);}
mpz2_class::mpz2_class(const mpz_t a) : mpz_class(a) {}
mpz2_class::mpz2_class(const mpz_class& a) : mpz_class(a) {}
mpz2_class::mpz2_class(const mpz2_class& a) : mpz_class(a) {}
mpz2_class::mpz2_class(const char *a, int base) : mpz_class(a, base) {}
mpz2_class::mpz2_class(const std::string& a, int base) : mpz_class(a, base) {}


void mpz2_class::clear() {
	mpz_clear((*this).get_mpz_t());
}

mpz2_class& mpz2_class::swap(mpz2_class& b) {
	mpz_swap((*this).get_mpz_t(), b.get_mpz_t());
	return *this;
}

mpz2_class mpz2_class::abs() {
	mpz2_class a;
	mpz_abs(a.get_mpz_t(), (*this).get_mpz_t());
	return a;
}

mpz2_class mpz2_class::divisible(const mpz2_class a) {
	return mpz_divisible_p((*this).get_mpz_t(), mpz2_class(a).get_mpz_t());
}
	
mpz2_class mpz2_class::congruent(const mpz2_class a, const mpz2_class b) {
	return mpz_congruent_p((*this).get_mpz_t(), a.get_mpz_t(), b.get_mpz_t());
}

mpz2_class mpz2_class::pow(const unsigned long a) {
	mpz2_class ret;
	mpz_pow_ui(ret.get_mpz_t(), (*this).get_mpz_t(), a);
	return ret;
}

mpz2_class mpz2_class::powmod(const mpz2_class a, const mpz2_class mod) {
	mpz2_class ret;
	mpz_powm(ret.get_mpz_t(), (*this).get_mpz_t(), mpz2_class(a).get_mpz_t(), mod.get_mpz_t());
	return ret;
}

mpz2_class mpz2_class::root(const unsigned long pow) {
	mpz2_class ret;
	mpz_root(ret.get_mpz_t(), (*this).get_mpz_t(), pow);
	return ret;
}
mpz2_class mpz2_class::root(const unsigned long pow, bool& exact) {
	mpz2_class ret;
	exact = (mpz_root(ret.get_mpz_t(), (*this).get_mpz_t(), pow) != 0);
	// exact = 1;
	return ret;
}
mpz2_class mpz2_class::root(const unsigned long pow, mpz2_class& remainder) {
	mpz2_class ret;
	mpz_rootrem(ret.get_mpz_t(), remainder.get_mpz_t(), (*this).get_mpz_t(), pow);
	return ret;
}

mpz2_class mpz2_class::sqrt() {
	mpz2_class ret;
	mpz_sqrt(ret.get_mpz_t(), (*this).get_mpz_t());
	return ret;
}
mpz2_class mpz2_class::sqrt(mpz2_class& remainder) {
	mpz2_class ret;
	mpz_sqrtrem(ret.get_mpz_t(), remainder.get_mpz_t(), (*this).get_mpz_t());
	return ret;
}

int mpz2_class::perfect_power() {
	return mpz_perfect_power_p((*this).get_mpz_t());
}
int mpz2_class::perfect_square() {
	return mpz_perfect_square_p((*this).get_mpz_t());
}

int mpz2_class::probab_prime(unsigned long testCount) {
	return mpz_probab_prime_p((*this).get_mpz_t(), testCount);
}
mpz2_class mpz2_class::nextprime() {
	mpz2_class ret;
	mpz_nextprime(ret.get_mpz_t(), (*this).get_mpz_t());
	return ret;
}
mpz2_class mpz2_class::gcd(mpz2_class b) {
	mpz2_class ret;
	mpz_gcd(ret.get_mpz_t(), (*this).get_mpz_t(), b.get_mpz_t());
	return ret;
}
mpz2_class mpz2_class::gcd(mpz2_class b, mpz2_class& s, mpz2_class& t) {
	mpz2_class ret;
	mpz_gcdext(ret.get_mpz_t(), s.get_mpz_t(), t.get_mpz_t(), (*this).get_mpz_t(), b.get_mpz_t());
	return ret;
}
mpz2_class mpz2_class::lcm(mpz2_class b) {
	mpz2_class ret;
	mpz_lcm(ret.get_mpz_t(), (*this).get_mpz_t(), b.get_mpz_t());
	return ret;
}
mpz2_class mpz2_class::invertmod(mpz2_class mod) {
	mpz2_class ret;
	mpz_invert(ret.get_mpz_t(), (*this).get_mpz_t(), mod.get_mpz_t());
	return ret;
}

size_t mpz2_class::out_str(FILE *stream, int base) {
	return mpz_out_str(stream, base, (*this).get_mpz_t());
}
size_t mpz2_class::inp_str(FILE *stream, int base) {
	return mpz_inp_str((*this).get_mpz_t(), stream, base);
}
size_t mpz2_class::out_raw(FILE *stream) {
	return mpz_out_raw(stream, (*this).get_mpz_t());
}
size_t mpz2_class::inp_raw(FILE *stream) {
	return mpz_inp_raw((*this).get_mpz_t(), stream);
}

mpz2_class& mpz2_class::setRandom(const mpz2_class a, const mpz2_class b) {
	mpz2_class a2 = mpz2_class(a);
	mpz2_class b2 = mpz2_class(b);
	if(mpz2_class::randInit == false)
	{
		gmp_randinit_mt (mpz2_class::randState);
		mpz2_class::randInit = true;
		gmp_randseed_ui(mpz2_class::randState, (unsigned int)std::time(NULL));
	}
	if(a2 > b2)
	{
		a2.swap(b2);
	}
	mpz_urandomm ((*this).get_mpz_t(), mpz2_class::randState, (b2 - a2 + 1).get_mpz_t());
	(*this) += a2;
	return *this;
}


void mpz2_class::bufImport(const void *inputBuf, size_t count, size_t size, int endian, int order, size_t nails) {
	mpz_import((*this).get_mpz_t(), count, order, size, endian, nails, inputBuf);
}

size_t mpz2_class::bufExport(void *outputBuf, size_t size, int endian, size_t nails, int order) {
	size_t count;
	mpz_export(outputBuf, &count, order, size, endian, nails, (*this).get_mpz_t());
	return count;
}


//Redefine operators
#define MPZ2_CLASS_INHERIT(TYPE, A) \
	/* Set */ \
	mpz2_class& mpz2_class::operator=(const TYPE a) { mpz_class::operator=(A); return *this; } \
	/* Multiplication */ \
	mpz2_class mpz2_class::operator*(const TYPE a) { return (mpz2_class)(((mpz_class)*this) * A); } \
	/* Addition */ \
	mpz2_class mpz2_class::operator+(const TYPE a) { return (mpz2_class)(((mpz_class)*this) + A); } \
	/* Division */ \
	mpz2_class mpz2_class::operator/(const TYPE a) { return (mpz2_class)(((mpz_class)*this) / A); } \
	/* Soustraction */ \
	mpz2_class mpz2_class::operator-(const TYPE a) { return (mpz2_class)(((mpz_class)*this) - A); } \
	/* Modulo */ \
	mpz2_class mpz2_class::operator%(const TYPE a) { return (mpz2_class)(((mpz_class)*this) % A); }

//Execute macro for each type :
MPZ2_CLASS_INHERIT(short, a);
MPZ2_CLASS_INHERIT(unsigned short, a);
MPZ2_CLASS_INHERIT(int, a);
MPZ2_CLASS_INHERIT(unsigned int, a);
MPZ2_CLASS_INHERIT(long, a);
MPZ2_CLASS_INHERIT(unsigned long, a);
MPZ2_CLASS_INHERIT(float, a);
MPZ2_CLASS_INHERIT(double, a);
MPZ2_CLASS_INHERIT(mpq_t&, mpz2_class(a));
MPZ2_CLASS_INHERIT(mpf_t&, mpz2_class(a));
MPZ2_CLASS_INHERIT(mpz_t&, mpz2_class(a));
MPZ2_CLASS_INHERIT(mpz_class&, a);
MPZ2_CLASS_INHERIT(mpz2_class&, a);
MPZ2_CLASS_INHERIT(char *, mpz2_class(a));
MPZ2_CLASS_INHERIT(std::string&, mpz2_class(a));


//Define operators that are not inside of the class
#define MPZ2_CLASS_EXTERNAL(TYPE) \
	/* Multiplication */ \
	mpz2_class operator*(const TYPE a, const mpz2_class& b) { return (mpz2_class)( a * ((mpz_class)b)); } \
	/* Addition */ \
	mpz2_class operator+(const TYPE a, const mpz2_class& b) { return (mpz2_class)( a + ((mpz_class)b)); } \
	/* Division */ \
	mpz2_class operator/(const TYPE a, const mpz2_class& b) { return (mpz2_class)( a / ((mpz_class)b)); } \
	/* soustraction */ \
	mpz2_class operator-(const TYPE a, const mpz2_class& b) { return (mpz2_class)( a - ((mpz_class)b)); } \
	/* Modulo */ \
	mpz2_class operator%(const TYPE a, const mpz2_class& b) { return (mpz2_class)( a % ((mpz_class)b)); } \

//Execute macro for each type :
MPZ2_CLASS_EXTERNAL(short);
MPZ2_CLASS_EXTERNAL(unsigned short);
MPZ2_CLASS_EXTERNAL(int);
MPZ2_CLASS_EXTERNAL(unsigned int);
MPZ2_CLASS_EXTERNAL(long);
MPZ2_CLASS_EXTERNAL(unsigned long);
MPZ2_CLASS_EXTERNAL(float);
MPZ2_CLASS_EXTERNAL(double);
MPZ2_CLASS_EXTERNAL(mpq_t&);
MPZ2_CLASS_EXTERNAL(mpf_t&);
MPZ2_CLASS_EXTERNAL(mpz_t&);
MPZ2_CLASS_EXTERNAL(mpz_class&);
MPZ2_CLASS_EXTERNAL(char *);
MPZ2_CLASS_EXTERNAL(std::string&);
