#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int checkIfPrime (int newPrime);
int checkRoot (int newPrime, int newRoot);
int computeYa (int newRoot, int newXa, int newPrime);
int computeInverseK (int userK, int newPrime);
int computeS2 (int inverseK, int userHash, int userXa, int userS1, int newPrime);
int computeV2 (int Ya, int S1, int S2, int newPrime);
int main ()
{
 int p = 0, q = 0, randXa = 0, UserAYa = 0, userS1 = 0, userS2 = 0;
 int primeCheck = 0, primitiveCheck = 0, userInt = 0;
 int hashValue = -1, randK = 0, inverseK = 0;
 char userChoice;
 char userMessage[256];
 int gcd;
 int V1 = 0, V2 = 0;
 printf ("Welcome to the ElGamal digital signature this works with primes up to 17\n\nThe global elements of this signature are a prime q\nand p, which is the primitive root of q\n");
 while (primeCheck == 0)
 {
 printf ("\nEnter a prime number q: ");
 scanf ("%d", &q);
 primeCheck = checkIfPrime (q);
 if (primeCheck == 1) printf (" This is in fact prime\n");
 else
 {
 printf (" Whoops, not prime\n");
 primeCheck = 0;
 }
 }
// Simple Implementation of an ElGamal Digital Signature and an attack on it 14
 while (primitiveCheck == 0)
 {
 printf ("\nEnter a primitive root of p: ");
 scanf ("%d", &p);
 primitiveCheck = checkRoot (q, p);
 if (primitiveCheck == 1) printf ("\nThis is in fact a primitive root\n");
 else
 {
 printf ("\nWhoops, not a primitive root\n");
 primeCheck = 0;
 }
 }
 printf ("\n\nNext User A generates a private/public key pair. First your random integer is generated");
 printf ("\nWould you like to enter a number greater than 1 but less than %d, y for yes or n for no: ", q - 1);
 scanf (" %c", &userChoice);
 if (userChoice == 'n')
 {
 while ((randXa <= 1) || (randXa >= q - 1))
 {
 randXa = rand ();
 }
 }
 else
 {
 while (randXa == 0)
 {
 printf ("Enter your random integer: ");
 scanf ("%d", &randXa);
 if ((randXa <= 1) || (randXa >= q - 1))
 randXa = 0;
 }
 }
 printf ("\n\nNext we computer Ya = p^Xa mod q");
 UserAYa = computeYa (p, randXa, q);
 printf ("\nUser A's Ya is %d", UserAYa);
// Simple Implementation of an ElGamal Digital Signature and an attack on it 15
 printf ("\nA's private key Xa is %d, A's public key is {q, p, Ya} {%d,%d,%d}\n",
 randXa, q, p, UserAYa);
 while (getchar () != '\n'); //Clears the buffer
 printf ("\n\nPlease enter your message:");
 scanf ("%[^\n]", userMessage);
 printf ("\nNext we are gonna give the user Message M a hash value m.");
 printf ("\nWould you like to enter one? y/n: ");
 scanf (" %c", &userChoice);
 if (userChoice == 'n')
 {
 while ((hashValue < 0) || (hashValue > q - 1))
 {
 hashValue = rand ();
 }
 }
 else
 {
 while (hashValue == -1)
 {
 printf ("Enter your hash value: ");
 scanf ("%d", &hashValue);
 if ((hashValue < 0) || (hashValue > q - 1)) hashValue = -1;
 }
 }
 printf ("\nThe hash value is %d", hashValue);
 printf ("\n\nA then forms a digital signature as follows");
 while (randK < 1)
 {
 while ((randK < 1) || (randK > q - 1))
 {
 randK = rand ();
 }
 for (int i = 1; i <= randK && i <= (q - 1); i++)
 {
 if ((randK % i == 0) && ((q - 1) % i == 0))
// Simple Implementation of an ElGamal Digital Signature and an attack on it 16
 gcd = i;
 }
 if (gcd != 1)
 randK = 0;
 }
 printf ("\n The a random integer K is generated %d\n", randK);
 printf ("\n Next we compute S1 = p^K mod q\n");
 userS1 = computeYa (p, randK, q);
 printf (" S1 is %d\n", userS1);
 printf ("\n Next we compute K^-1 mod(q-1)");
 inverseK = computeInverseK (randK, q);
 printf ("\n K^-1 is %d because %d*%d mod %d = 1", inverseK, inverseK,
 randK, q - 1);
 printf ("\n\n Next we compute S2 = K^-1(m-XaS1)mod(q-1)");
 userS2 = computeS2 (inverseK, hashValue, randXa, userS1, q);
 printf ("\n S2 is %d because it is %d*(%d - %d*%d)mod(%d) ", userS2,
 inverseK, hashValue, randXa, userS1, q - 1);
 printf ("\n\nThe signature consists of (S1, S2) which are %d , %d", userS1,
 userS2);
//Verification
 printf ("\nWould you like to verify? y/n: ");
 scanf (" %c", &userChoice);
 if (userChoice == 'y')
 {
 printf ("\n\nTo check first we calculate V1 = p^m mod q");
 V1 = computeYa (p, hashValue, q);
 printf ("\n\nThen we calculate V2 = (Ya^S1 * S1^S2)mod q");
 V2 = computeV2 (UserAYa, userS1, userS2, q);
 printf ("\n\nFinally, we check whether they equal each other");
 if (V1 == V2) printf ("\nThe signature is valid V1 %d == V2 %d\n\n", V1, V2);
 else printf ("\nSignature is invalid V1 %d != V2 %d\n\n", V1, V2);
 }
// Simple Implementation of an ElGamal Digital Signature and an attack on it 17
 return 0;
}
int computeV2 (int Ya, int S1, int S2, int newPrime)
{
 int newV2 = 0;
 long long int exYa = 1, exS1 = 1;
 while (S2 != 0)
 {
 exS1 *= S1;
 --S2;
 }
 while (S1 != 0)
 {
 exYa *= Ya;
 --S1;
 }
 exYa = exYa % newPrime;
 exS1 = exS1 % newPrime;
 newV2 = exYa * exS1;
 newV2 = newV2 % newPrime;
 return newV2;
}
int computeS2 (int inverseK, int userHash, int userXa, int userS1, int newPrime)
{
 int newS2 = 0;
 newS2 = inverseK * (userHash - (userXa * userS1));
 newS2 = newS2 % (newPrime - 1);
 if (newS2 < 0)
 newS2 = newS2 + (newPrime - 1);
 return newS2;
}
int computeInverseK (int userK, int newPrime)
{
 int inverseK = 0;
// Simple Implementation of an ElGamal Digital Signature and an attack on it 18
 int testValue, posValue = 1;
 while (inverseK == 0)
 {
 testValue = (posValue * userK) % (newPrime - 1);
 if (testValue == 1)
 {
 inverseK = posValue;
 }
 else
 {
 posValue++;
 }
 }
 return inverseK;
}
int computeYa (int newRoot, int newXa, int newPrime)
{
 long long int newYa = 1;
 while (newXa != 0)
 {
 newYa *= newRoot;
 --newXa;
 }
 newYa = newYa % newPrime;
 return (int) newYa;
}
// Checks if number is prime
int checkIfPrime (int newPrime)
{
 if (newPrime <= 1)
 return 0;
 if (newPrime > 2)
 for (int factor = 2; factor < newPrime; factor++)
// Simple Implementation of an ElGamal Digital Signature and an attack on it 19
 {
 if (newPrime % factor == 0)
 return 0;
 }
 return 1;
}
int checkRoot (int newPrime, int newRoot)
{
 long long int primeCombo = 0, modCheck = 1;
 int power;
 char result;
 if (newRoot >= newPrime) return 0;
for (int factor = 1; factor < newPrime; factor++) primeCombo = primeCombo + factor;
 printf ("\n Starting PrimeCombo %d", primeCombo);
 for (int exponent = 1; exponent < newPrime; exponent++)
 {power = exponent;
 while (power != 0){modCheck *= (long long int) newRoot; --power;}
 modCheck = modCheck % (long long int) newPrime;
 printf ("\n%d^%d mod %d is %lli", newRoot, exponent, newPrime, modCheck);
 modCheck = 1;}
 printf ("\nDid any value repeat?(y for yes or n for no) ");
 scanf (" %c", &result);
 if (result == 'y')
 return 0;
 else
 return 1;
}
