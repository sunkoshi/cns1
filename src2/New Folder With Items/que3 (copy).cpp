#include <bits/stdc++.h>
using namespace std;

int pc1[56] = {57 , 49 , 41 , 33 , 25 , 17 , 9 ,
				1 , 58 , 50 , 42 , 34 , 26 , 18 , 
				10 , 2 , 59 , 51 , 43 , 35 , 27 , 
				19 , 11 , 3 , 60 , 52 , 44 , 36 , 
				63 , 55 , 47 , 39 , 31 , 23 , 15 , 
				7 , 62 , 54 , 46 , 38 , 30 , 22 , 
				14 , 6 , 61 , 53 , 45 , 37 , 29 , 
				21 , 13 , 5 , 28 , 20 , 12 , 4};

int pc2[48] = {14 , 17 , 11 , 24 , 1 , 5 , 3 , 28 , 
				15 , 6 , 21 , 10 , 23 , 19 , 12 , 4 , 
				26 , 8 , 16 , 7 , 27 , 20 , 13 , 2 , 
				41 , 52 , 31 , 37 , 47 , 55 , 30 , 40 , 
				51 , 45 , 33 , 48 , 44 , 49 , 39 , 56 , 
				34 , 53 , 46 , 42 , 50 , 36 , 29 , 32};

vector<string> keys;

string ls_1(string s)
{
	string t = s;
	int n = t.size();

	char ch = t[0];
	for(int i=1; i<n; i++) {
		t[i-1] = t[i];
	}
	t[n-1] = ch;

	return t;
}

string ls_2(string s)
{
	string t = s;
	int n = t.size();

	for(int k=0; k<2; k++)
	{
		char ch = t[0];
		for(int i=1; i<n; i++) {
			t[i-1] = t[i];
		}
		t[n-1] = ch;
	}

	return t;
}

void key_generatiion(string &s)
{
	string t = s;
	for(int i=0; i<56; i++) {
		t += s[pc1[i]-1];
	}

	string left = t.substr(0 , 28);
	string right = t.substr(28 , 28);

	for(int i=0; i<16; i++)
	{
		if(i == 0 || i == 1 || i == 8 || i == 15) {
			left = ls_1(left);
			right = ls_1(right);
		}

		else {
			left = ls_2(left);
			right = ls_2(right);
		}

		string comb = left + right;

		string key = "";
		for(int j=0; j<48; j++) {
			key += comb[pc2[j]-1];
		}

		keys.push_back(key);
	}

	return ;
}

string dec_bin(int n)
{
	string s = "";
	while(n) 
	{
		int d = n%2; n /= 2;
		s.push_back('0'+d);
	}

	while(s.size() < 4) {
		s.push_back('0');
	}

	reverse(s.begin() , s.end());
	return s;
}

string hex_bin(string s)
{
	int n = s.size();
	string ans = "";

	for(int i=0; i<n; i++)
	{
		if(s[i] >= '0' && s[i] <= '9') {
			ans += dec_bin(s[i] - '0');
		}

		else if(s[i] == 'a') {
			ans += dec_bin(10);
		}

		else if(s[i] == 'b') {
			ans += dec_bin(11);
		}

		else if(s[i] == 'c') {
			ans += dec_bin(12);
		}

		else if(s[i] == 'd') {
			ans += dec_bin(13);
		}

		else if(s[i] == 'e') {
			ans += dec_bin(14);
		}

		else if(s[i] == 'f') {
			ans += dec_bin(15);
		}
	}

	return ans;
}

int find(string s)
{
	int ans = 0;
	int val = 8;
	for(int i=0; i<s.size(); i++) {
		ans += ((s[i] - '0') * (val));
		val /= 2;
	}
	return ans;
}

char bin_hex(string s)
{
	int d = find(s);
	if(d >= 0 && d <= 9) return '0' + d;
	else if(d == 10) return 'a';
	else if(d == 11) return 'b';
	else if(d == 12) return 'c';
	else if(d == 13) return 'd';
	else if(d == 14) return 'e';
	else return 'f';
}

int main()
{
	string key = "0f1571c947d9e859";
	string p = hex_bin(key);
	key_generatiion(p);

	cout<<keys.size()<<" keys are generated"<<endl;

	for(int i=0; i<keys.size(); i++) 
	{
		string p = keys[i];
		string z = "";

		for(int j=0; j<p.size(); j+=4)
		{
			z = "";
			for(int l=0; l<4; l++) {
				z += p[j+l];
			}
			cout<<bin_hex(z);
		}
		cout<<endl;
	}

	return 0;
}
