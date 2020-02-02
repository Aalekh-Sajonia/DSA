#include<bits/stdc++.h>
using namespace std;  
#define MAX 10000000
int dp[2000][2000];
int ans(char *S, char *T, int m, int n) 
{ 
    if (m == 0) 
        return MAX; 
  
    // T string is empty 
    if (n <= 0) 
        return 1; 
  	
  	if(dp[m][n]!=-1)
  	return dp[m][n];
    int k; 
    for (k=0; k < n; k++) 
        if (T[k] == S[0]) 
            break; 
  
    if (k == n)  //char not found
        return 1; 
  

    return dp[m][n] = min(ans(S+1, T, m-1, n), 
            1 + ans(S+1, T+k+1, m-1, n-k-1)); 
} 


int solve(string S,string V)
{
	int len1 = S.size();
	int len2 = V.size();
	memset(dp,-1,sizeof(dp));
	char ch1[len1+1];
	char ch2[len2+1];
	strcpy(ch1,S.c_str());
	strcpy(ch2,V.c_str());
//	cout<<ch1<<" "<<ch2;
	return ans(ch1,ch2,len1,len2);
}

int main()
{
	string S,V;
	cin>>S>>V;
	cout<<solve(S,V)<<endl;
	return 0;
}
