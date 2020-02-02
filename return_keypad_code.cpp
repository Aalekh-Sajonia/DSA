#include<bits/stdc++.h>
using namespace std;

string fun(int n)
{
	if(n == 2)
	return "abc";
	if(n == 3)
	return "def";
	if(n == 4)
	return "ghi";
	if(n == 5)
	return "jkl";
	if(n == 6)
	return "mno";
	if(n == 7)
	return "pqrs";
	if(n == 8)
	return "tuv";
	if(n == 9)
	return "wxyz";
	
	return " ";
}

int keypad(int n,string output[])
{
	if(n==0)
	{
		output[0] = "";
		return 1;
	}
	
	int num = n%10;
	n = n/10;
	string str = fun(num);
	int count = keypad(n,output);
	
	for(int i=0;i<str.size()-1;i++)
	{
		for(int j=0;j<count;j++)
		{
			output[j+(i+1)*count] = output[j];
		}
	}
	
	int k=0;
	for(int i=0;i<str.size();i++)
	{
		for(int j=0;j<count;j++)
		{
			output[k] = output[k] + str[i];
			k++;
		}
	}
	return count*str.size();
}


int main()
{
	int n;
	cin>>n;
	string output[1000];
	int count = keypad( n, output);
	for(int i=0;i<n;i++)
	{
		cout<<output[i]<<endl;
	}
	return 0;
}
