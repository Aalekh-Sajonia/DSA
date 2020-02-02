#include <iostream>
using namespace std;

#include<bits/stdc++.h>

int minAbsoluteDiff(int arr[], int n) 
{
    sort(arr,arr+n);
    int min = INT_MAX;
    for(int i=0;i<n-1;i++)
    {
    	int temp = arr[i+1]-arr[i];
    	if(temp<min)
    	{
    		min = temp;
		}
	}
	return min;

}


int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	cout<< minAbsoluteDiff(input,size) << endl;
	
	return 0;

}

