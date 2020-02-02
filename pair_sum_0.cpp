#include<iostream>
using namespace std;
#include<bits/stdc++.h>
	
void PairSum(int *input, int n) 
{	 
	map<int,int> m;
	for(int i=0;i<n;i++)
	{
		m[input[i]]++; 
	}
	
	map<int,int>::iterator itr;
	int temp;
	for(itr=m.begin();itr!=m.end();itr++)
	{
		if(itr->second>0)
		{
			temp = itr->second * m[-1*(itr->first)];
			for(int i=0;i<temp;i++)
			{
				if(itr->second>0)
				{
					cout<<itr->first<<" "<<-1*itr->first;
				}
				else
				{
					cout<<-1*itr->first<<" "<<itr->first;
				}
				cout<<endl;
			}
			itr->second = 0;
			m[-1*(itr->first)] = 0;
		}
	}
	
     	
}



int main()
{
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    PairSum(arr, n);
    return 0;
}

