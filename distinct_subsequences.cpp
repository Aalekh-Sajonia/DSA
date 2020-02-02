#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MAX_CHAR = 500;
const int MOD = 1000000007;
int fun(string str)
{
	int last[256];
	for(int i=0;i<256;i++)
	{
		last[i] = -1;
	}
	
	ll length = str.length();
	
	ll dp[length+1];
	
	dp[0] = 1;  
	
	for(ll i=1;i<=length;i++)
	{
		dp[i] = 2*dp[i-1];
		dp[i] %= MOD;
		
		if(last[str[i-1]] != -1)
		{
			dp[i] = dp[i] - dp[last[str[i-1]]];
			if(dp[i]< 0)
			dp[i]+=MOD;
		}
		last[str[i-1]] = i-1;
	}
	
	return dp[length];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int ans = fun(s);
		cout<<ans%MOD<<endl;
	}
    return 0;
}

