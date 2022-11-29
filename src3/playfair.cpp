#include<bits/stdc++.h>
using namespace std;
int main()
{
    char k[5][5];
    string msg,key;
    cout<<"Enter the key:-";
    cin>>key;
    cout<<"\nEnter the message:-";
    cin>>msg;
    
    int n=0;
    map<char,char>m;
    for(int i=0;i<key.length();i++)
    {
        if(key[i]=='j')
        {
            key[i]='i';
        }
        m[key[i]]++;
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            n=i*5+j;
            if(n==key.length())
            {
                break;
            }
            k[i][j]=key[n];

        }
        if(n==key.length())
        {
            break;
        }
    }
    
    int I,J;
    I=(key.length())/5;
    J=(key.length())%5;
    for(int i=0;i<26;i++)
    {
        if('a'+i=='j')
        {
            continue;
        }
        if(m.find((char)('a'+i))==m.end())
        {
           // cout<<(char)('a'+i)<<endl;
            k[I][J++]=(char)('a'+i);
            if(J==5)
            {
                J=0;
                I++;
            }
        }
    }
    string s;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
           // cout<<k[i][j]<<" ";
        }
       // cout<<endl;
    }
    
    for(int K=0;K<msg.length();K=K+2)
    {
        char a, b;
        int I1=-1,I2=-1,J1=-1,J2=-1;
        a=msg[K];
        if(K+1<msg.length())
        {
            b=msg[K+1];
        }
        else
        {
            b='x';
        }
        if(a==b)
        {
            b='x';
        }
        if(a=='j')
        {
            a='i';
        }
        if(b=='j')
        {
            b='i';
        }
      //  cout<<a<<" "<<b<<endl;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(k[i][j]==a)
                {
                    I1=i;
                    J1=j;
                }
                if(k[i][j]==b)
                {
                    I2=i;
                    J2=j;
                }
            }
        }
       // cout<<I1<<" "<<I2<<" "<<J1<<" "<<J2<<endl;
        if(I1==I2)
        {
            s.push_back(k[I1][(J1+1)%5]);
            s.push_back(k[I2][(J2+1)%5]);
        }
        else if(J1==J2)
        {
            s.push_back(k[(I1+1)%5][J1]);
            s.push_back(k[(I2+1)%5][J2]);
        }
        else
        {
            s.push_back(k[I1][J2]);
            s.push_back(k[I2][J1]);
        }
    }
    
    cout<<"Encrypter message is :-"<<s<<endl;
    return 0;
}