#include<bits/stdc++.h>
using namespace std;
struct worker
{
	int t,x,y;
	worker()
	{
	}
	worker(int t,int x,int y)
	{
		this->t = t;
		this->x = x;
		this->y = y;
	}
};

bool comparesort(worker a,worker b)
{
	if(a.t == b.t)
	{
		if(a.y==b.y)
		{
			return a.x < b.x; //ascendind order
		}
		return a.y > b.y; // descending order
	}
	return a.t < b.t; //ascending order
}
int main()
{
	long long n,d;
	cin>>n>>d;
	vector<worker> arr;
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		arr.push_back(worker(a,b,c));
	}
	
	sort(arr.begin(),arr.end(),comparesort);
	
	cout<<endl;
	
	int currCost=0;
	int totalCost=0;
	double fraction=0;
	int area=0;
	double oldFraction = (double)arr[1].y/arr[1].x;
	for(int i=0;i<arr.size();i++)
	{
		fraction = (double)arr[i].y/arr[i].x;
		if(oldFraction<fraction)
		{
		
			if(d<=(area+arr[i].y))
			{
				totalCost += arr[i].x;
				area += arr[i].y;
			}	
			else
			{
				int rArea = d-area;
				totalCost += arr[i].x * ((double)rArea/arr[i].y);
				break;
			}
		}
	}
	cout<<totalCost;
	/*
	for(int i=0;i<n;i++)
	{
		cout<<arr[i].t<<" "<<arr[i].x<<" "<<arr[i].y;
		cout<<endl;
	}*/
	return 0;
}
