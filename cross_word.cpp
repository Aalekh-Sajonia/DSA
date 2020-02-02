#include<bits/stdc++.h>
using namespace std;
char arr[10][10];
bool isValidVertical(int row,int col,string str)
{
	int size = str.size();
	int k=1;
	for(int i=row+1,j=col;i<(row+(size));i++)
	{
		if(arr[i][j]=='+')
		return false;
		else if(arr[i][j]!='-')
		{
			if(arr[i][j]!=str[k])
			return false;
		}
		k++;
	}
	return true;
}
void setVertical(int row,int col,bool helper[],string str)
{
	int size = str.size();
	int k=0;
	for(int i=row,j=col;i<(row+(size));i++)
	{
		if(arr[i][j]=='-')
		{
			arr[i][j] = str[k];
			helper[k] = true;
			k++;
		}
		else
		{
			helper[k] = false;
			k++;
		}
	}
	return ;
}

void resetVertical(int row,int col,bool helper[],string str)
{
	int size= str.size();
	int k=0;
	for(int i=row,j=col;i<(row+(size));i++)
	{
		if(helper[k]==true)
		{
			arr[i][j]='-';
		}
		k++;
	}
	return ;
}

bool isValidHorizontal(int row,int col,string str)
{
	int size = str.size();
	int k=1;
	for(int i=row,j=col+1;j<(col+(size));j++)
	{
		if(arr[i][j]=='+')
		return false;
		else if(arr[i][j]!='-')
		{
			if(arr[i][j]!=str[k])
			return false;
		}
		k++;
	}
	return true;
}

void resetHorizontal(int row,int col,bool helper[],string str)
{
	int size= str.size();
	int k=0;
	for(int i=row,j=col;j<(col+(size));j++)
	{
		if(helper[k]==true)
		{
			arr[i][j]='-';
		}
		k++;
	}
	return ;
}

void setHorizontal(int row,int col,bool helper[],string str)
{
	int size = str.size();
	int k=0;
	for(int i=row,j=col;j<(col+(size));j++)
	{
		if(arr[i][j]=='-')
		{
			arr[i][j] = str[k];
			helper[k] = true;
			k++;
		}
		else
		{
			helper[k] = false;
			k++;
		}
	}
	return ;
}

bool crossword(char arr[10][10],string str[],int index,int end)
{
	if(index==end)
	{
		return true;
	}
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(arr[i][j]=='-' || arr[i][j] == str[index][0])
			{
				if(isValidVertical(i,j,str[index]))
				{
					int n = str[index].size();
					bool helper[n];
					setVertical(i,j,helper,str[index]);
					if(crossword(arr,str,index+1,end))
					{
						return true;
					}
					resetVertical(i,j,helper,str[index]);
				}
				if(isValidHorizontal(i,j,str[index]))
				{
					int n = str[index].size();
					bool helper[n];
					setHorizontal(i,j,helper,str[index]);
					if(crossword(arr,str,index+1,end))
					{
						return true;
					}
					resetHorizontal(i,j,helper,str[index]);
				}
			}
		}
	}
}

int main()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cin>>arr[i][j];
		}
	}
	string str;
	cin>>str;
	int k=0;
	int j=0;
	string str1[20];
	while(str.size()!=k)
	{
		if(str[k]==';')
		{
			j++;
		}
		else
		{
			str1[j] += str[k];
		}
		k++;		
	}
	
	crossword(arr,str1,0,j+1);
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	
/*	cout<<endl;
	for(int i=0;i<=j;i++)
	{
		cout<<str1[i]<<endl;
	}*/
	return 0;
}
