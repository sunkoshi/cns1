#include <bits/stdc++.h>
using namespace std;

int main()
{
	int mod = 21; // x^4 + x^2 + 1 --> 10101 -> 21
	int n = 16;   // GF(2^4)

	vector<vector<int> > A(n , vector<int>(n));

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			int d = i * j;
			d %= mod;
			A[i][j] = d;
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++) {
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}