#include <iostream>
using namespace std;

void merge(int arr[],int start,int end)
{
	int mid = (start+end)/2;
	int *temp = new int[end-start+1];
	int i = start;
	int j = mid+1;
	int k = 0;
	while(i<=mid && j<=end)
	{
		if(arr[i]<arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}
	while(i<=mid)
	{
		temp[k++] = arr[i++];
	}
	while(j<=end)
	{
		temp[k++] = arr[j++];
	}
	
	k = 0;
	for(int i=start;i<=end;i++)
	{
		arr[i] = temp[k++]; 
	}
}


void msort(int arr[],int start,int end)
{
	if(start>=end)
	{
		return ;
	}
	
	int mid = (start+end)/2;
	msort(arr,start,mid);
	msort(arr,mid+1,end);
	merge(arr,start,end);
}

void mergeSort(int input[], int size){
	
	int start = 0;
	int end = size-1;
    msort(input,start,end);
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}

