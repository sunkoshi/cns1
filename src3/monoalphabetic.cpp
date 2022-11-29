#include<bits/stdc++.h>
using namespace std;
int main()
{
    string key;
    map<char,char>m;
    string msg;
    cout<<"Enter the 26 letter key:-";
    cin>>key;
    cout<<"\nEnter the message:-";
    cin>>msg;
    for(int i=0;i<26;i++)
    {
        m['a'+i]=key[i];
    }
    string s;
    for(int i=0;i<msg.length();i++)
    {
        s.push_back(m[msg[i]]);
    }
    cout<<"\nEncrypted message is :-"<<s<<endl;
    return 0;
}