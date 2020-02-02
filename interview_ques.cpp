#include<bits/stdc++.h>
using namespace std;
vector<string> fun(int n)
{
	vector<string> str;
	string str1="Fizz";
	string str2="Buzz";
	string str3="FizzBuzz";
	for(int i=1;i<=n;i++)
	{
		if(i%3==0 && i%5==0)
		{
			str.push_back(str3);
		}
		else if(i%3==0)
		{
			str.push_back(str1);
		}
		else if(i%5==0)
		{
			str.push_back(str2);
		}
		else
		{
			str.push_back(to_string(i));
		}
	}
	return str;
}

int main()
{
	vector<string> str;
	int n;
	cin>>n;
	str=fun(n);
	for(int i=0;i<str.size();i++)
	{
		cout<<str[i]<<" ";
	}
	return 0;
}
