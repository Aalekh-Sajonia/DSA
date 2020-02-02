#include<bits/stdc++.h>
using namespace std;

int maxLPS(string str)
{
	int n = str.length();
	int count = 0;
	for(int i=0;i<n;i++)
	{
		int l = i;
		int r = i;
		while(l>=0 && r<n && str[l]==str[r])
		{
			count++;
//			int currMax = (r-l)+1;
//			if(currMax > maxLps)
//			{
//				maxLps = currMax;	
//			} 
			l--;
			r++;
		}
		
		l=i;
		r=i+1;
		while(l>=0 && r<n && str[l]==str[r])
		{
			count++;
//			int currMax = (r-l)+1;
//			if(currMax > maxLps)
//			{
//				maxLps = currMax;	
//			} 
			l--;
			r++;
		}
	}
	return count;
}

int main()
{
	string str;
	cin>>str;
	cout<<maxLPS(str);
	
	return 0;
}
