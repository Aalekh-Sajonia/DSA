#include <iostream>

int turnOnIthBit(int n, int i)
{
	int temp = 1<<i;
	int ans;
	if(n&(1<<i))
	{
		ans = n^temp;
	}
	else
	{
		return n;
	}
}



using namespace std;

int main() {
	int n, i;

	cin >> n >> i;
	
	cout<< turnOnIthBit(n, i) <<endl;
		
	return 0;
}


