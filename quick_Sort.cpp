#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
// taking last as pivot
/*int partition(int arr[],int low,int high)
{
	int pivot = arr[high];
	int i = low-1;
	for(int j = low;j<=high-1;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return i+1;
}*/
//taking first as pivot
int partition(int arr[],int low,int high)
{
	int pivot = arr[low];
	int i = low;
	for(int j = low+1;j<=high;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr[j],arr[i]);
		}
	}
	swap(arr[i],arr[low]);
	return i;
	
}


void qsort(int arr[],int start,int end)
{
	if(start>=end)
	{
		return ;
	}
	
	int c = partition(arr,start,end);
	
	qsort(arr,start,c-1);
	qsort(arr,c+1,end);
}

void quickSort(int input[], int size) 
{
	int start = 0;
	int end = size-1;
	qsort(input,start,end);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}



