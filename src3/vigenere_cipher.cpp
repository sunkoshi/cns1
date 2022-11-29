#include<bits/stdc++.h>
using namespace std;
int main()
{
    string key;
    string msg;
    cout<<"Enter the key:-'\n";
    cin>>key;
    cout<<"Enter the message:-\n";
    cin>>msg;
    int klen=key.length();
    string s;
    for(int i=0;i<msg.length();i++)
    {
        char c=((msg[i]+key[i%klen])%26) +'a';
        s.push_back(c);
    }
    cout<<"Encrypted message:-"<<s<<endl;
    return 0;
}