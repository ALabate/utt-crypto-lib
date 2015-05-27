#ifndef MPZ2_CLASS_H
#define MPZ2_CLASS_H

#include <gmp.h>
#include <gmpxx.h>

/**
 * @class mpz2_class
 * Class based on Gmpxx, the C++ implementation of Gmp. This class add some method missing in gmpxx like power.
 */
class mpz2_class : public mpz_class
{
    public:
        mpz2_class();
        mpz2_class(const unsigned int a);
        mpz2_class(const char* a);
        mpz2_class(const mpz_class& a);
        mpz2_class(const mpz2_class& a);
        // mpz2_class(const unsigned int a);
        // mpz2_class & operator=(const unsigned int a);
        mpz2_class& operator=(const mpz2_class& b);

        mpz2_class operator*(const mpz2_class& b);
        mpz2_class operator%(const unsigned int a);
        mpz2_class operator+(const mpz2_class& b);
        // mpz2_class operator%(const unsigned int b);
        // using mpz_class::operator*;
        // using mpz_class::operator+;
};

#endif