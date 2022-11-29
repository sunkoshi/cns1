#include<gmp.h>
void main()
{
    mpz_t r1,r2,q,x1,x2,x3,y1,y2,y3,a,b;
    mpz_inits(r1,r2,q,x1,x2,x3,y1,y2,y3,a,b,NULL);

    gmp_printf("Enter the value of a:-");
    gmp_scanf("%Zd",r1);
    gmp_printf("Enter the value of b:-");
    gmp_scanf("%Zd",r2);
    mpz_set_ui(x1,1);
    mpz_set_ui(x2,0);
    mpz_set_ui(y1,0);
    mpz_set_ui(y2,1);
    while(mpz_cmp_ui(r2,0)!=0)
    {
        mpz_fdiv_q(q,r1,r2);
        mpz_fdiv_r(a,r1,r2);
        
        //gmp_printf("%Zd   %Zd\n",r1,r2);
        mpz_set(r1,r2);
        mpz_set(r2,a);
        mpz_mul(a,q,x2);
        mpz_sub(x3,x1,a);
        mpz_mul(a,q,y2);
        mpz_sub(y3,y1,a);
        mpz_set(x1,x2);
        mpz_set(x2,x3);
        mpz_set(y1,y2);
        mpz_set(y2,y3);
    }
    gmp_printf("GCD :-%Zd\n ",r1);
}