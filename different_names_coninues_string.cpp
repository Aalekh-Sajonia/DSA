#include<bits/stdc++.h>
using namespace std;
vector<string> words(string str)
{
	vector<string> final;
	string word = "";
	for(auto x : str)
	{
		if(x==' ')
		{
			final.push_back(word);
			word="";
		}
		else
		{
			word = word+x;
		}
	}
	return final;
}
int main()
{
	string str;
	getline(cin,str);
	str = str+ ' ';
	vector<string> comp;
	comp=words(str);
	int counter=0;
	unordered_map<string,int> m;
	for(int i=0;i<comp.size();i++)
	{
	//	cout<<comp[i]<<endl;
		m[comp[i]]++;
	}
	unordered_map<string,int>::iterator itr;
	for(int i=0;i<comp.size();i++)
	{
		if(m[comp[i]]>1)
		{
			cout<<comp[i]<<" "<<m[comp[i]]<<endl;
		}
		m.erase(comp[i]);
	}
	return 0;
}
