#include<iostream>
using namespace std;

int arr[1000][1000];

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	
	if(value==0)
	{
		return 1;
	}
	if(value<0)
	{
		return 0;
	}
	if(numDenominations==0)
	{
		return 0;
	}
	if(arr[numDenominations][value]>0)
	{
		return arr[numDenominations][value];
	}
	int select = countWaysToMakeChange(denominations,numDenominations,value-denominations[0]);
	int notselect = countWaysToMakeChange(denominations+1,numDenominations-1,value);
	arr[numDenominations][value] = select+notselect;
	return select+notselect;

}



int main(){
	
/*	for(int i=0;i<1001;i++)
	{
		for(int j=0;j<1001;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}*/
 int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}



