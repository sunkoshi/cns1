#include <bits/stdc++.h>
using namespace std;
int findMI(int a, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if ((a * i) % n == 1)
            return i;
    }
    return -1;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int chooseE(int et)
{
    for (int i = 2; i <= et; i++)
    {
        if (gcd(et, i) == 1)
            return i;
    }
    return -1;
}

int findD(int e, int et)
{
    return findMI(3, et);
}

int encrypt(long long m, long long e, int n)
{
    return (int)pow(m, e) % n;
}

int decrypt(long long c, int d, int n)
{

    return (int)pow(c, d) % n;
}

int main()
{
    int p, q;
    cout << "Enter P and Q ";
    cin >> p >> q;
    int n = p * q;
    int et = (p - 1) * (q - 1);
    int e = chooseE(et);
    int d = findD(e, et);
    cout << "E:" << e << endl;
    cout << "D:" << d << endl;
    int m;
    cout << "Enter M: ";
    cin >> m;

    long long c = (long long)pow(m, e) % n;
    cout << "Encrypted Value: " << c << endl;
    cout << "Decrypted Value: " << (long long)pow(c, d) % n << endl;
}