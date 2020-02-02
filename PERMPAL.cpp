#include<bits/stdc++.h>
using namespace std;
char getChar(int i)
{
	return (char)(i+97);
}
void palindrome(string s)
{
	map<int,vector<int>> m;
	for(int i=0;i<s.length();i++)
	{
		m[s[i]].push_back(i);
	}
	
	int odd_count = 0;
	for(int i=0;i<26;i++)
	{
		if((m[getChar(i)].size()%2)!=0)
		{
			odd_count++;
		}
	}
	if(odd_count>=2)
	{
		cout<<"-1"<<endl;
		return ;
	}
	
	int ans[s.length()];
	int str=0;
	int end=s.length()-1;
	for(int i=0;i<26;i++)
	{
		char currentChar = getChar(i);
		for(int j=0;j<m[currentChar].size();j+=2)
		{
			if(m[currentChar].size()-j==1)
			{
				ans[s.length()/2] = m[currentChar].at(j)+1;
				continue;
			}
			ans[str] = m[currentChar].at(j)+1;
			ans[end] = m[currentChar].at(j+1)+1;
			str++;
			end--;
		}
	}
	for(int i=0;i<s.length();i++)
	{
		cout<<ans[i]<<" ";
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		palindrome(s);
		cout<<endl;
	}
	return 0;
}
