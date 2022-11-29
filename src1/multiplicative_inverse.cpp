#include <gmp.h>
#include <iostream>
using namespace std;

int main()
{
    mpz_t a, b, n, i, temp;
    mpz_inits(a, b, n, i, temp, NULL);
    gmp_printf("Enter the value of a and n:");
    gmp_scanf("%Zd", a);
    gmp_scanf("%Zd", n);

    mpz_add_ui(n, n, 1);
    for (mpz_set_ui(i, 1); mpz_cmp(i, n) < 0; mpz_add_ui(i, i, 1))
    {
        mpz_mul(temp, a, i);
        mpz_fdiv_r(temp, temp, n);
        if (mpz_cmp_ui(temp, 1) == 0)
        {      
            gmp_printf("=> %Zd is Multipicative Inverse\n", i);
            break;
        }
    }
}                        