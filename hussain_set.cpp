#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	queue<ll> q;
	int counter=0;
	int N,M;
	cin>>N>>M;
	ll Narr[N];
	for(int i=0;i<N;i++)
	{
		cin>>Narr[i];
	}
	sort(Narr,Narr+N);
	int end = N-1;
	while(M--)
	{
		int curr_m;
		cin>>curr_m;
		ll ans;
		for(;counter<curr_m;counter++)
		{
			if(end>=0 && (q.empty() || (Narr[end]>=q.front())))
			{
				ans=Narr[end];
				end--;
			}
			else
			{
				ans=q.front();
				q.pop();
			}
			q.push(ans/2);	
		}
		cout<<ans<<endl;	
	}
	return 0;
}
