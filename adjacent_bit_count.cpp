#include <bits/stdc++.h> 
#define ll long long
#define mod 1000000007
using namespace std; 
#define MAX 1000
ll waysToKAdjacentSetBits(int dp[][MAX][2],int n, int k, int currentIndex, 
						int adjacentSetBits, int lastBit) 
{ 

	if (currentIndex == n) { 

		if (adjacentSetBits == k) 
			return 1; 
		return 0; 
	} 

	if (dp[currentIndex][adjacentSetBits][lastBit] != -1) 
	{ 
        return dp[currentIndex][adjacentSetBits][lastBit]; 
    } 
	int noOfWays = 0; 

	if (lastBit == 1) { 
		noOfWays += waysToKAdjacentSetBits(dp,n, k, currentIndex + 1, 
											adjacentSetBits + 1, 1); 
		noOfWays += waysToKAdjacentSetBits(dp,n, k,currentIndex + 1, 
												adjacentSetBits, 0); 
		
	} 
	else if (!lastBit) { 
		noOfWays += waysToKAdjacentSetBits(dp,n, k, currentIndex + 1, 
												adjacentSetBits, 1); 
		noOfWays += waysToKAdjacentSetBits(dp,n, k, currentIndex + 1, 
												adjacentSetBits, 0); 
	} 
	
	noOfWays %= mod;
	dp[currentIndex][adjacentSetBits][lastBit] = noOfWays;
	return noOfWays; 
} 


int main() 
{ 
	int dp[MAX][MAX][2]; 
    memset(dp, -1, sizeof(dp)); 
	int t,n,k,count;
	cin>>t;
	while(t--)
	{
    memset(dp, -1, sizeof(dp)); 
	cin>>count>>n>>k;
	ll totalWays = (waysToKAdjacentSetBits(dp,n, k, 1, 0, 1) 
					+ waysToKAdjacentSetBits(dp,n, k, 1, 0, 0)); 

	cout <<count<<" "<< totalWays%mod << endl ; 
	}
	return 0; 
} 

