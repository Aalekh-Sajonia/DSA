#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int board[11][11];

bool canplace(int n,int row,int col)
{
	for(int i=row-1;i>=0;i--)
	{
		if(board[i][col]==1)
		return false;
	}
	for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
	{
		if(board[i][j]==1)
		return false;
	}
	for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
	{
		if(board[i][j]==1)
		return false;
	}
	return true;
}


void queenhelp(int n,int row)
{
	
	if(row==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<board[i][j]<<" ";
			}
		}
		cout<<endl;
		return ;
	}
	
	for(int i=0;i<n;i++)
	{
		if(canplace(n,row,i))
		{
			board[row][i]=1;
			queenhelp(n,row+1);
			board[row][i]=0;
		}
	}
	return ;
}



void placeNQueens(int n){
	
	memset(board,0,11*11*sizeof(int));
	
	queenhelp(n,0);
	return ;
}


int main(){

  int n; 
  cin >> n ;
  placeNQueens(n);

}



