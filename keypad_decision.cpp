#include<bits/stdc++.h>
using namespace std;

string keypad(int n)
{
	if(n==2)
	{
		return "abc";
	}
	if(n==3)
	{
		return "def";
	}
	if(n==4)
	{
		return "ghi";
	}
	if(n==5)
	{
		return "jkl";
	}
	if(n==6)
	{
		return "mno";
	}
	if(n==7)
	{
		return "pqrs";
	}
	if(n==8)
	{
		return "tuv";
	}
	if(n==9)
	{
		return "wxyz";
	}
	return " ";
}

void recur(int n,string output)
{
	if(n==0)
	{
		cout<<output<<endl;
		return ;
	}
	
	int temp = n%10;
	n = n/10;
	string outputstr = keypad(temp);
	for(int i=0;i<outputstr.size();i++)
	{
		recur(n,outputstr[i]+ output );
	}
	
}

int main()
{
	int n;
	cin>>n;
	string output;
	recur(n,output);
	return 0;
	
}
