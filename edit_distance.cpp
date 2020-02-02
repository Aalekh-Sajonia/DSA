#include<iostream>
#include<cstring>
using namespace std;

int min(int a,int b,int c)
{
	return min(min(a,b),c);
}

int output(string s1,string s2,int n,int m)
{
	int **dp = new int*[n+1];
	for(int i=0;i<n+1;i++)
	{
		dp[i] = new int[m+1];
	}
	
	for(int i=0;i<n+1;i++)
	{
		dp[i][0] = i;
	}
	for(int j=0;j<m+1;j++)
	{
		dp[0][j] = j;
	}
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			if(s1[n-i]==s2[m-j])
			{
				dp[i][j]= dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = 1+ min(dp[i-1][j-1],
								  dp[i-1][j],
								  dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
	
}


/*int output(string s1,string s2,int n, int m)
{
	if(n==0)
	{
		return m;
	}
	if(m==0)
	{
		return n;
	}
	
	if(s2[m-1]==s1[n-1])
	{
		return output(s1,s2,n-1,m-1);
	}
	return 1 + min(
						output(s1,s2,n,m-1), //insert
						output(s1,s2,n-1,m), //remove
						output(s1,s2,n-1,m-1)//replace
						);
}
*/
int editDistance(string s1, string s2)
{
	int l1 = s1.size();
	int l2 = s2.size();
	int ans = output(s1,s2,l1,l2);	
	return ans;
}

int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}




