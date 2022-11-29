#include <gmp.h>
#include <iostream>
using namespace std;

void gcd(mpz_t a, mpz_t b)
{
}

int main()
{
    mpz_t r, q, s, t, s1, s2, t1, t2, r1, r2, gcd, temp;
    mpz_inits(r, q, s, t, s1, s2, t1, t2, r1, r2, gcd, temp, NULL);
    gmp_printf("Enter the value of a and b for GCD(a,b): ");
    gmp_scanf("%Zd", r2);
    gmp_scanf("%Zd", r1);
    gmp_printf("Finding GCD(%Zd,%Zd)...\n", r2, r1);

    mpz_set_ui(s2, 1);
    mpz_set_ui(s1, 0);

    mpz_set_ui(t2, 0);
    mpz_set_ui(t1, 1);

    mpz_set_ui(gcd, 1);

    while (true)
    {
        gmp_printf("s(i-2)=%Zd, t(i-2)=%Zd\n", s2, t2);
        gmp_printf("s(i-1)=%Zd, t(i-1)=%Zd\n", s1, t1);
        gmp_printf("q(i)=%Zd, r(i)=%Zd, s(i)=%Zd, t(i)=%Zd\n\n", q, r, s, t);

        // calculate for q(i) and r(i)
        mpz_fdiv_q(q, r2, r1);
        mpz_fdiv_r(r, r2, r1);

        // calculate for s(i)
        mpz_mul(temp, q, s1);
        mpz_sub(s, s2, temp);

        // calculate for t(i)
        mpz_mul(temp, q, t1);
        mpz_sub(t, t2, temp);

        // make s2 = s1 and s1 = s
        mpz_set(s2, s1);
        mpz_set(s1, s);

        // make t2 = t1 and t1 = t
        mpz_set(t2, t1);
        mpz_set(t1, t);

        mpz_set(r2, r1);
        mpz_set(r1, r);

        if (mpz_cmp_ui(r, 0) == 0)
        {
            break;
        }
    }
    gmp_printf("a,b: %Zd,%Zd\n", s2, t2);
    gmp_printf("GCD: %Zd\n", r2);
}