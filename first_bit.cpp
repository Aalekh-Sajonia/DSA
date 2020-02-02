#include <iostream>
using namespace std;

int turnOffFirstSetBit(int n){
	
	int temp = 1;
	while(temp<=n)
	{
		if(temp&n)
		{
			n = temp^ n;
			return n;
		}
		temp = temp<<1;
	}
	
	return 0;    
}



int main() {
	int n;

	cin >> n;
	
	cout<< turnOffFirstSetBit(n) <<endl;
		
	return 0;
}


