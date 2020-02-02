#include<iostream>
#include<array>
using namespace std;
int main()
{
	array<int,5> arr;
	for(int i=0;i<5;i++)
	{
		cin>>arr.at(i);
	}
	array<int,5> arr1;
	arr1.fill(0);
	arr.swap(arr1);
	for(int i=0;i<5;i++)
	{
		cout<<arr1.at(i)<<" ";
	}
	return 0;
}
