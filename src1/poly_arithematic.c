#include<stdio.h>

void addition(int p1[], int p2[], int n)
{
   printf("Addition of 2 polynomial is: ");
   int add[n+1];
   for(int i=n; i>=0; i--)
   {
      add[i] = (p1[i]+p2[i])%2;
      if(add[i] == 0) continue;
      if(i!=0)
         printf("%dx%d ",add[i],i);
      else printf("%d ",add[i]);
   }

}
void subtract(int p1[], int p2[], int n)
{
   printf("\nSubtraction of 2 polynomial is: ");
   int sub[n+1];
   for(int i=n; i>=0; i--)
   {
      sub[i] = (p1[i]-p2[i])%2;
      if(sub[i] == 0) continue;
      if(i!=0)
         printf("%dx%d ",sub[i],i);
      else printf("%d ",sub[i]);
   }
}
void leftshift(int arr[], int n)
{
    for (int i = n-1 ; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = 0;
}
void XOR(int fx[], int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        fx[i] = fx[i] ^ arr[i];
    }
}
void mul(int p1[],int p2[], int p3[], int n)
{
   printf("\nMultiplication of 2 polynomial using fast multiplication is: ");

   int f[n],g[n],prod[n];
   for(int i=0; i<n; i++)
      prod[i] = 0;
   for(int i=0; i<=n; i++)
   {
      f[i] = p1[i];
      g[i] = p2[i];
   }
   if(g[0] == 1) 
   {
      for(int i=0; i<n; i++)
         prod[i] = f[i];
   }
   for(int i=0; i<n; i++)
   {
      int msb = f[n-1];
      leftshift(f,n);

      if(msb == 1)
      {
         XOR(f,p3,n);
      }
      if(g[i] == 1)
      {
         XOR(prod,f,n);
      }
   }
   for (int i = n-1; i >=0 ; i--)
    {
        printf("%dx^%d ", prod[i], i);
    }
}

int main()
{
   int n; 
   printf("Ënter N: "); 
   scanf("%d",&n);
   int poly1[n+1],poly2[n+1],poly3[n+1];
   printf("Ënter coeffecients of 1st polynomial: "); 
   for(int i=n; i>=0; i--)
   {
      scanf("%d",&poly1[i]);
   }
   printf("Ënter coeffecients of 2nd polynomial: "); 
   for(int i=n; i>=0; i--)
   {
      scanf("%d",&poly2[i]);
   }
   printf("Ënter coeffecients of 3rd polynomial: "); 
   for(int i=n; i>=0; i--)
   {
      scanf("%d",&poly3[i]);
   }
   printf("F(x) = ");
   for (int i = n; i >=0 ; i--)
    {
      if(poly1[i])
        printf("%dx^%d ", poly1[i], i);
    }
    printf("\nG(x) = ");
    for (int i = n; i >=0 ; i--)
    {
      if(poly2[i])
        printf("%dx^%d ", poly2[i], i);
    }
    printf("\nM(x) = ");
    for (int i = n; i >=0 ; i--)
    {
      if(poly3[i])
        printf("%dx^%d ", poly3[i], i);
    }
    

   addition(poly1,poly2,n);
   subtract(poly1,poly2,n);
   mul(poly1,poly2,poly3,n);
   return 0;
}