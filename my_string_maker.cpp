#include<bits/stdc++.h>
using namespace std;
int dp[55][55][55];
#define max 1000000007
int makeString(string a,string b,string c,int la,int lb,int lc)
{
	if(lc==0)
	{
		return 1;
	}
	if(la<=0 && lb<=0)
	{
		return 0;
	}
	
	if(dp[la][lb][lc] != -1)
	{
		return dp[la][lb][lc];
	}
	
	int number = 0;
	for(int i=la-1;i>=0;i--)
	{
		if(c[lc-1] == a[i])
		{
			number = (number + makeString(a,b,c,i,lb,lc-1))%max; 
		}
	}
	
	for(int j=lb-1;j>=0;j--)
	{
		if(c[lc-1] == b[j])
		{
			number = (number + makeString(a,b,c,la,j,lc-1))%max;
		}
	}
	dp[la][lb][lc] = number;
	return number;
}

int solve(string a,string b,string c)
{
	memset(dp,-1,sizeof(dp));
	int la = a.length();
	int lb = b.length();
	int lc = c.length();
	return makeString(a,b,c,la,lb,lc);
}

int main()
{
	string a,b,c;
	cin>>a>>b>>c;
	cout<<solve(a,b,c)<<endl;
	return 0;
}
