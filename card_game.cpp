#include <bits/stdc++.h>
#define maxn 100007
using namespace std;
typedef long long ll;
 
inline int read(){ 
	int num;    
	scanf("%d",&num);   
	return num;
}
int p,n;
int a[maxn];
ll ans;
int prime[50];
int pcnt[50];
int b[maxn][50];
int c[50];
int main()
{
    int n = read();
    int k = read();
    int cnt = 0;
    for(int i = 2; i<=sqrt(k); i++){
        if(k%i==0){
            prime[++cnt] = i;
            while(k%i==0){
                k /= i;
                pcnt[cnt]++;
            }
        }
    }
    if(k>1){
        prime[++cnt] = k;
        pcnt[cnt] = 1;
    }
    for(int i = 1; i<=n; i++){
        a[i] = read();
        for(int j = 1; j<=cnt; j++){
            while(a[i]%prime[j]==0){
                b[i][j]++;
                a[i] /= prime[j];
            }
        }
    }
    int i = 1,j = 0;
    while(i<=n){
        int flag = false;
        while(j<=n && !flag){
            j++;
            flag = true;
            for(int w = 1; w<=cnt; w++){
                c[w] += b[j][w];
                flag &= (c[w]>=pcnt[w]);
            }
        }
        if(!flag)   break;
        while(flag && i<=j){
            ans += n-j+1;
            for(int w = 1; w<=cnt; w++){
                c[w] -= b[i][w];
                flag &= (c[w]>=pcnt[w]);
            }
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}

