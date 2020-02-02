#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int *arr = new int[N];
	int *temp = new int[N];
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	int pos = 0;
	int temp1 = 0;
	for(int i=0;i<N;i++)
	{

		int a = (arr[i]-i)/N; 

		if((arr[i]-i)%N>0)
		{
		//	cout<<a;
			temp1 = a+1;
			temp[i] = i + (temp1*N);
		}
		else
		{
		//	cout<<"here";
			temp1 = a;
			temp[i] = i + (temp1*N);
		}
		
	}
	
	for(int i=0;i<N;i++)
	{
		cout<<temp[i]<<" ";
	}
	
/*	int small = INT_MAX;
	int store =0;
	for(int i = 0;i<N;i++)
	{
		if(temp[i]<small)
		{
			small = temp[i];
			store = i;
		}
	}
	cout<<store+1;*/
}
