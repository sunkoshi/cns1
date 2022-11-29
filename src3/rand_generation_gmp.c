#include<gmp.h>
void main()
{
    gmp_randstate_t state;
    gmp_randinit_mt(state);
    unsigned long seed;
    seed = time(NULL);
    gmp_randseed_ui(state,seed);
    mpz_t a,max;
    mpz_inits(a,max,NULL);
    mpz_set_ui(max,100000);
    mpz_urandomm(a,state,max);
    gmp_printf("%Zd \n",a);
}