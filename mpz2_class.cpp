#include "mpz2_class.h"

gmp_randstate_t mpz2_class::randState = {};
bool mpz2_class::randInit = false;

//Init and Set
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


//Define this macro to not repeat functions for each type
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
	mpz2_class mpz2_class::operator%(const TYPE a) { return (mpz2_class)(((mpz_class)*this) % A); } \
	/* Pow Mod */ \
	mpz2_class mpz2_class::powmod(const TYPE a, const mpz2_class mod) { \
		mpz2_class ret; \
		mpz_powm(ret.get_mpz_t(), (*this).get_mpz_t(), mpz2_class(a).get_mpz_t(), mod.get_mpz_t()); \
		return ret; \
	} \
	/* Random */ \
	mpz2_class& mpz2_class::setRandom(const TYPE a, const TYPE b) { \
		mpz2_class a2 = mpz2_class(a); \
		mpz2_class b2 = mpz2_class(b); \
		if(mpz2_class::randInit == false) \
		{ \
			gmp_randinit_mt (mpz2_class::randState); \
			mpz2_class::randInit = true; \
			gmp_randseed_ui(mpz2_class::randState, (unsigned int)std::time(NULL)); \
		} \
		if(a2 > b2) \
		{ \
			a2.swap(b2); \
		} \
		mpz_urandomm ((*this).get_mpz_t(), mpz2_class::randState, (b2 - a2 + 1).get_mpz_t()); \
		(*this) += a2; \
		return *this; \
	} \



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


#define MPZ2_CLASS_STD(TYPE) \
	/* Pow */ \
	mpz2_class mpz2_class::pow(const TYPE a) { \
		mpz2_class ret; \
		mpz_pow_ui(ret.get_mpz_t(), (*this).get_mpz_t(), a); \
		return ret; \
	} \
	

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

//Define X*(mpz2_class) that are not defined inside the class
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


MPZ2_CLASS_STD(short);
MPZ2_CLASS_STD(unsigned short);
MPZ2_CLASS_STD(int);
MPZ2_CLASS_STD(unsigned int);
MPZ2_CLASS_STD(long);
MPZ2_CLASS_STD(unsigned long);
MPZ2_CLASS_STD(float);
MPZ2_CLASS_STD(double);

//Function with no types in parameters
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
