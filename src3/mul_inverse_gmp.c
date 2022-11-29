#include<gmp.h>
void main()
{
    mpz_t n,x,y,z,x1,x2;
    mpz_inits(n,x,y,z,x1,x2,NULL);
    gmp_printf("Enter the value of n:-");
    gmp_scanf("%Zd",n);
    mpz_set(x,n);
    mpz_sub_ui(z,n,1);
    while(mpz_cmp_ui(x,0)!=0)
    {
        mpz_set(y,n);
      //  gmp_printf("x==%Zd\n",z);
        while(mpz_cmp_ui(y,0)!=0)
        {
           // mpz_t x1,x2;
          //  gmp_printf("y==%Zd\n",y);
        
            mpz_mul(x1,y,x);
            mpz_mod(x2,x1,n);
            if(mpz_cmp_ui(x2,1)==0)
            {
                gmp_printf("%Zd   %Zd\n",x,y);
                break;
            }
            mpz_sub_ui(y,y,1);
           // gmp_printf("y==%Zd\n",y);
        }
        mpz_sub_ui(x,x,1);
    }
}