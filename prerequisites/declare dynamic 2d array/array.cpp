/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int **arr = new int*[n];  //n rows
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[n];   //columns can be m
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//delete all the elements 
	for(int i=0;i<n;i++)
	{
		delete arr[i];
	}
	delete[] arr;
	return 0;
}*/




