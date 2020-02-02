#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int temp=0;
	vector<int> arrival;
	vector<int> depart;
	for(int i=0;i<N;i++)
	{
		cin>>temp;
		arrival.push_back(temp);
	}
	temp=0;
	for(int i=0;i<N;i++)
	{
		cin>>temp;
		depart.push_back(temp);
	}
	
	sort(arrival.begin(),arrival.end());
	sort(depart.begin(),depart.end());
		
	int current_customer=0;
	int max_customer=0;
	int k=0;
	int j=0;
	for(int i=0;i<N*2;i++)
	{
		//cout<<"inside";
		if((j<=N-1)&&(k<=N-1))
		{
		if((arrival.at(j)<depart.at(k)))
		{
			//cout<<"inside";
			current_customer++;
			j++;
		}
		else 
		{
			current_customer--;
			k++;
		}
		}
		if(current_customer>max_customer)
		{
			max_customer=current_customer;
		}
	}
	cout<<max_customer<<endl;	
/*	cout<<endl;	
	for(int i=0;i<N;i++)
	{
		cout<<arrival.at(i)<<" "<<depart.at(i)<<endl;
	}*/
	return 0;
}
