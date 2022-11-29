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

int main()
{
    int b, p, n;
    cout << "Enter B, P, N: ";
    cin >> b >> p >> n;
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
    cout << curr;
}