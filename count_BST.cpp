#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


int *dp = new int[1001]();
int mod = 1000000000+7;
int countBST( int n)
{
	int ans=0;
  	dp[0]=1;
  	dp[1]=1;
   	for(int i=2;i<=n;i++)
   	{
   		dp[i]=0;
   		for(int k=0;k<i;k++)
   		{
            int temp;
   			temp = (int)(dp[k] * dp[i-k-1])%mod;
			dp[i] = (dp[i]+temp)%mod;
		}
	}
	
    return dp[n]%mod;

}





int main()
{
	int n ;
	cin>>n;
	int k=1;
	cout<<countBST(n);
	return 0;
}

