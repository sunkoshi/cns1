#include<bits/stdc++.h>
#include<gmp.h>
using namespace std;

void MI(mpz_t a, mpz_t b, mpz_t *MI){
    mpz_t  r, q, X,Y,s, t, s1, s2, t1, t2, r1, r2, gcd, temp, brk;
    mpz_inits( r, q, X, Y,s, t, s1, s2, t1, t2, r1, r2, gcd, temp, brk, NULL);
    mpz_set_ui(brk, 1);
    gmp_printf("(a,p): ");
    // r1 = a, r2=p
    mpz_set(r1,a);
    mpz_set(r2,b);

    //s1 =1, s2=0
    mpz_set_ui(s1, 1);
    mpz_set_ui(s2, 0);

    //t1=0,t2=1
    mpz_set_ui(t1, 0);
    mpz_set_ui(t2, 1);

    //to store gcd 
    mpz_set_ui(gcd,1);
    
    while(mpz_cmp_ui(brk, 0)!=0)
    {
        mpz_fdiv_q(q,r1, r2); // q = r1/r2
        mpz_fdiv_r(r,r1, r2); // r = r1 mod r2

        // s = s1 - s2*q
        mpz_mul(temp, q, s2);
        mpz_sub(s, s1, temp);

        // t = t1 - t2*q
        mpz_mul(temp, q, t2);
        mpz_sub(t, t1, temp);

        // for next iteration s1 = s2, s2 = s
        mpz_set(s1,s2);
        mpz_set(s2, s);

        // for next iteration t1 = t2, t2 = t
        mpz_set(t1, t2);
        mpz_set(t2, t);

        // for next iteration r1 = r2, r2 = r
        mpz_set(r1, r2);
        mpz_set(r2, r);

        // if r = 0, gcd is found at r1 and X = S1, Y = S2
        if (mpz_cmp_ui(r, 0)==0){
            mpz_set_ui(brk, 0);
            mpz_set(gcd,r1);
            mpz_set(X,s1);
            mpz_set(Y,t1);
        }
    }
    if(mpz_cmp_ui(gcd,1) == 0)
    {
        if(mpz_cmp_ui(X,0) < 0) mpz_add(X,b,X); // if MI is -ve
    }
    else {
        gmp_printf("\n gcd(%Zd,%Zd) != 1, Multipicative inverse doesnt exist \n",a,b);
    }
    mpz_set(*MI,X);
}

int main()
{
   // Initialisations
   gmp_randstate_t rstate;
   gmp_randinit_mt(rstate);
   unsigned long seed;
   seed = time(NULL);
   gmp_randseed_ui(rstate, seed);

   mpz_t p,alpha,x,y,M,k,C1,C1x,C2,C2x,temp,mi;
   mpz_inits(p,alpha,x,y,M,k,C1,C1x,C2,C2x,temp,mi,NULL);
   mpz_set_ui(temp,20);
   
   // choosing P and Alpha
   mpz_set_ui(p,23);
   mpz_set_ui(alpha,11);
   gmp_printf("Prime Number p : %Zd\n",p);
   gmp_printf("Primitive Root alpha : %Zd\n",alpha);

   //choosing private key {1<x<p-1}
   mpz_urandomm(x, rstate, p);
//    mpz_set_ui(x,6);
   gmp_printf("Private Key chosen Randomly: %Zd\n",x);

   // computing public key y = alpha^x mod p
   mpz_powm(y,alpha,x,p);
   gmp_printf("Public Key computed: %Zd\n",y);

   // El-Gamal Encryption
   gmp_printf("Enter Plaintext: ");
   gmp_scanf("%Zd",&M);
   mpz_urandomm(k, rstate, temp);
//    mpz_set_ui(k,3);
   gmp_printf("K chosen randomly: %Zd\n",k);
   
   // computing cipher texts C1 and C2
   mpz_powm(C1,alpha,k,p);
   mpz_powm(C2,y,k,p);
   mpz_mul(C2,C2,M);
   mpz_mod(C2,C2,p);
   gmp_printf("Ciphertext {C1,C2} : {%Zd,%Zd}\n",C1,C2);

   // El-Gamal Decryption
  
   // C1x = y^(k) mod p
   mpz_powm(C1x,y,k,p);
   gmp_printf("C1x computed: %Zd\n",C1x);


   //M = (C2x * C1x) mod p
   mpz_powm(temp,y,k,p);
   MI(temp,p,&mi);
   gmp_printf("MI = %Zd\n",mi);
   mpz_mul(M,C2,mi);
   mpz_mod(M,M,p);
   gmp_printf("Deciphered plain text = %Zd\n\n",M);
}