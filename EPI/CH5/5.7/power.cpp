#include <iostream>
#include <math.h>
#include <assert.h>
using namespace std;

// Time: O(y)
double brute_power(double x, int y)
{
	if(y == 0) return 1;
	double solution = x;

	for(int i = 1; i < y; i++)
	{
		solution *= x;
	}

	return solution;
}

// Time: O(log(y))
double recursive_power(double x, int y)
{
	if(y == 0) return 1;
	if(y < 0) // Make it work with negative exponent
	{
		y = -y;
		x = 1.0 / x;
	}
	double s = recursive_power(x, y/2);

	if(y % 2 == 0)
	{
		return s * s;
	}
	else
	{
		return x * s * s;
	}
}

// Book solution: Time: O(n) where n is the sizeof(int)
// with 32bit int, this will take 32 steps
double book_power(double x, int y)
{
	double result = 1.0;
	long long power = y;
	if(y < 0)
	{
		power = -power;
		x = 1.0 / x;
	}

	while(power)
	{
		if(power & 1) // When we hit a 1, we can then use what we calculated
		{
			result *= x;
		}
		x *= x; // Calculating the exponent at every bit
		power >>= 1;
	}

	return result;
}

int main()
{
	assert(brute_power(2, 10) == pow(2, 10));
	assert(brute_power(14, 5) == pow(14, 5));
	assert(brute_power(21, 7) == pow(21, 7));
	assert(brute_power(5, 10) == pow(5, 10));

	assert(recursive_power(2, 10) == pow(2, 10));
	assert(recursive_power(14, 5) == pow(14, 5));
	assert(recursive_power(21, 7) == pow(21, 7));
	assert(recursive_power(5, 10) == pow(5, 10));

	assert(book_power(2, 10) == pow(2, 10));
	assert(book_power(14, 5) == pow(14, 5));
	assert(book_power(21, 7) == pow(21, 7));
	assert(book_power(5, 10) == pow(5, 10));

	return 0;
}