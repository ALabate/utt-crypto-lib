# Gmp mpz2 documentation
##  Définition

On peut utiliser les types suivants pour créer une variable
```cpp
mpz2_class()
mpz2_class(short a)
mpz2_class(unsigned short a)
mpz2_class(int a)
mpz2_class(unsigned int a)
mpz2_class(long a)
mpz2_class(unsigned long a)
mpz2_class(float a)
mpz2_class(double a)
mpz2_class(mpz_t a)
mpz2_class(mpz_class& a)
mpz2_class(mpz2_class& a)
mpz2_class(char* a, int base)
mpz2_class(std::string& a, int base)
```

### Exemples de créations de variables
```cpp
mpz2_class a; // La variable 'a' sera égal à 0
mpz2_class b = mpz2_class(10); // 'b' sera égal à 10
mpz2_class c = mpz2_class("28"); // 'c' sera égal à 28
mpz2_class d = mpz2_class("1C", 16); // 'd' sera égal à 28 en base 16
mpz2_class e = mpz2_class(b); // 'e' sera égal à 10
```

## Assignation
Pour assigner une valeur à une variable, c'est à dire par exemple
```cpp
mpz2_class a = 12;
```
On peut utiliser tous les types suivants

```cpp
const short
unsigned short
int
unsigned int
long
unsigned long
float
double
mpz_class&
mpz2_class&
char*
std::string
```

### Exemples d'assignation de valeurs
```cpp
mpz2_class a = 10;
mpz2_class b;
b = "28";
b = "0x1C";
b = a;
```

