#include<iostream>
using namespace std;
string uniqueChar(char str[]){
	int arr[127];
	string final;
	for(int i=0;i<127;i++)
	{
		arr[i]=0;
	}
	int i=0;
	while(str[i]!='\0')
	{
		arr[str[i]]++;
		i++;
	}
	
	/*for(int i=0;i<26;i++)
	{
		cout<<arr[i]<<" ";
	}*/
	i=0;
	int k=0;
	while(str[i]!='\0')
	{
		if(arr[str[i]]>0)
		{
			final += str[i];
		}
		arr[str[i]]=0;
		i++;
	}
	//cout<<final;
	return final;
}

int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}

