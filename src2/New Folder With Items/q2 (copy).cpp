#include<bits/stdc++.h>
using namespace std;

string convertBinaryToAscii(string binary){
    string ascii = "";
    for (int i = 0; i < binary.length(); i += 8){
        string temp = binary.substr(i, 8);
        char c = (char)bitset<8>(temp).to_ulong();
        ascii += c;
    }
    return ascii;
}

string convertDecimalToBinary(int decimal)
{
    string binary;
    while (decimal != 0) {
        binary = (decimal % 2 == 0 ? "0" : "1") + binary;
        decimal = decimal / 2;
    }
    while (binary.length() < 4) {
        binary = "0" + binary;
    }
    return binary;
}

int convertBinaryToDecimal(string binary)
{
    int decimal = 0;
    int counter = 0;
    int size = binary.length();
    for (int i = size - 1; i >= 0; i--)
    {
        if (binary[i] == '1') {
            decimal += pow(2, counter);
        }
        counter++;
    }
    return decimal;
}


int main(){
	int a, b;
	cout<<"Enter a, b: ";
	cin>>a>>b;
	cout<<"Enter coefficients in L to S: ";
	string s="";
	char temp;
	for(int i=0;i<b;i++){
		cin>>temp;
		s+=temp;
	}
	int n = pow(a,b);
	int irr = convertBinaryToDecimal(s);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int temp = (i*j)%irr;
			cout<< temp<<" ";
		}
		cout<<endl;
	}
}
