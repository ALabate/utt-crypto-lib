

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
	— Function: void mpz_powm (mpz_t rop, const mpz_t base, const mpz_t exp, const mpz_t mod)
	— Function: void mpz_powm_ui (mpz_t rop, const mpz_t base, unsigned long int exp, const mpz_t mod)

	— Function: void mpz_pow_ui (mpz_t rop, const mpz_t base, unsigned long int exp)
