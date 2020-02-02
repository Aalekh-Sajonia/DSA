#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b)  //obv a>b
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}

ll reduce(ll a,string b)
{
	ll mod = 0;
	
	for(int i=0;i<b.length();i++)
	{
		mod = (mod*10 + b[i] - '0')%a;
	}
	
	return mod;
}

ll calGCD(string b,ll a)
{
	ll num = reduce(a, b);
	return gcd(max(num,a),min(num,a));
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a;
		ll b;
		cin>>b;
    	cin>>a;
    	if(a[0] == '0' || b==0)
    	{
    		cout<<'0'<<endl;
    		continue;
		}
		cout<<calGCD(a,b);
		cout<<endl;
	}

	return 0;
}
