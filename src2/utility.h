#include <bits/stdc++.h>
using namespace std;
vector<int> toBinary(int n)
{
    vector<int> res;
    while (n != 0)
    {
        res.push_back(n % 2);
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int BpowPmodN(int b, int p, int n)
{

    vector<int> bin = toBinary(p);
    int prev = b;
    int curr = prev;
    for (int i = 1; i < bin.size(); i++)
    {
        curr = (int)pow(prev, 2) % n;
        if (bin[i] == 1)
        {
            curr = (curr * b) % n;
        }
        prev = curr;
    }
    return curr;
}

int primitiveRoot(int q)
{
    for (int i = 1; i < q; i++)
    {
        set<int> s;
        for (int j = 1; j < q; j++)
        {
            s.insert(BpowPmodN(i, j, q));
        }
        if (s.size() == q - 1)
            return i;
    }
    return -1;
}

int randomNBetween(int min, int max)
{
    return (min + (rand() % static_cast<int>(max - min + 1)));
}

int findMI(int a, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if ((a * i) % n == 1)
            return i;
    }
    return -1;
}