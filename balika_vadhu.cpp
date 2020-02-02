#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
string str1,str2;
ll dp[150][150][150];
ll ascii(int s1,int s2,int k)
{
	if(s1==n || s2==m)
	{
		if(k>0)
		{
			return INT_MIN;
		}
		else
		return 0;
	}
	
	if(dp[s1][s2][k]!=-1)
	{
		return dp[s1][s2][k];
	}
	if(str1[s1] == str2[s2])
	{
		if(k>0)
		{
			return dp[s1][s2][k] = max(str1[s1] + ascii(s1+1,s2+1,k-1),
				   max(ascii(s1+1,s2,k),ascii(s1,s2+1,k)));
		}
		else
		return 0 ;
	}
	
	return dp[s1][s2][k] = max(ascii(s1+1,s2,k),
				ascii(s1,s2+1,k));
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	memset(dp,-1,sizeof dp);
	cin>>str1;
	cin>>str2;
	int k;
	cin>>k;
	n = str1.size();
	m = str2.size();
		
	cout<<max((ll)0,ascii(0,0,k))<<endl;
	}
    return 0;
}


