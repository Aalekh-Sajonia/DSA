#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,K;
	cin>>N>>K;
	int *arr = new int[N];
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+N);
	int ptr1=0;
	int ptr2=1;
	int count = 0;
	while(ptr2<N)
	{
		if(ptr1==ptr2)
		{
			ptr2++;
		}
		else if(arr[ptr2]-arr[ptr1]>=K)
		{
			count += N-ptr2;
			ptr1++;
		}
		else
		{
			ptr2++;
		}
		
	}
	cout<<count;
	return 0;
}
