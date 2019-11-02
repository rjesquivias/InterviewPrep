#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
	if(x < 0) return false;

	// How do you take out the front integer?
	int frontDivisor = 1;
	int left = 0, right = 0;
	while(x / frontDivisor)
	{
		frontDivisor *= 10;
		left++;
	}
	frontDivisor /= 10;

	while(left > right)
	{
		int frontDigit = x / frontDivisor;
		int backDigit = x % 10;

		if(frontDigit != backDigit) return false;

		x /= frontDivisor;
		x /= 10;
		frontDivisor /= 100;

		left--;
		right++;
	}

	return true;
}

int main()
{
	cout << isPalindrome(1) << endl;

	return 0;
}