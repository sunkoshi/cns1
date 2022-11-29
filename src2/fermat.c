#include<stdio.h>
#include<gmp.h>
#include<time.h>
int main()
{
    mpz_t p,a,r,div,one,bits,t;
    mpz_inits(p,a,r,div,one,t,bits,NULL);
    unsigned long int x = 1;
    mpz_set_ui(one,x);
    gmp_randstate_t state;
    gmp_randinit_mt(state);
    unsigned long seed;
    seed = time(NULL);
    gmp_randseed_ui(state,seed);
    
    
    printf("p: ");
    gmp_scanf("%Zd",p);
    
    if (mpz_cmp(p,one) <= 0 || mpz_cmp_ui(p,4) == 0) 
    {
    	gmp_printf("Fermats Little theorem doesnt hold true, %Zd is Composite!\n",p);
    	return 0;
    }
    if (mpz_cmp_ui(p,3) <= 0) 
    {
    	gmp_printf("Fermats Little theorem holds true, %Zd is a Prime!\n",p);
    	return 0;
    }
   
    mpz_sub_ui(bits,p,4);
    mpz_sub_ui(t,p,1);
    printf("No.of Iterations: "); int itr;
    scanf("%d",&itr);
    // generating multiple random numbers for primality testing
    for(int i=0;i<itr;i++)
    {
	    // generating random number in [2 ... n-2]    	    
	    mpz_urandomm(a,state,bits);
	    mpz_add_ui(a,a,2);
	    
	    // Checking if a and n are co-prime
	    mpz_gcd(r,a,p);
	    if(mpz_cmp(r,one) != 0 )
	    {	
	    	gmp_printf("Fermats Little theorem doesnt hold true, %Zd is Composite!\n",p);
	    	
	    	return 0;
	    }
	    // fermats little theorem r = a^(p-1)modp
	    mpz_powm(r,a,t,p);
	    if(mpz_cmp(r,one) != 0)
	    {
	    
	    	gmp_printf("Fermats Little theorem doesnt hold true, %Zd is Composite!\n",p);
	    	return 0;
	    }
     }
     gmp_printf("Fermats Little theorem holds true, %Zd is a Prime!\n",p);
     

    return 0;
}
