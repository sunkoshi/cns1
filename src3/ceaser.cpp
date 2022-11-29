#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    string msg;
    int k;
    cout<<"Enter the message:-";
    cin>>msg;
    cout<<"\nEnter the key:-";
    cin>>k;
    string s;
    for(int i=0;i<msg.length();i++)
    {
        int t=(msg[i]-'a'+k)%26;
        char c=('a'+t);
        s.push_back(c);
    }
    cout<<"ciphered text is:-"<<s<<endl;
    return 0;
}