#ifndef CRYPTOLIB_H
#define CRYPTOLIB_H

#include "mpz2_class.h"

class Crypto
{
	public:
		/**
		 * @brief This function calculate the power with an algorithm called exponentiation by squaring
		 * @param a - The integer value that will be multiplicated to itself p times
		 * @param p - Number of times a will be multiplicated to itself
		 * @return The integer result
		 */
		static mpz2_class pow(mpz2_class a, unsigned long p);

		/**
		 * @brief This function calculate the power with the classic algorithme used by humans
		 * @param a - The integer value that will be multiplicated to itself p times
		 * @param p - Number of times a will be multiplicated to itself
		 * @return The integer result
		 */
		static mpz2_class pow_classic(mpz2_class a, unsigned long p);

		/**
		 * @brief This function check if an integer is composite or if it is probably prime 
		 * @param n - The number that will be tested
		 * @param k - Number of test, it determines the accuracy of the test
		 * @return False for a composite number or true for a probably prime number
		 */
		static bool rm_probabPrime(mpz2_class n, int k);



		/**
		 * @brief This function calculate the private key of an user of the Diffie-Hellmann key exchange
		 * @param a - The secret random/choosen number of the user
		 * @param p - A prime number chosen to work in Z/pZ
		 * @param g - A generator of the cyclic group Z/pZ
		 * @return The public key of the user
		 */
		static mpz2_class dh_step1(mpz2_class a, mpz2_class p = 0, mpz2_class g = 0);

		/**
		 * @brief This function calculate the common key of the Diffie-Hellmann key exchange
		 * @param a - The secret prime number of the user
		 * @param b_pub - The public key of the other user
		 * @param p - A prime number chosen to work in Z/pZ
		 * @return The common key of the two users
		 */
		static mpz2_class dh_step2(mpz2_class a, mpz2_class b_pub, mpz2_class p = 0);



		/**
		 * @brief This function calculate the ElGamal private key of the user using the public key "p" and the generator "g"
		 * @param a - The secret random/choosen number of the user
		 * @param p - A prime number chosen to work in Z/pZ
		 * @param g - A generator of the cyclic group Z/pZ
		 * @return The public key of the user
		 */
		static mpz2_class eg_generateKey(mpz2_class a, mpz2_class p = 0, mpz2_class g = 0);

		/**
		 * @brief This function does the encryption of a message using el Gamal algorithm.
		 * @param a - The secret number of the user
		 * @param b_pub - The public key of the other user
		 * @param message - The message to crypt
		 * @param p - A prime number chosen to work in Z/pZ
		 * @return The encrypted message */
		static mpz2_class eg_encrypt(mpz2_class a, mpz2_class b_pub, mpz2_class message, mpz2_class p = 0);

		/**
		 * @brief This function does the decryption of a message using el Gamal algorithm.
		 * @param a - The secret number of the user
		 * @param b_pub - The public key of the other user
		 * @param encryptedMessage - The encrypted message
		 * @param p - A prime number chosen to work in Z/pZ
		 * @return The decrypted message */
		static mpz2_class eg_decrypt(mpz2_class a, mpz2_class b_pub, mpz2_class encryptedMessage, mpz2_class p = 0);



		/**
		 * @brief This function generate a keypair for the rsa cryptosystem
		 * @param n - A reference to the variable that will contain n=p*q (p and q are the two prime numbers found)
		 * @param d - A reference to the variable that will contain the decrypt exponent d=e^-1 [n] 
		 * @param e - A reference to the variable that will contain the encrypt exponent e, by default its 65537 (but you can set your own and it will not be modified)
		 * @param bitlength - The length of primes numbers p and q
		 */
		static void rsa_generateKey(mpz2_class &n, mpz2_class &d, mpz2_class &e, unsigned long bitlength = 1024);

		/**
		 * @brief This function encrypt a number with rsa
		 * @param message - The number to encrypt
		 * @param e - The encrypt exponent
		 * @param n - n given by the key generator
		 * @return the encrypted result
		 */
		static mpz2_class rsa_encrypt(mpz2_class message, mpz2_class e, mpz2_class n);


		/**
		 * @brief This function decrypt a number with rsa
		 * @param message - The number to decrypt
		 * @param d - The decrypt exponent
		 * @param n - n given by the key generator
		 * @return the decrypted result
		 */
		static mpz2_class rsa_decrypt(mpz2_class encryptedMessage, mpz2_class d, mpz2_class n);


		//Diffie Hellman default prime number and default generator
		static const mpz2_class dh_p;
		static const mpz2_class dh_g;


};

#endif
