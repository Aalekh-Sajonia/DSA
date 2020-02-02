#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string str1,str2;
	cin>>n;
	cin>>str1;
	cin>>str2;
	int *arr = new int[n];
	int *arr1 = new int[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = str1[i]-'0';
		arr1[i] = str2[i] - '0';
	}
	
	int cost = 0;
	int i=0;
	while(i<n)
	{
		if(arr[i]!=arr1[i])
		{
			if((arr[i]!=arr[i+1])&&(arr[i+1]!=arr1[i+1]))
			{
				swap(arr[i],arr[i+1]);
				cost++;
				i+=2;
				continue;			
			}
			else
			{
				arr[i]=arr1[i];
				cost++;
				i++;
				continue;
			}
		}
		i++;
	}
	cout<<cost;
	return 0;
}
