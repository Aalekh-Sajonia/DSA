#include <bits/stdc++.h> 
using namespace std; 
int minimizeDiff(int* arr, int n, int k) 
{ 
    int max = *(max_element(arr, arr + n)); 
    int min = *(min_element(arr, arr + n)); 
    if ((max - min) <= k) { 
        return (max - min); 
    }
    int avg = (max + min) / 2; 
    for (int i = 0; i < n; i++) { 

        if (arr[i] > avg) 
            arr[i] -= k; 

        else
            arr[i] += k; 
    } 
    max = *(max_element(arr, arr + n)); 
    min = *(min_element(arr, arr + n)); 
    return (max - min); 
} 
  
// Driver code 
int main() 
{ 
	int n,k;
	cin>>n>>k;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	} 
  
    cout<< minimizeDiff(arr, n, k) << endl; 
  
    return 0; 
} 
