#include<iostream>
using namespace std;

long long *arr = new long long[1000]();

long staircase(long n){
		
	if(n==0)
	{
		return 1;
	}
	if(n<0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	}
	if(n==2)
	{
		return 2;
	}
    if(arr[n]>0)
    return arr[n];
    int output = staircase(n-1) + staircase(n-2) + staircase(n-3);
    arr[n] = output;
    return output;
    
}


int main(){

  long n; 
  cin >> n ;
  cout << staircase(n) << endl;

}
