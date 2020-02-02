#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void prinsol(int **output,int n)
{
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<output[i][j]<<" ";
			}
		}
		cout<< endl;
		return ;
}
void rathelp(int maze[][20],int n,int row,int col,int **output)
{
	if(row==n-1 && col==n-1)
	{
		output[row][col] = 1;
		prinsol(output,n);
		output[row][col] = 0;
		return ;
	}
	if(row>=n || row<0 || col>=n || col<0 || maze[row][col] == 0 || output[row][col]==1)
	{
		return;
	}
	output[row][col] = 1;
	rathelp(maze,n,row-1,col,output);
	rathelp(maze,n,row+1,col,output);
	rathelp(maze,n,row,col-1,output);
	rathelp(maze,n,row,col+1,output);
	output[row][col] = 0;
	return ;
}


void ratInAMaze(int maze[][20], int n)
{
	int **output = new int*[n];
	for(int i=0;i<n;i++)
	{
		output[i] = new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			output[i][j] = 0;
		}
	}
	rathelp(maze,n,0,0,output);
	return;
}


int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}



