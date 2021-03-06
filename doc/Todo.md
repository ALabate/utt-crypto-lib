

Init :
	Function: void mpz_init (mpz_t x)
	Function: void mpz_inits (mpz_t x, ...)
	Function: void mpz_clear (mpz_t x)
	Function: void mpz_clears (mpz_t x, ...)

Set :
	Function: void mpz_set (mpz_t rop, const mpz_t op)
	Function: void mpz_set_ui (mpz_t rop, unsigned long int op)
	Function: void mpz_set_si (mpz_t rop, signed long int op)
	Function: void mpz_set_d (mpz_t rop, double op)
	Function: void mpz_set_q (mpz_t rop, const mpq_t op)
	Function: void mpz_set_f (mpz_t rop, const mpf_t op)
	Function: void mpz_set_str (mpz_t rop, const char *str, int base)
	Function: void mpz_swap (mpz_t rop1, mpz_t rop2)

Init + Set
	Function: void mpz_init_set (mpz_t rop, const mpz_t op)
	Function: void mpz_init_set_ui (mpz_t rop, unsigned long int op)
	Function: void mpz_init_set_si (mpz_t rop, signed long int op)
	Function: void mpz_init_set_d (mpz_t rop, double op)
	Function: int mpz_init_set_str (mpz_t rop, const char *str, int base)
Converting :
	— Function: unsigned long int mpz_get_ui (const mpz_t op)
	— Function: signed long int mpz_get_si (const mpz_t op)
	— Function: double mpz_get_d (const mpz_t op)
	— Function: double mpz_get_d_2exp (signed long int *exp, const mpz_t op)
	— Function: char * mpz_get_str (char *str, int base, const mpz_t op)
Arithmetics :
	Function: void mpz_add (mpz_t rop, const mpz_t op1, const mpz_t op2)
	Function: void mpz_add_ui (mpz_t rop, const mpz_t op1, unsigned long int op2)

	Function: void mpz_sub (mpz_t rop, const mpz_t op1, const mpz_t op2)
	Function: void mpz_sub_ui (mpz_t rop, const mpz_t op1, unsigned long int op2)
	Function: void mpz_ui_sub (mpz_t rop, unsigned long int op1, const mpz_t op2)

	Function: void mpz_mul (mpz_t rop, const mpz_t op1, const mpz_t op2)
	Function: void mpz_mul_si (mpz_t rop, const mpz_t op1, long int op2)
	Function: void mpz_mul_ui (mpz_t rop, const mpz_t op1, unsigned long int op2)
	
	Function: void mpz_neg (mpz_t rop, const mpz_t op)
	Function: void mpz_abs (mpz_t rop, const mpz_t op)
Division
	Function: void mpz_tdiv_q (mpz_t q, const mpz_t n, const mpz_t d)

	Function: void mpz_mod (mpz_t r, const mpz_t n, const mpz_t d)
	Function: unsigned long int mpz_mod_ui (mpz_t r, const mpz_t n, unsigned long int d)

	— Function: int mpz_divisible_p (const mpz_t n, const mpz_t d)
	— Function: int mpz_divisible_ui_p (const mpz_t n, unsigned long int d)

	— Function: int mpz_congruent_p (const mpz_t n, const mpz_t c, const mpz_t d)
	— Function: int mpz_congruent_ui_p (const mpz_t n, unsigned long int c, unsigned long int d)
Exponentiation
	Function: void mpz_powm (mpz_t rop, const mpz_t base, const mpz_t exp, const mpz_t mod)
	Function: void mpz_powm_ui (mpz_t rop, const mpz_t base, unsigned long int exp, const mpz_t mod)
	Function: void mpz_pow_ui (mpz_t rop, const mpz_t base, unsigned long int exp)
Roots:
	— Function: int mpz_root (mpz_t rop, const mpz_t op, unsigned long int n)
	— Function: void mpz_rootrem (mpz_t root, mpz_t rem, const mpz_t u, unsigned long int n)
	— Function: void mpz_sqrt (mpz_t rop, const mpz_t op)
	— Function: void mpz_sqrtrem (mpz_t rop1, mpz_t rop2, const mpz_t op)
	— Function: int mpz_perfect_power_p (const mpz_t op)
	— Function: int mpz_perfect_square_p (const mpz_t op)
