#include<gmp.h>
void main()
{
    mpz_t a1,m1,y1,a2,m2,y2,x,ans,z1,z2;
    mpz_inits(a1,m1,y1,a2,m2,y2,x,ans,z1,z2,NULL);
    gmp_scanf("%Zd",a1);
    gmp_scanf("%Zd",m1);
    gmp_scanf("%Zd",a2);
    gmp_scanf("%Zd",m2);
    mpz_set_ui(ans,0);
    mpz_set_ui(y1,1);
    mpz_set_ui(y2,1);
    while(mpz_cmp_ui(ans,1)!=0)
    {
        mpz_mul(z1,y1,m1);
        mpz_mod(ans,z1,m2);
        mpz_add_ui(y1,y1,1);       
    }
    mpz_sub_ui(y1,y1,1);
    mpz_set_ui(ans,0);
    while(mpz_cmp_ui(ans,1)!=0)
    {
        mpz_mul(z2,y2,m2);
        mpz_mod(ans,z2,m1);
        mpz_add_ui(y2,y2,1);       
    }
    mpz_sub_ui(y2,y2,1);
    mpz_mul(y1,y1,m1);
    mpz_mul(y1,y1,a2);
      mpz_mul(y2,y2,m2);
    mpz_mul(y2,y2,a1);
    mpz_add(ans,y1,y2);
    mpz_mul(m1,m1,m2);
    mpz_mod(ans,ans,m1);
    gmp_printf("\nans:- %Zd\n",ans);
}