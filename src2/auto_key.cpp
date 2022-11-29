#include<bits/stdc++.h>
using namespace std;

string key_gen(string pre_key, string input){
    if (pre_key.size()>=input.size())
        return pre_key;
    int i=0;
    while(pre_key.size()!=input.size()){
        pre_key.push_back(input[i]);
        i=(i+1)%input.size();
    }
    return pre_key;
}

string cipher(string a, string key){
    for (int i=0;i<a.size();i++){
        a[i]=(((a[i]-97)+(key[i]-97))%26)+97;
    }
    return a;
}

string decipher(string a, string key){
    for (int i=0;i<a.size();i++){
        a[i]=(((a[i]-97)-(key[i]-97))%26)+97;
    }
    return a;
}

int main(){
    string a,key;
    cout<<"Enter Key: ";
    cin>>key;
    cout<<"Enter Text: ";
    cin>>a;
    string c = cipher(a, key);
    cout<<"Cipher Text: "<< c <<endl;
    cout<<"Decipher Text: "<< decipher(c, key)<<endl;
}
