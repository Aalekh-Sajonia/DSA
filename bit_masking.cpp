#include<bits/stdc++.h>
using namespace std;
int main()
{
	// 1 2 3 4
	int a[4];
	for(int i=0;i<4;i++)
	{
		cin>>a[i];
	}
	int sum = 4;
	int count=0;
	for(int i=0;i<((1<<4)-1);i++)
	{
	//	cout<<i<<" ";
		int temp=0;
		for(int j=0;j<4;j++)
		{
			if((i & (1<<j) )!= 0)
			{
				cout<<a[j]<<" ";
				temp += a[j];
			}
		}
		cout<<endl;
		if(sum==temp)
		{
			count++;
		}
	}
	
	cout<<count<<endl;
	
	return 0;
}
