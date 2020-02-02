#include <iostream>
using namespace std;

int clearAllBits(int n, int i)
{
	int temp = ((1<<i)-1);
//	cout<<temp;
	return temp&n;	
    
}



int main() {
	int n, i;

	cin >> n >> i;
	
	cout<< clearAllBits(n, i) <<endl;
		
	return 0;
}


