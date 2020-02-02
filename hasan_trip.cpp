#include <bits/stdc++.h>
using namespace std;

struct trip
{
	double xi,yi,fi;
};

int main()
{
	int n;
	cin>>n;
	trip *arr = new trip[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].xi;
		cin>>arr[i].yi;
		cin>>arr[i].fi;
	}
	
	double *dp = new double[n+1];
	dp[0] = arr[0].fi;
	for(int i=1;i<n;i++)
	{
		double max_happy = INT_MIN;
		for(int j=0;j<i;j++)
		{
			double x = arr[j].xi - arr[i].xi;
			double y = arr[j].yi - arr[i].yi;
			
			x = x*x;
			y = y*y;
			double distance = sqrt(x+y);
			double happy = dp[j] + arr[i].fi;
			happy = happy - distance;
			if(happy>max_happy)
			{
				max_happy = happy;
				dp[i] = max_happy;
			}
		}
	}
	
	cout<< fixed << setprecision(6)<<dp[n-1]<<endl;
    return 0;
}

