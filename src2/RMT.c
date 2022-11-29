#include<stdio.h>
#include<stdlib.h>
#include<gmp.h>
#include<time.h>
int main()
{
	mpz_t n,q,bits,r,a,k,j,mod;
	mpz_inits(n,q,bits,r,a,j,k,mod,NULL);
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned long seed;
	seed = time(NULL);
	gmp_randseed_ui(state,1000);

	
	gmp_printf("\nn: ");
	gmp_scanf("%Zd",n);
	mpz_mod_ui(mod,n,2);
	if (mpz_cmp_ui(n,1) <= 0 || mpz_cmp_ui(n,4) == 0) 
    {
    	gmp_printf("Composite!\n");
    	return 0;
    }
    if (mpz_cmp_ui(n,3) <= 0) 
    {
    	gmp_printf("Inconclusive!\n");
    	return 0;
    }
	// find q = n-1/2^k k>0	
	mpz_sub_ui(q,n,1);	
	mpz_set(bits,q); mpz_sub_ui(bits,n,4);
	mpz_mod_ui(mod,q,2);
	mpz_set_ui(k,0);
	// calculating k and q, while n-1/2^k gives an integer
	while(mpz_cmp_ui(mod,0)!=0)   
	{
		mpz_div_ui(q,q,2);  // q / 2^i
		mpz_add_ui(k,k,1);  // k++
		mpz_mod_ui(mod,q,2); // q % 2
	}	
	gmp_printf("\nFound values of k and q:");
	gmp_printf("\nk= %Zd; q= %Zd", k, q);

	
	
	// select random number a between 0 and n-2,	
	mpz_urandomm(a,state,bits);
	// adding 2 to get a in range [2,n-2]
	mpz_add_ui(a,a,2);	
	// a contains the random number 1 < a < n-1
	gmp_printf("\na: %Zd",a);
	// finding a^q mod n
	mpz_powm(r,a,q,n);
	if(mpz_cmp_ui(r,1)==0) 
	{
		gmp_printf("\nInconclusive!");
		return 0;
	}

	mpz_set_ui(j,0);
	mpz_t n_1;
	mpz_init(n_1);
	mpz_sub_ui(n_1,n_1,1);
	while(mpz_cmp(j,k)<0)
	{
		mpz_powm(r,a,q,n);
		if(mpz_cmp(r,n_1)==0) 
		{
			gmp_printf("\nInconclusive!");
			return 0;
		}
		mpz_mul_ui(q,q,2);
	}
	gmp_printf("\nComposite!");
	return 0;
}