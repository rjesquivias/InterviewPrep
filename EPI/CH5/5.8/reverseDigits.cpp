#include <iostream>
using namespace std;

int reverseDigits(int x)
{
	bool isNegative = false;
	if(x < 0)
	{
		isNegative = true;
		x = -x;
	}

	int sol = 0;
	while(x)
	{
		sol *= 10;
		sol += x % 10;
		x /= 10;
	}

	return isNegative ? -sol : sol;
}

int main()
{
	cout << reverseDigits(8452) << endl;

	return 0;
}