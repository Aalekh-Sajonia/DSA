#include<bits/stdc++.h>
using namespace std;

bool check(long long mid,long long n)
{
	long long temp=n;
	long long sum = 0;
	while(temp>0)
	{
		sum = sum + min(mid,temp);
		temp = temp-mid;
		temp = temp - (temp/10);
	}
	if(2*sum>=n)
	return true;
	else
	return false;

}

int main()
{
	long long n;
	cin>>n;
	long long start = 0;
	long long end = LLONG_MAX;
	long long mid;
	long long save=LLONG_MAX;
	while(start<=end)
	{
		mid = (start+end)/2;
	//	cout<<mid<<endl;
		if(check(mid,n))
		{
			if(save>mid)
			{
				save=mid;
			}
			end = mid-1;	
		}
		else
		{
			start = mid+1;
		}
	}   
	cout<<save; 
	return 0;
}

