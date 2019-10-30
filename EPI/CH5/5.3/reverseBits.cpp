#include <iostream>
#include <stack>
using namespace std;

void printBits(int x)
{
	stack<char> s;
	for(int i = 0; i < sizeof(x) * 8; i++)
	{
		if( (x >> i) & 1 )
			s.push('1');
		else
			s.push('0');
	}

	while(!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	cout << endl;
}

int reverseBits(int x)
{
	int left = sizeof(x) * 8 - 1;
	int right = 0;

	while(left > right)
	{
		if( ((x >> left) & 1) != ((x >> right) & 1) )
		{
			x ^= (1 << left) | (1 << right);
		}

		left--;
		right++;
	}
	
	return x;
}

int main()
{	
	int x = 18273;
	printBits(x);
	printBits(reverseBits(x));

	return 0;
}