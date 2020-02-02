#include<bits/stdc++.h>
using namespace std;

int dp[120][10000];

int ans(int *weights,int *values,int n,int maxWeight)
{
	if(n<0)
	{
		return 0;
	}
	
	if(maxWeight<=0)
	{
		return 0;
	}
	
	if(dp[n][maxWeight]!=-1)
	{
		return dp[n][maxWeight];	
	}	
	
	if(maxWeight>=weights[n-1])
	{
		return dp[n][maxWeight] = max( values[n-1] + ans(weights,values,n-1,maxWeight-weights[n-1]),
					ans(weights,values,n-1,maxWeight) );
	}
	else
	{
		return dp[n][maxWeight] = ans(weights,values,n-1,maxWeight);
	}
}


int knapsack(int* weights, int* values, int n, int maxWeight){
	
	for(int i=0;i<120;i++)
	{
		for(int j=0;j<10000;j++)
		{
			dp[i][j]=-1;
		}
	}
	return ans(weights,values,n,maxWeight);
}





int main(){

  int maxWeight;
  cin >> maxWeight;
  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
    cin >> values[i];
  }



	int ans = knapsack(weights, values, n, maxWeight);
  cout << ans;
}



