#include <gmp.h>
#include <iostream>
using namespace std;

void gcd(mpz_t a, mpz_t b)
{
    if (mpz_cmp_ui(b, 0) == 0)
    {
        gmp_printf("GCD: %Zd\n", a);
        return;
    }
    mpz_t c;
    mpz_inits(c, NULL);
    mpz_fdiv_r(c, a, b);
    gcd(b, c);
}

int main()
{
    mpz_t a, b;
    mpz_inits(a, b, NULL);
    gmp_printf("Enter the value of a and b for GCD(a,b): ");
    gmp_scanf("%Zd", a);
    gmp_scanf("%Zd", b);
    gmp_printf("Finding GCD(%Zd,%Zd)...\n", a, b);
    gcd(a, b);
}