#include<bits/stdc++.h>

using namespace std;
const int me = 1000025;
const int sz = 11;

int dp[sz][me], has[me];

int main() {
    
    for(int i = 2; i < me; i++)
    {
    	if(has[i]==0)
    	{
            for(int j = i; j < me; j += i)
            {
                has[j]++;
            }
    	}
	}
        
    for(int i = 0; i < sz; i++)
    {
    	int k=0;
        for(int j = 1; j < me; j++)
        {
        	if(has[j]==i)
        	{
        		k++;
			}
			dp[i][j] = k;
		}
    }
    
    int t, n, a, b;
    cin >> t;
    while(t--)
	{
        cin >> a >> b >> n;
        cout << dp[n][b] - dp[n][a - 1] << endl;
    }
    
    return 0;
}
