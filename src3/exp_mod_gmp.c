#include<gmp.h>
void main()
{
    mpz_t a,x,m,ans;
    mpz_inits(a,x,m,ans,NULL);
    gmp_printf("Enter the value of a:");
    gmp_scanf("%Zd",a);
    gmp_printf("Enter the value of x:");
    gmp_scanf("%Zd",x);
    gmp_printf("Enter the value of m:");
    gmp_scanf("%Zd",m);
    mpz_set_ui(ans,1);
    mpz_mod(a,a,m);
    while(mpz_cmp_ui(x,0)!=0)
    {
        mpz_mul(ans,ans,a);
        mpz_mod(ans,ans,m);
        mpz_sub_ui(x,x,1);
    }
    gmp_printf("ans:-%Zd\n",ans);
}