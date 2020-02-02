#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void FindTriplet(int arr[], int size, int x) 
{
    sort(arr,arr+size);
    for(int i=0;i<size;i++)
    {
    	int start = i+1;
    	int end = size-1;
    	int val = x - arr[i];
    	while(start<end)
    	{
    		if(arr[start]+arr[end] > val)
			end--;
			else if(arr[start]+arr[end] < val)
			start++;
			else
			{
				int count1=0;
				int count2=0;
				for(int j = start;j<=end;j++)
				{
					if(arr[start]==arr[j])
					count1++;
					else
					break;
				}
				for(int j = end;j>=start;j--)
				{
					if(arr[end]==arr[j])
					count2++;
					else
					break;
				}
				int combinations = count1*count2;
				if(arr[start]==arr[end])
				{
					combinations = ((end-start+1)*(end-start))/2;
				}
				for(int k=0;k<combinations;k++)
				{
					cout<<arr[i]<<" "<<arr[start]<<" "<<arr[end]<<endl;
				}
				start = start+ count1;
				end = end - count2;
			}
		}
	}
    

}



int main() {

	int size;

	int x;
	cin>>size;
	
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;

	FindTriplet(input,size,x);
		
	return 0;
}


