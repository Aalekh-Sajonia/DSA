#include<bits/stdc++.h>
using namespace std;

/*
3
Mohit 94 85 97
Shubham 93 91 94
Rishabh 95 81 99
Sample Output:
1 Shubham
2 Mohit
3 Rishabh

dictionary output
*/
int main()
{
	
	int n;
	string str;
	cin>>n;
	int a,b,c;
	int temp;
	map<int,vector<string>> m;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		cin>>a>>b>>c;
		temp=a+b+c;	
		m[temp].push_back(str);	
	}
	
	map<int,vector<string>>::iterator itr,itr1,itr2;
	itr2=m.begin();
	itr2--;
	itr1=m.end();
	itr1--;
	int counter=1;
	for(itr=itr1;itr!=itr2;itr--)
	{
		//cout<<itr->first<<" ";
		if(itr->second.size()>1)
		{
		//	sort(itr->second.begin(),itr->second.end());
			for(int i=0;i<itr->second.size();i++)
			{
				cout<<counter<<" ";
				//cout<<itr->second[i]<<" ";
				cout<<itr->second[i]<<" "<<endl;
				counter++;	
			}
		}
		else
		{
			cout<<counter<<" ";
			//cout<<itr->second[0]<<" ";
			cout<<itr->second[0]<<" "<<endl;
			counter++;
		}
		
	}

	return 0;
}
