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
        mpz2_class(const short a);
        mpz2_class(const unsigned short a);
        mpz2_class(const int a);
        mpz2_class(const unsigned int a);
        mpz2_class(const long a);
        mpz2_class(const unsigned long a);
        mpz2_class(const float a);
        mpz2_class(const double a);
        mpz2_class(const mpz_t a);
        mpz2_class(const mpz_class& a);
        mpz2_class(const mpz2_class& a);
        mpz2_class(const char *s, int base = 0);
        mpz2_class(const std::string& s, int base = 0);

        mpz2_class& operator=(const short a);
        mpz2_class& operator=(const unsigned short a);
        mpz2_class& operator=(const int a);
        mpz2_class& operator=(const unsigned int a);
        mpz2_class& operator=(const long a);
        mpz2_class& operator=(const unsigned long a);
        mpz2_class& operator=(const float a);
        mpz2_class& operator=(const double a);
        mpz2_class& operator=(const mpz_class& a);
        mpz2_class& operator=(const mpz2_class& a);
        mpz2_class& operator=(const char *s);
        mpz2_class& operator=(const std::string& s);

        // mpz2_class(const unsigned int a);
        // mpz2_class & operator=(const unsigned int a);

        mpz2_class operator*(const mpz2_class& a);
        mpz2_class operator%(const unsigned int a);
        mpz2_class operator+(const   mpz2_class& a);
        // mpz2_class operator%(const unsigned int b);
        // using mpz_class::operator*;
        // using mpz_class::operator+;
};

#endif