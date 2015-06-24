#ifndef CRYPTOLIB_H
#define CRYPTOLIB_H

#include <fstream>
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
		 * @param e - The encrypt exponent e, by default its 65537 (but you can set your own and it will not be modified)
		 * @param bitlength - The length of primes numbers p and q
		 */
		static void rsa_generateKey(mpz2_class &n, mpz2_class &d, mpz2_class e = 0, unsigned long bitlength = 1024);

		/**
		 * @brief This function encrypt a number with rsa
		 * @param message - The number to encrypt
		 * @param n - n given by the key generator : The public key
		 * @param e - The encrypt exponent wich is public
		 * @return the encrypted result
		 */
		static mpz2_class rsa_encrypt(mpz2_class message, mpz2_class n, mpz2_class e = 0);


		/**
		 * @brief This function decrypt a number with rsa
		 * @param message - The number to decrypt
		 * @param n - n given by the key generator : The public key
		 * @param d - The decrypt exponent : The private key
		 * @return the decrypted result
		 */
		static mpz2_class rsa_decrypt(mpz2_class encryptedMessage, mpz2_class n, mpz2_class d);



		/**
		 * @brief This function give a block of n bytes from a file into a mpz2_class
		 * @param file - The pointer to the file
		 * @param n - The length of the block in bytes
		 * @return the block in a mpz2_class
		 */
		static mpz2_class file_split(std::ifstream& file, unsigned long n);

		/**
		 * @brief This function append at the end of a file a mpz2_class of n bytes
		 * @param file - The pointer to the file
		 * @param n - The length of the block in bytes
		 * @param value - The value to append
		 */
		static void file_append(std::ofstream& file, unsigned long n, mpz2_class value);


		/**
		 * @brief This function give a block of n bytes from a buffer into a mpz2_class
		 * @param buf - The input buffer
		 * @param pos - The position in blocks (begin from 0)
		 * @param n - The length of the block in bytes
		 * @return the block in a mpz2_class
		 */
		static mpz2_class buf_split(const char *buf, unsigned long pos, unsigned long n, unsigned long size = 0);

		/**
		 * @brief This function append at the end of a buffer a mpz2_class of n bytes
		 * @param buf - The input and output buffer
		 * @param pos - The position in blocks (begin from 0)
		 * @param n - The length of the block in bytes
		 * @param value - The value to append
		 */
		static void buf_append(const char *buf, unsigned long pos, unsigned long n, mpz2_class value);




		//Diffie Hellman default prime number and default generator
		static const mpz2_class dh_p;
		static const mpz2_class dh_g;
		static const unsigned long dh_blockBytes;
		static const unsigned long dh_cryptedBlockBytes;

		static const mpz2_class rsa_e;
		static const unsigned long rsa_blockBytes;
		static const unsigned long rsa_cryptedBlockBytes;


};

#endif
