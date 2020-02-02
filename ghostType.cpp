#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int>submask[22];
bool vis[1<<22];
ll dp[1<<22];
int N;
ll rec(int mask)
{
    if(mask==(1<<(N+1))-2) 
		return 1;
    if(vis[mask]) 
		return dp[mask];
    vis[mask] = 1;
    ll &K = dp[mask];
    K=0;
    int x;
    for(int i=1;i<=N;i++){
        if(!(mask&(1<<i))){
            bool flag=true;
            for(int j=0;j<submask[i].size();j++){
                x = submask[i][j];
                if(!(mask&(1 << x ))) 
                flag=false;
            }
            if(flag){
                K += rec(mask|(1<<i));
            }
        }
    }
    return K;
}
int main(){
    for(int i=1;i<=20;i++){
        for(int j=i-1;j>=1;j--){
            if( (i&j)==j ) submask[i].push_back(j);
        }
    }
    cin >> N;
    cout<<rec(0);
}
