#include<bits/stdc++.h>
using namespace std;
/*bool comparator(pair<int,int> a,pair<int,int> b)
{
	return (a.second>b.second);
}*/
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int a,b;
		cin>>a>>b;
		vector<pair<int,int>> arr;
		int *arr1 = new int[b];
		int i1,i2;
		for(int i=0;i<a;i++)
		{
			cin>>i1>>i2;
			arr.push_back(make_pair(i1,i2));
		}

		sort(arr.begin(),arr.end());
		while(b--)
		{
			int input;
			cin>>input;
			int position = lower_bound(arr.begin(),arr.end(),make_pair(input,0)) 
							- arr.begin();
			if(position==0)
			{
				int ans = arr[0].first-input;
				cout<<ans<<endl;
			}
			else
			{
				int ans = -1;
				if(arr[position-1].second > input)
				ans=0;
				else if(position<arr.size())
				{
					ans = arr[position].first - input;
				}
				cout<<ans<<endl;
			}
		
		}
	}
	return 0;
}
