#include<bits/stdc++.h>
using namespace std; 
int maxProfit(int price[], int n, int k) 
{ 
    
    int profit[k + 1][n + 1]; 
  

    for (int i = 0; i <= k; i++) 
        profit[i][0] = 0; 
  

    for (int j = 0; j <= n; j++) 
        profit[0][j] = 0; 
  

    for (int i = 1; i <= k; i++) 
	{ 
        for (int j = 1; j < n; j++) 
		{ 
            int max_till_now = INT_MIN; 
  
            for (int m = 0; m < j; m++) 
                max_till_now = max(max_till_now, 
                                 price[j] - price[m] + profit[i - 1][m]); 
  
            profit[i][j] = max(profit[i][j - 1], max_till_now); 
        } 
    } 
  
    return profit[k][n - 1]; 
} 
  

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
    int n,k;
    cin>>k>>n;
    int price[n];

	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}
  
    cout<< maxProfit(price, n, k)<<endl; 
	}
    return 0; 
} 
