#include<iostream>
using namespace std;

#include<bits/stdc++.h>
int minCount(int n)
{
    int* dp = new int[n + 1]; 
    dp[0] = 0; 
    dp[1] = 1; 
    dp[2] = 2; 
    dp[3] = 3; 
    for (int i = 4; i <= n; i++) 
	{ 
		//cout<<ceil(sqrt(i));
        dp[i] = i; 
        for (int x = 1; x <= ceil(sqrt(i)); x++) 
		{ 
            int temp = x * x; 
            if (temp > i) 
                break; 
            else
            {
                dp[i] = min(dp[i], 1 + dp[i - temp]);
				//cout<<dp[i];
			}
        } 
    }
    int res = dp[n]; 
    delete[] dp; 
    return res;   
}

int main(){
    
    int num;
    cin >> num;
    cout << minCount(num);
    
}


