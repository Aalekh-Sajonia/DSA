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
	int swaps=0;
	int flag = 1;
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i]==i+1)
		{
		/*	if(i==0)
			{
				break;
			}*/
			continue;
		}
		else if(arr[i-1]==i+1)
		{
			swaps++;
			swap(arr[i],arr[i-1]);
		}
		else if(arr[i-2]==i+1)
		{
		//	cout<<"enter"<<endl;
			swaps += 2;
			swap(arr[i-2],arr[i-1]);
			swap(arr[i],arr[i-1]);
		}
		else
		{
		
			flag = 0;
			break;
		}
	}
/*	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}*/
	if(flag==1)
	{
		cout<<"YES"<<endl;
		cout<<swaps;
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}
