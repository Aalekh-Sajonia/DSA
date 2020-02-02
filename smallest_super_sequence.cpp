#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[100][100] ;

int callme(char str1[],int len1,char str2[],int len2)
{
	if(len1==0)
	{
		return len2;
	}
	if(len2==0)
	{
		return len1;
	}
	if(len1==0 && len2==0)
	{
		return 0;
	}
	if(dp[len1][len2] != -1)
	return dp[len1][len2];
	
	if(str1[len1-1] == str2[len2-1])
	{
		return  dp[len1][len2] = 1 + callme(str1,len1-1,str2,len2-1);
	}
	else
	{
		return dp[len1][len2] = 1 + min(callme(str1,len1-1,str2,len2),
						callme(str1,len1,str2,len2-1));
	}
}


int smallestSuperSequence(char str1[], int len1, char str2[], int len2) 
{
	memset(dp,-1,sizeof(dp));
	return callme(str1,len1,str2,len2);
}


int main()
{

    char str1[50], str2[50];
    cin>>str1;
    cin>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = smallestSuperSequence(str1, len1, str2, len2);
    cout<<min_len;
    return 0;
}

