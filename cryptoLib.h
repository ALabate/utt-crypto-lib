#ifndef CRYPTOLIB_H
#define CRYPTOLIB_H

#include "mpz2_class.h"

/**
 * @brief This function calculate the power with an algorithm called exponentiation by squaring
 * @param a - The integer value that will be multiplicated to itself p times
 * @param p - Number of times a will be multiplicated to itself
 * @return The integer result
 */
// mpz2_class crypto_pow(mpz2_class a, unsigned long p);

/**
 * @brief This function calculate the power with the classic algorithme used by humans
 * @param a - The integer value that will be multiplicated to itself p times
 * @param p - Number of times a will be multiplicated to itself
 * @return The integer result
 */
// mpz2_class crypto_pow_classic(mpz2_class a, unsigned long p);

/**
 * @brief This function check if an integer is composite or if it is probably prime 
 * @param n - The number that will be tested
 * @param k - Number of test, it determines the accuracy of the test
 * @return False for a composite number or true for a probably prime number
 */
bool crypto_primality_test(mpz2_class n, int k);

/**
 * @brief This function calculate the first step of the Diffie-Hellmann key exchange (g^a mod p)
 * @param a - The secret prime number of the user
 * @param p - A prime number chosen to work in Z/pZ
 * @param g - It is a primitive root modulo p
 * @return The encode secret number of the user */
mpz2_class diffie_hellmann_etape_1(mpz2_class a, mpz2_class p, mpz2_class g);

/**
 * @brief This function calculate the second step of the Diffie-Hellmann key exchange (the common key)
 * @param a - The secret prime number of the user
 * @param p - A prime number chosen to work in Z/pZ
 * @param B - The encode secret number from the other user
 * @return The common key of the two users */

mpz2_class diffie_hellmann_etape_2(mpz2_class a, mpz2_class p, mpz2_class B);

#endif