#ifndef MPZ2_CLASS_H
#define MPZ2_CLASS_H

#include <ctime>
#include <gmp.h>
#include <gmpxx.h>

/**
 * @class mpz2_class
 * Class based on Gmpxx, the C++ implementation of Gmp. This class add some method missing in gmpxx like power.
 */
class mpz2_class : public mpz_class
{
    public:

        //Constructors
        mpz2_class();
        mpz2_class(const short a);
        mpz2_class(const unsigned short a);
        mpz2_class(const int a);
        mpz2_class(const unsigned int a);
        mpz2_class(const long a);
        mpz2_class(const unsigned long a);
        mpz2_class(const float a);
        mpz2_class(const double a);
        mpz2_class(const mpq_t a);
        mpz2_class(const mpf_t a);
        mpz2_class(const mpz_t a);
        mpz2_class(const mpz_class& a);
        mpz2_class(const mpz2_class& a);
        mpz2_class(const char *s, int base = 0);
        mpz2_class(const std::string& s, int base = 0);


        void clear();
        mpz2_class& swap(mpz2_class& b);
        mpz2_class abs();

        mpz2_class divisible(const mpz2_class a);
        mpz2_class congruent(const mpz2_class a, const mpz2_class b);

        mpz2_class pow(const unsigned long a);
        mpz2_class powmod(const mpz2_class a, const mpz2_class mod);

        mpz2_class root(const unsigned long pow);
        mpz2_class root(const unsigned long pow, bool& exact);
        mpz2_class root(const unsigned long pow, mpz2_class& remainder);
        mpz2_class sqrt();
        mpz2_class sqrt(mpz2_class& remainder);
        int perfect_power();
        int perfect_square();

        int probab_prime(unsigned long testCount);
        mpz2_class nextprime();
        mpz2_class gcd(mpz2_class b);
        mpz2_class gcd(mpz2_class b, mpz2_class& s, mpz2_class& t);
        mpz2_class lcm(mpz2_class b);
        mpz2_class invertmod(mpz2_class mod);

        size_t out_str (FILE *stream, int base = 16);
        size_t inp_str (FILE *stream, int base = 16);
        size_t out_raw (FILE *stream);
        size_t inp_raw (FILE *stream);

        mpz2_class& setRandom(const mpz2_class a, const mpz2_class b);

        //Redefine operators
        #define MPZ2_CLASS_INHERIT_H(TYPE) \
            mpz2_class& operator=(const TYPE a); \
            /* Multiplication */ \
            mpz2_class operator*(const TYPE a); \
            /* Addition */ \
            mpz2_class operator+(const TYPE a); \
            /* Division */ \
            mpz2_class operator/(const TYPE a); \
            /* Soustraction */ \
            mpz2_class operator-(const TYPE a); \
            /* Modulo */ \
            mpz2_class operator%(const TYPE a);
        
        //Execute macro for each type :
        MPZ2_CLASS_INHERIT_H(short);
        MPZ2_CLASS_INHERIT_H(unsigned short);
        MPZ2_CLASS_INHERIT_H(int);
        MPZ2_CLASS_INHERIT_H(unsigned int);
        MPZ2_CLASS_INHERIT_H(long);
        MPZ2_CLASS_INHERIT_H(unsigned long);
        MPZ2_CLASS_INHERIT_H(float);
        MPZ2_CLASS_INHERIT_H(double);
        MPZ2_CLASS_INHERIT_H(mpq_t&);
        MPZ2_CLASS_INHERIT_H(mpf_t&);
        MPZ2_CLASS_INHERIT_H(mpz_t&);
        MPZ2_CLASS_INHERIT_H(mpz_class&);
        MPZ2_CLASS_INHERIT_H(mpz2_class&);
        MPZ2_CLASS_INHERIT_H(char *);
        MPZ2_CLASS_INHERIT_H(std::string&);

    private:
        static gmp_randstate_t randState;
        static bool randInit;

       
};

#endif