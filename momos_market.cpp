#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int money;
		cin>>money;
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]!=0)
			{
				if(money>arr[i])
				{
					money -= arr[i];
					count++;
				}
			}
		}
		cout<<count<<" "<<money<<endl;
	}
}
