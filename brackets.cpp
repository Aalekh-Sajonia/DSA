#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int brackets(int o,int c,int total,bool *record)
{
	if(o>total || c>total) //to be on safe side not required
	return 0;
	
	if(o==total && c==total)
	{
		return 1;
	}
	
	if(dp[o][c]!=-1)
	return dp[o][c];
	
	int curIndex = o+c;
	if(o==c || record[curIndex])
	{
		return dp[o][c] = brackets(o+1,c,total,record);		
	}
	else if(o==total)
	{
		return dp[o][c] = brackets(o,c+1,total,record);
	}
	else
	{
		return dp[o][c] = brackets(o+1,c,total,record) + brackets(o,c+1,total,record);
	}
	
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	
	memset(dp,-1,sizeof(dp));	
	int n;
	cin>>n;
	int k;
	cin>>k;
	bool record[2*n+20] = {false};
	record[0] = true;
	for(int i=0;i<k;i++)
	{
		int a;
		cin>>a;
		record[a-1] = true;
	}
	cout<<brackets(0,0,n,record)<<endl;
	}
	return 0;
}
