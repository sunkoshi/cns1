#include<bits/stdc++.h>
#include<gmp.h>
#include <gmpxx.h>
using namespace std;
//global public elements
mpz_t q;
mpz_t alpha;
gmp_randstate_t rstate;
void init()
{
    gmp_randinit_mt(rstate);
    unsigned long seed;
    seed = time(NULL);
    gmp_randseed_ui(rstate, seed);
}
int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}

int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}

void generateRandomPrime(int bits)
{
    while(true)
    {
        mpz_urandomb(q, rstate, bits);
        if (mpz_probab_prime_p(q, 25) == 1 || mpz_probab_prime_p(q, 25) == 2)
          break;
    }
    
}
mpz_class generatePrivateKey(){
    mpz_class rand;
      
    mpz_urandomm(rand.get_mpz_t(), rstate, q);
    // if(mpz_cmp(rand.get_mpz_t(),q)<0) break;
    

    return rand;
}

int main()
{
    init();
    int bits =50;
    //initialising q and alpha
    generateRandomPrime(bits);
    int gen = generator(mpz_get_ui(q));
    mpz_set_ui(alpha,gen);

    gmp_printf("Global Elements Prime No. (q) = %Zd & its generator (alpha) = %Zd\n",q,alpha);

    mpz_class privateKeyA = generatePrivateKey();
    mpz_class privateKeyB = generatePrivateKey();
    cout<<"\nRandomly Chosen ";
    gmp_printf("privateKeyA = %Zd, privateKeyB = %Zd\n",privateKeyA.get_mpz_t(),privateKeyB.get_mpz_t());

    mpz_class publicKeyA, publicKeyB;
    mpz_powm(publicKeyA.get_mpz_t(), alpha, privateKeyA.get_mpz_t(), q);
    mpz_powm(publicKeyB.get_mpz_t(), alpha, privateKeyB.get_mpz_t(), q);

    gmp_printf("\nGenerated publicKeyA = %Zd, publicKeyB = %Zd\n",publicKeyA.get_mpz_t(),publicKeyB.get_mpz_t());

    mpz_class secretKeyA,secretKeyB;
    mpz_powm(secretKeyA.get_mpz_t(), publicKeyB.get_mpz_t(), privateKeyA.get_mpz_t(), q);
    mpz_powm(secretKeyB.get_mpz_t(), publicKeyA.get_mpz_t(), privateKeyB.get_mpz_t(), q);

    gmp_printf("\nComputer Shared secretKeyA = %Zd, secretKeyB = %Zd\n",secretKeyA.get_mpz_t(),secretKeyB.get_mpz_t());

    return 0;

}
