#include <bits/stdc++.h>
using namespace std;

string key_gen(int len)
{
    string temp = "abcdefghijklmnopqrstuvwxyz";
    string key = "";
    for (int i = 0; i < len; i++)
    {
        key += temp[rand() % 26];
    }
    return key;
}

string cipher(string a, string key)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = (((a[i] - 97) + (key[i] - 97)) % 26) + 97;
    }
    return a;
}

string decipher(string a, string key)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = ((((a[i] - 97) - (key[i] - 97)) + 26) % 26) + 97;
    }
    return a;
}

int main()
{
    string a;
    cout << "Enter string: ";
    cin >> a;
    string key = key_gen(a.size());
    string c = cipher(a, key);
    cout << "Cipher Text: " << c << endl;
    cout << "Decipher Text: " << decipher(c, key) << endl;
}
