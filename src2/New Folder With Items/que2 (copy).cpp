#include <bits/stdc++.h>
using namespace std;

#define ll long long int
ll const mod = 26;

ll power(ll a, ll b, ll mod)
{
	if(a == 1 || b == 0) return 1;

	ll d = power(a , b/2 , mod);
	d = ((d%mod) * (d%mod)) % mod;

	if(b%2) {
		d = ((d%mod) * (a%mod)) % mod;
	}

	return d;
}

string conv(string &s, char padding, int d)
{
	string t = "";
	for(int i=0; i<s.size(); i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z') {
			t += s[i];
		}
		else if(s[i] >= 'A' && s[i] <= 'Z') {
			t += 'a' + (s[i] - 'A');
		}
	}

	while(t.size()%d != 0) {
		t += padding;
	}

	return t;
}

ll find(ll n)
{
	while(n < 0) {
		n += mod;
	}
	return n;
}

vector<int> mul(vector<vector<int> > &key, vector<int> &A)
{
	vector<int> B;
	int d = key.size();

	for(int i=0; i<d; i++)
	{
		int sum = 0;
		for(int j=0; j<d; j++)
		{
			int x = key[i][j] * A[j];
			sum += x;
		}
		sum = find(sum);
		sum %= 26;
		B.push_back(sum);
	}

	return B;
}

string encp(string &s, vector<vector<int> > &key)
{
	string t = "";
	int d = key.size();

	for(int i=0; i<s.size(); i+=d)
	{
		vector<int> B;
		for(int j=0; j<d; j++) {
			B.push_back(s[i+j] - 'a');
		}

		vector<int> C = mul(key , B);

		for(auto &it : C) {
			t += 'a' + it;
		}
	}

	return t;
}

int det(vector<vector<int> > &key)
{
	int d = (key[0][0] * key[1][1]) - (key[0][1] * key[1][0]);
	return d;
}

int mul_inv(int n)
{
	for(int i=1; i<26; i++)
	{
		int d = ((n%26) * (i%26)) % 26;
		if(d == 1) return i;
	}
}

vector<vector<int> > inverse(vector<vector<int> > &key)
{
	vector<vector<int> > inv = key;
	swap(inv[0][0] , inv[1][1]);
	// swap(inv[0][1] , inv[1][0]);

	inv[0][1] *= -1;
	inv[1][0] *= -1;

	ll x = det(key);
	x = mul_inv(x);

	for(int i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
		{
			ll p = ((inv[i][j]%mod) * (x%mod)) % mod;
			inv[i][j] = p;
		}
	}

	return inv;
}

string decp(string &s, vector<vector<int> > &key)
{
	string t = "";
	int d = key.size();
	vector<vector<int> > inv = inverse(key);
	int dete = det(key);

	for(int i=0; i<s.size(); i+=d)
	{
		vector<int> B;
		for(int j=0; j<d; j++) {
			B.push_back(s[i+j] - 'a');
		}

		vector<int> C = mul(inv , B);

		for(auto &it : C) {
			t += 'a' + it;
		}
	}

	return t;
}

int main()
{

	string plain_text, chipher_text;
	char padding;

	cout<<"Plain Text : ";
	cin>>plain_text;

	cout<<"Enter padding character : "; 
	cin>>padding;

	vector<vector<int> > key(2 , vector<int> (2));
	key[0][0] = 9; key[0][1] = 4;
	key[1][0] = 5; key[1][1] = 7;

	int d = key.size();
	plain_text = conv(plain_text , padding , d);
	
	chipher_text = encp(plain_text , key);

	cout<<"Chipher text : "<<chipher_text<<endl;
	cout<<"Plain Text : "<<decp(chipher_text , key)<<endl;

	return 0;
}