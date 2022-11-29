#include<gmp.h>
#include<iostream>
using namespace std;

int main()
{
    mpz_t a,b,n,i,exp;
    mpz_inits(a,b,n,i,exp,NULL);
    gmp_printf("Enter the value of a,b and n:");
    gmp_scanf("%Zd", a);
    gmp_scanf("%Zd", b);
    gmp_scanf("%Zd", n);
    mpz_set(exp, a);

    mpz_set_ui(i,1);
    for (mpz_set_ui(i,1);mpz_cmp(i,b)<0;mpz_add_ui(i,i,1))
    {
        mpz_mul(exp,exp,a);
    }
    gmp_printf("Exp: %Zd\n",exp);
    mpz_fdiv_r(i, exp, n);
    gmp_printf("Ans: %Zd\n",i);
}