#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num,digits;
	cin>>num>>digits;
	vector<int> arr;
	for(int i=0;i<digits;i++)
	{
		arr.push_back(0);
	}
	int final = num-1;
	int j = digits-1;
	while(j>0||final>0)
	{
		if(final>=9)
		{
			arr[j]=9;
			final = final-9;
			j--;
			if(j<1)
			break;
		}
		if(final<9)
		{
			arr[j] = final;
			final = 0;
			j--;
		}
	}
	if(final!=0)
	{
		arr[0] = 1+final;
	}
	else
	{
		arr[0]=1;
	}
	//cout<<final<<endl;
	for(int i=0;i<digits;i++)
	{
		cout<<arr[i];
	}
	return 0;
}
