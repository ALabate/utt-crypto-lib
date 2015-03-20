#ifndef CRYPTOLIB_H
#define CRYPTOLIB_H

#include <gmp.h>

/**
 * @brief This function calculate the power with an algorithm called exponentiation by squaring
 * @param dest - The integer number that will received the result
 * @param a - The integer value that will be multiplicated p times
 * @param p - Number of times a will be multiplicated
 */
void crypto_pow(mpz_t dest, mpz_t a, unsigned long p);

/**
 * @brief This function is the internal part of `crypto_pow`. Please use `crypto_pow` and not directly this one.
 * @param dest - The integer number that will received the result
 * @param a - The integer value that will be multiplicated p times (Warning : it will be edited too)
 * @param p - Number of times a will be multiplicated
 */
void crypto_pow_classic(mpz_t dest, mpz_t a, unsigned long p);

/**
 * @brief This function calculate the power with the classic algorithme used by humans
 * @param dest - The integer number that will received the result
 * @param a - The integer value that will be multiplicated p times
 * @param p - Number of times a will be multiplicated
 */
void crypto_pow_recur(mpz_t dest, mpz_t a, unsigned long p);

#endif