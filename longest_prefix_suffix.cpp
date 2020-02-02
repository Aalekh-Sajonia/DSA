#include<bits/stdc++.h>
using namespace std;
int index;
int *getLps(string str)
{
	int len = str.length();
	int *lps = new int[len];
	
	int i=1;
	int j=0;
	lps[0] = 0;
	
	while(i<len)
	{
		if(str[i]==str[j])
		{
			lps[i] = j+1;
			j++;
			i++;
		}
		else
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}

void kmpSearch(string str,string pattern)
{
	int lenStr = str.length();
	int lenPat = pattern.length();
	
	int i=0;
	int j=0;
	
	int *lps = getLps(pattern);
	
	while(i<lenStr && j<lenPat)
	{
		if(str[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	if(j==lenPat)
	{
		index = i-lenPat;
		return;
	}
	index = -1;
	return ;
}

int main()
{
	string str;
	string subStr;
	cin>>str>>subStr;
	kmpSearch(str,subStr);
	cout<<index;
	return 0;
}
