#include<bits/stdc++.h>
using namespace std;
vector<int> vect;
int *getLps(string str)
{
	int len = str.length();
	int *lps = new int[len];
	
	int i=1;
	int j=0;
	lps[0] = 0;
	
	while(i<len)
	{
		if(str[i]==str[j])
		{
			lps[i] = j+1;
			j++;
			i++;
		}
		else
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}

string convertToString(char* a, int size) 
{ 
    int i; 
    string s = ""; 
    for (i = 0; i < size; i++) { 
        s = s + a[i]; 
    } 
    return s; 
} 
  

void findString(char S[], char T[]) 
{
    
    int a = strlen(S);
    int b = strlen(T);
    string str = convertToString(S,a);
    string pattern = convertToString(T,b);
    

   // cout<<str<<" "<<pattern<<endl;
    int lenStr = a;
	int lenPat = b;
	
	int i=0;
	int j=0;
	
	int *lps = getLps(pattern);
	for(int i=0;i<lenPat;i++)
	{
		cout<<lps[i]<<endl;
	}
	while(i<=lenStr)
	{
		if(j==lenPat)
		{
			vect.push_back(i-lenPat);
			j = lps[j-1];
		}
		if(str[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
}


int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    findString(S, T);
    for(auto x:vect)
    {
    	cout<<x<<" ";
	}
}

