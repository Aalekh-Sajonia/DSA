#include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
		
	if(input[0]=='\0')
	{
		return ;
	}
	
	if(input[0]!=input[1])
	{
		removeConsecutiveDuplicates(input+1);
	}
	else if(input[0]==input[1])
	{
		int i;
		for(i=0;input[i]!='\0';i++)
		{
			input[i] = input[i+1];
		}
		input[i-1] = '\0';
		removeConsecutiveDuplicates(input); 
	}

}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
