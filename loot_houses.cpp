#include <iostream>
using namespace std;

int *dp = new int[10000]();

int getMaxMoney(int arr[], int n){

	if(n<1)
	{
		return 0;
	}
	if(dp[n]>0)
	{
		return dp[n];
	}
	int ifChoose = arr[n-1] + getMaxMoney(arr,n-2);
	int NotChoose = getMaxMoney(arr,n-1);
	dp[n] = max(ifChoose,NotChoose);
	return max(ifChoose,NotChoose);

}


int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}


