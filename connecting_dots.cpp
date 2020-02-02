#include<bits/stdc++.h>
using namespace std;
#define MAXN 51

bool findCycle(char board[][MAXN], bool visited[][MAXN], int n, int m, char color, int idx_i, int idx_j, int length, int prev_i, int prev_j){
    
    cout<<idx_i<<" "<<idx_j<<endl;
    if(length > 250)
        return false;
    
    // Check if conditions are satisfied.
    if(length >= 4){
        // Check for all four directions.
        // Up
        if((prev_i != idx_i-1 || prev_j != idx_j) && visited[idx_i-1][idx_j] && color == board[idx_i-1][idx_j])
            return true;
        
        // down
        if((prev_i != idx_i+1 || prev_j != idx_j) && visited[idx_i+1][idx_j] && color == board[idx_i+1][idx_j])
            return true;
        
        // left
        if((prev_i != idx_i || prev_j != idx_j-1) && visited[idx_i][idx_j-1] && color == board[idx_i][idx_j-1])
            return true;
        
        // right
        if((prev_i != idx_i || prev_j != idx_j+1) && visited[idx_i][idx_j+1] && color == board[idx_i][idx_j+1])
            return true;
    }
    
    // If base is false explore all four directions.
    // up
    if(idx_i-1 >= 0 && (prev_i != idx_i-1 || prev_j != idx_j) && !visited[idx_i-1][idx_j] && color == board[idx_i-1][idx_j]){
        bool status = findCycle(board, visited, n, m, color, idx_i-1, idx_j, length+1, idx_i, idx_j);
        if(status)
            return true;
    }

    // down
    if(idx_i+1 < n && (prev_i != idx_i+1 || prev_j != idx_j) && !visited[idx_i+1][idx_j] && color == board[idx_i+1][idx_j]){
        bool status = findCycle(board, visited, n, m, color, idx_i+1, idx_j, length+1, idx_i, idx_j);
        if(status)
            return true;
    }

    // left
    if(idx_j-1 >= 0 && (prev_i != idx_i || prev_j != idx_j-1) && !visited[idx_i][idx_j-1] && color == board[idx_i][idx_j-1]){
        bool status = findCycle(board, visited, n, m, color, idx_i, idx_j-1, length+1, idx_i, idx_j);
        if(status)
            return true;
    }

    // right
    if(idx_j+1 < m && (prev_i != idx_i || prev_j != idx_j+1) && !visited[idx_i][idx_j+1] && color == board[idx_i][idx_j+1]){
        bool status = findCycle(board, visited, n, m, color, idx_i, idx_j+1, length+1, idx_i, idx_j);
        if(status)
            return true;
    }
    
    return false;
}

int solve(char board[][MAXN],int n, int m)
{
    
    bool visited[n][MAXN];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            visited[i][j] = false;
    
    
	for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            
            if(visited[i][j])
                continue;
            
            visited[i][j] = true;
            char color = board[i][j];
            int length = 1;
            
            bool status = findCycle(board, visited, n, m, color, i, j, -1, -1, length);
            cout<<endl;
            if (status)
            {	
                return 1;
            }
        }
    }
    
    return 0;
}


int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}