Number Theoretic Functions
	Function: int mpz_probab_prime_p (const mpz_t n, int reps)
	— Function: void mpz_nextprime (mpz_t rop, const mpz_t op)
	— Function: void mpz_gcd (mpz_t rop, const mpz_t op1, const mpz_t op2)
	— Function: unsigned long int mpz_gcd_ui (mpz_t rop, const mpz_t op1, unsigned long int op2)
	— Function: void mpz_gcdext (mpz_t g, mpz_t s, mpz_t t, const mpz_t a, const mpz_t b)
	— Function: void mpz_lcm (mpz_t rop, const mpz_t op1, const mpz_t op2)
	— Function: void mpz_lcm_ui (mpz_t rop, const mpz_t op1, unsigned long op2)
	Function: int mpz_invert (mpz_t rop, const mpz_t op1, const mpz_t op2)
	— Function: int mpz_jacobi (const mpz_t a, const mpz_t b)
	— Function: int mpz_legendre (const mpz_t a, const mpz_t p)
	— Function: int mpz_kronecker (const mpz_t a, const mpz_t b)
	— Function: int mpz_kronecker_si (const mpz_t a, long b)
	— Function: int mpz_kronecker_ui (const mpz_t a, unsigned long b)
	— Function: int mpz_si_kronecker (long a, const mpz_t b)
	— Function: int mpz_ui_kronecker (unsigned long a, const mpz_t b)
	— Function: mp_bitcnt_t mpz_remove (mpz_t rop, const mpz_t op, const mpz_t f)
	— Function: void mpz_fac_ui (mpz_t rop, unsigned long int n)
	— Function: void mpz_2fac_ui (mpz_t rop, unsigned long int n)
	— Function: void mpz_mfac_uiui (mpz_t rop, unsigned long int n, unsigned long int m)
	— Function: void mpz_primorial_ui (mpz_t rop, unsigned long int n)
	— Function: void mpz_bin_ui (mpz_t rop, const mpz_t n, unsigned long int k)
	— Function: void mpz_bin_uiui (mpz_t rop, unsigned long int n, unsigned long int k)
	— Function: void mpz_fib_ui (mpz_t fn, unsigned long int n)
	— Function: void mpz_fib2_ui (mpz_t fn, mpz_t fnsub1, unsigned long int n)
	— Function: void mpz_lucnum_ui (mpz_t ln, unsigned long int n)
	— Function: void mpz_lucnum2_ui (mpz_t ln, mpz_t lnsub1, unsigned long int n)
Comparaison
	— Function: int mpz_cmp (const mpz_t op1, const mpz_t op2)
	— Function: int mpz_cmp_d (const mpz_t op1, double op2)
	— Macro: int mpz_cmp_si (const mpz_t op1, signed long int op2)
	— Macro: int mpz_cmp_ui (const mpz_t op1, unsigned long int op2)
	— Function: int mpz_cmpabs (const mpz_t op1, const mpz_t op2)
	— Function: int mpz_cmpabs_d (const mpz_t op1, double op2)
	— Function: int mpz_cmpabs_ui (const mpz_t op1, unsigned long int op2)
	— Macro: int mpz_sgn (const mpz_t op)
Bitwise
	— Function: void mpz_and (mpz_t rop, const mpz_t op1, const mpz_t op2)
	— Function: void mpz_ior (mpz_t rop, const mpz_t op1, const mpz_t op2)
	— Function: void mpz_xor (mpz_t rop, const mpz_t op1, const mpz_t op2)
	— Function: void mpz_com (mpz_t rop, const mpz_t op)
	— Function: mp_bitcnt_t mpz_popcount (const mpz_t op)
	— Function: mp_bitcnt_t mpz_hamdist (const mpz_t op1, const mpz_t op2)
	— Function: mp_bitcnt_t mpz_scan0 (const mpz_t op, mp_bitcnt_t starting_bit)
	— Function: mp_bitcnt_t mpz_scan1 (const mpz_t op, mp_bitcnt_t starting_bit)
	— Function: void mpz_setbit (mpz_t rop, mp_bitcnt_t bit_index)
	— Function: void mpz_clrbit (mpz_t rop, mp_bitcnt_t bit_index)
	— Function: void mpz_combit (mpz_t rop, mp_bitcnt_t bit_index)
	— Function: int mpz_tstbit (const mpz_t op, mp_bitcnt_t bit_index)
IO
	— Function: size_t mpz_out_str (FILE *stream, int base, const mpz_t op)
	— Function: size_t mpz_inp_str (mpz_t rop, FILE *stream, int base)
	— Function: size_t mpz_out_raw (FILE *stream, const mpz_t op)
	— Function: size_t mpz_inp_raw (mpz_t rop, FILE *stream)
Random
	Function: void mpz_urandomm (mpz_t rop, gmp_randstate_t state, const mpz_t n)
Imports
	— Function: void mpz_import (mpz_t rop, size_t count, int order, size_t size, int endian, size_t nails, const void *op)
	— Function: void * mpz_export (void *rop, size_t *countp, int order, size_t size, int endian, size_t nails, const mpz_t op)
Misc
	— Function: int mpz_fits_ulong_p (const mpz_t op)
	— Function: int mpz_fits_slong_p (const mpz_t op)
	— Function: int mpz_fits_uint_p (const mpz_t op)
	— Function: int mpz_fits_sint_p (const mpz_t op)
	— Function: int mpz_fits_ushort_p (const mpz_t op)
	— Function: int mpz_fits_sshort_p (const mpz_t op)
	— Macro: int mpz_odd_p (const mpz_t op)
	— Macro: int mpz_even_p (const mpz_t op)
	— Function: size_t mpz_sizeinbase (const mpz_t op, int base)
Special
	— Function: mp_limb_t mpz_getlimbn (const mpz_t op, mp_size_t n)
	— Function: size_t mpz_size (const mpz_t op)
	— Function: const mp_limb_t * mpz_limbs_read (const mpz_t x)
	— Function: mp_limb_t * mpz_limbs_write (mpz_t x, mp_size_t n)
	— Function: mp_limb_t * mpz_limbs_modify (mpz_t x, mp_size_t n)
	— Function: void mpz_limbs_finish (mpz_t x, mp_size_t s)
	— Function: mpz_srcptr mpz_roinit_n (mpz_t x, const mp_limb_t *xp, mp_size_t xs)
	— Macro: mpz_t MPZ_ROINIT_N (mp_limb_t *xp, mp_size_t xs)