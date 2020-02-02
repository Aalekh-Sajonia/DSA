#include<bits/stdc++.h>
using namespace std;
#define N 9

bool findEmpLoc(int arr[N][N],int &row,int &col)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]==0)
			{
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}

bool possiblerow(int arr[N][N],int row,int ele)
{
	for(int i=0;i<9;i++)
	{
		if(arr[row][i]==ele)
		return false;
	}
	return true;
}

bool possiblecol(int arr[N][N],int col,int ele)
{
	for(int i=0;i<9;i++)
	{
		if(arr[i][col]==ele)
		return false;
	}
	return true;
}

bool possiblegrid(int arr[N][N],int row,int col,int ele)
{
	int rowfactor = row-(row%3);
	int colfactor = col-(col%3);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(arr[i+rowfactor][j+colfactor]==ele)
			return false;
		}
	}
	return true;
}
bool possible(int arr[N][N],int row,int col,int ele)
{
	if(possiblerow(arr,row,ele) && possiblecol(arr,col,ele) && possiblegrid(arr,row,col,ele))
	{
		return true;
	}
	return false; 
}
bool solvesudoku(int arr[N][N])
{
	int row, col;
	if(!findEmpLoc(arr,row,col))
	{
		return true;
	}
	
	for(int i=1;i<=9;i++)
	{
		if(possible(arr,row,col,i))
		{
			arr[row][col] = i;
			if(solvesudoku(arr))
			{
				return true;
			}
			arr[row][col] = 0;
		}
	}
	return false;
}

int main()
{
	int arr[N][N];
	string str;
/*	for(int i=0;i<N;i++)
	{
		cin>>str;
		for(int j=0;j<N;j++)
		{
			arr[i][j] = str[j] - '0';
		}
	}*/
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	if(solvesudoku(arr))
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	/*for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}*/
	return 0;
}
