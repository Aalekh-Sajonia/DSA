#include<bits/stdc++.h>
#define long long ll
using namespace std;
struct worker
{
	ll time,cost,speed;
};

bool compare(worker a,worker b)
{
	if(a.time==b.time)
	{
		if(a.speed==b.speed)
		{
			return a.cost<b.cost;
		}
		return a.speed>b.speed;
	}
	return a.time<b.time;
}

int main()
{
	ll n,d;
	cin>>n>>d;
	worker *arr = new worker[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].time>>arr[i].cost>>arr[i].speed;
	}
	sort(arr,arr+n,compare);
	
	ll bestspeed = 0;
	ll cost =0;
	ll lastTime = arr[0].time;
	ll area=0;
	for(int i=0;i<n;i++)
	{
		ll addition = bestspeed * (arr[i].time-lastTime);
		area += addition;
		
		if(area>=d)
		{
			break;
		}
		
		if(arr[i].speed>bestspeed)
		{
			bestspeed = arr[i].speed;
			cost += arr[i].cost;
		}
		lastTime = arr[i].time;
	}
	
	cout<<cost<<endl;
	return 0;
}
