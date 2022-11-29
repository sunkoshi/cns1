#include <gmp.h>
int main()
{
    mpz_t a,b, r, q, X,Y,s, t, s1, s2, t1, t2, r1, r2, gcd, temp, brk;
    mpz_inits(a, b, r, q, X, Y,s, t, s1, s2, t1, t2, r1, r2, gcd, temp, brk, NULL);
    mpz_set_ui(brk, 1);
    gmp_printf("(a,b): ");
    // r1 = a, r2=b
    gmp_scanf("%Zd", a);
    gmp_scanf("%Zd", b);
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
        gmp_printf("q=%Zd, r1=%Zd, r2=%Zd, r=%Zd, s1=%Zd, s2=%Zd, s=%Zd, t1=%Zd, t2=%Zd, t=%Zd\n", q, r1, r2, r, s1, s2, s, t1, t2, t);

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
    gmp_printf("X,Y: %Zd,%Zd\n", X, Y);
    gmp_printf("gcd(a,b): %Zd\n", gcd);
    gmp_printf("gcd(a,b) = X*a + Y*b => %Zd = %Zd*%Zd + %Zd*%Zd\n",gcd,X,a,Y,b);
    return 0;
}
