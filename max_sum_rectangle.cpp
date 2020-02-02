#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size) 
{ 
   int max_so_far = 0, max_ending_here = 0; 
   for (int i = 0; i < size; i++) 
   { 
       max_ending_here = max_ending_here + a[i]; 
       if (max_ending_here < 0) 
           max_ending_here = 0; 
       else if (max_so_far < max_ending_here) 
           max_so_far = max_ending_here; 
   } 
   return max_so_far; 
} 


int cal(int **arr,int left,int right,int row)
{
	int *store = new int[row]();
	for(int i=0;i<row;i++)
	{
		for(int j=left;j<=right;j++)
		{
			store[i] += arr[i][j];
		}
	}
	int ans = maxSubArraySum(store,row);
	return ans;
}

int main()
{
	int r,c;
	cin>>r>>c;
	int **arr = new int*[r];
	for(int i=0;i<r;i++)
	{
		arr[i] = new int[c];
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>arr[i][j];
		}
	}
	

	int max = INT_MIN;	
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<c;j++)
		{
			int curr_max = cal(arr,i,j,r);
			if(curr_max>max)
			{
				max = curr_max;
			}
		}
	}
	if(max!=0)
	cout<<max;
	else
	cout<<"-1";
	return 0;
}
