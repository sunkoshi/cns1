#include<bits/stdc++.h>
#include <time.h>
#include <cstdlib>
#include<gmp.h>
#include <functional>
using namespace std;
gmp_randstate_t state;
void generateRandomPrimes(mpz_t *prime,int bits)
{   
    while(true)
    {
        mpz_urandomb(*prime, state, bits);
        if (mpz_probab_prime_p(*prime, 25) == 1 || mpz_probab_prime_p(*prime, 25) == 2)
          break;
    }
    
}
string hashMessage(string s)
{
   string hashed = "";
   for (int i = 0; i <= s.length(); i++)
      {
         // convert each char to
         // ASCII value
         int val = int(s[i]);
         hashed += to_string(val);
      }
      return hashed;
}
int main(){
   srand (time(0));
   
   gmp_randinit_mt(state);
	unsigned long seed;
	seed = time(NULL);
	gmp_randseed_ui(state,seed);

   mpz_t p,q,alpha,h,n,k,k_i,r,s,e,d,w,u1,u2,v,MD,temp1,temp2;
	mpz_inits(p,q,alpha,h,n,k,k_i,r,s,e,d,w,u1,u2,v,MD,temp1,temp2,NULL);


   //generating random prime p and q
   mpz_set_ui(temp1,10);
   mpz_set_ui(temp2,5);
   int bits1 = mpz_get_ui(temp1);
   int bits2 = mpz_get_ui(temp2);
   generateRandomPrimes(&p,bits1);
   generateRandomPrimes(&q,bits2);
   mpz_sub_ui(temp2,p,1);
   mpz_fdiv_r(temp1,temp2,q);
   while(mpz_cmp_ui(temp1,0)!=0)
   {
      generateRandomPrimes(&p,bits1);
      generateRandomPrimes(&q,bits2);
      mpz_sub_ui(temp2,p,1);
      mpz_fdiv_r(temp1,temp2,q);
   } 
   // mpz_set_ui(p,919);
   // mpz_set_ui(q,17);
	gmp_printf("Value of large prime p: %Zd\n",p);
	gmp_printf("Value of large prime q: %Zd\n",q);

   

   // 1 < h < p
   mpz_urandomm(h,state,p);
   // mpz_set_ui(h,849);
   if(mpz_cmp_ui(h,1)<=0) 
      mpz_add_ui(h,h,1);

   // finding alpha such that, alpha**q mod p = 1 and alpha = h**((p–1)/q)
   mpz_set_ui(alpha,1);   
   while(mpz_cmp_ui(alpha,1) == 0)
   {
      mpz_sub_ui(temp2,p,1);
      mpz_fdiv_q(temp1,temp2,q);
      mpz_powm(alpha,h,temp1,p);
   }
   gmp_printf("Value of alpha: %Zd\n",alpha);

   // Private Key d : 0 < d < q
   mpz_urandomm(d,state,q);
   // mpz_set_ui(d,2);
   if(mpz_cmp_ui(d,0)==0) 
      mpz_add_ui(d,d,1);

   gmp_printf("Private Key for decryption (d)= %Zd\n",d);

   // computing public key e : alpha**d mod p
   mpz_powm(e,alpha,d,p);
   gmp_printf("Computed Public Key for encryption (e)= %Zd\n",e);


   cout<<"DSA Signing in progress......"<<endl;

   string M;
   cout<<"Enter the message to be signed: ";
   getline(cin,M); 
  
   // generating Message Digest
   
   
   string M_t = hashMessage(M);
   char *str = new char [M_t.length()+1];
   strcpy(str, M_t.c_str());
   mpz_set_str(MD,str,10);
   gmp_printf("Sent Message Digest (MD)= %Zd\n",MD);
      
   mpz_set_ui(r,0);
   mpz_set_ui(s,0);
   while(mpz_cmp_ui(r,0) == 0 || mpz_cmp_ui(s,0) ==0)
   {
      // random ephemeral key K : 0 < K < q
      mpz_urandomm(k,state,q);
      if(mpz_cmp_ui(k,0)==0) 
         mpz_add_ui(k,d,1);
      // gmp_printf("Random Ephermal Key(k)= %Zd\n",k);
      
      
      // (alpha**k mod p) mod q. If r = 0, select a different k.
      mpz_powm(r,alpha,k,p);
      mpz_mod(r,r,q);
      // gmp_printf("r= %Zd\n",r);


      // modular multiplicative inverse of k modulo q 
      mpz_invert(k_i,k,q);

      //  s = k_i*(MD+r*d) mod q. If s = 0, select a different k.
      mpz_mul(temp2,r,d);
      mpz_add(temp1,MD,temp2);
      mpz_mul(temp2,k_i,temp1);
      mpz_mod(s,temp2,q);
      // gmp_printf("s= %Zd\n",s);
   }

   gmp_printf("Random Ephermal Key(k)= %Zd\n",k);
   gmp_printf("Digital Signature {r,s}= {%Zd, %Zd}\n",r,s);

   cout<<"DSA Verification in progress......"<<endl;

   
   int opt = rand()%2; // to randomly alter message recieved 
   if(opt == 1)
   {
      string newM = "If message received is altered";
      string newM_t = hashMessage(newM);
      char *newStr = new char [newM_t.length()+1];
      strcpy(newStr, newM_t.c_str());
      mpz_set_str(MD,newStr, 10);
   }   
   gmp_printf("Recieved Message Digest (MD)= %Zd\n",MD);


   //computing w = the modular multiplicative inverse of s modulo q
   mpz_invert(w,s,q);
   gmp_printf("Auxiliary Value(w)= %Zd\n",w);

   // Compute u1 = MD*w mod q.
   mpz_mul(temp2,MD,w);
   mpz_mod(u1,temp2,q);
   gmp_printf("Auxiliary Value(u1)= %Zd\n",u1);

   // Compute u2 = r*w mod q.
   mpz_mul(temp2,r,w);
   mpz_mod(u2,temp2,q);
   gmp_printf("Auxiliary Value(u2)= %Zd\n",u2);


   //Compute v = (((alpha**u1)*(e**u2)) mod p) mod q.
   mpz_powm(temp2,alpha,u1,p);
   mpz_powm(temp1,e,u2,p);
   mpz_mul(temp2,temp2,temp1);
   mpz_mod(temp2 ,temp2,p);
   mpz_mod(v,temp2,q);
   gmp_printf("Verification Constatn Value(v)= %Zd\n",v);


   if(mpz_cmp(v,r) == 0) cout<<"Valid Signature"<<endl;
   else cout<<"Not Valid Signature"<<endl;


}
