#include <iostream>
#include <assert.h>
#include <math.h>
using namespace std;

// Time: O(n) where n is the word size
short brute_force_parity(unsigned long x)
{
	short result = 0;
	while(x)
	{
		result += (x & 1);
		x >>= 1;
	}

	return result % 2;
}

// Time: O(k) where k is the number of 1's
short refined_brute_force_parity(unsigned long x)
{
	short result = 0;
	while(x)
	{
		result ^= 1; // toggle result between 0 & 1
		x &= (x-1); // Set the last set bit to 0
	}

	return result;
}

// This is good under the assumption we computer the lookup table once.
// If we are doing many parity checks, after this one time cost
// we get O(3) for each parity check
// General lookup table if we dont use xor trick: O(n/L) 
// n = 64, L = 16
// n = sizeof(long)
// L = size of lookup word, in this case 16
short lookup_table_parity(unsigned long x)
{
	// 2^16 = 65536, this is a reasonable amount of space
	short precomputed_parity[(int)pow(2, 16)];
	for(int i = 0; i < pow(2, 16); i++)
	{
		precomputed_parity[i] = refined_brute_force_parity(i);
	}

	x ^= x >> 32;
	return precomputed_parity[(x >> 16) & 0xFFFF] ^ 
	       precomputed_parity[x & 0xFFFF];
}

// Time: O(log(n))
short xor_parity(unsigned long x)
{
    x ^= x >> 32;
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    return x & 0x1;
}

int main()
{
	assert(brute_force_parity(1) == 1);
	assert(brute_force_parity(2) == 1);
	assert(brute_force_parity(3) == 0);
	assert(brute_force_parity(4) == 1);
	assert(brute_force_parity(5) == 0);
	assert(brute_force_parity(6) == 0);
	assert(brute_force_parity(7) == 1);
	assert(brute_force_parity(8) == 1);
	assert(brute_force_parity(9) == 0);
	assert(brute_force_parity(10) == 0);

	assert(refined_brute_force_parity(1) == 1);
	assert(refined_brute_force_parity(2) == 1);
	assert(refined_brute_force_parity(3) == 0);
	assert(refined_brute_force_parity(4) == 1);
	assert(refined_brute_force_parity(5) == 0);
	assert(refined_brute_force_parity(6) == 0);
	assert(refined_brute_force_parity(7) == 1);
	assert(refined_brute_force_parity(8) == 1);
	assert(refined_brute_force_parity(9) == 0);
	assert(refined_brute_force_parity(10) == 0);

	assert(lookup_table_parity(1) == 1);
	assert(lookup_table_parity(2) == 1);
	assert(lookup_table_parity(3) == 0);
	assert(lookup_table_parity(4) == 1);
	assert(lookup_table_parity(5) == 0);
	assert(lookup_table_parity(6) == 0);
	assert(lookup_table_parity(7) == 1);
	assert(lookup_table_parity(8) == 1);
	assert(lookup_table_parity(9) == 0);
	assert(lookup_table_parity(10) == 0);

	assert(xor_parity(1) == 1);
	assert(xor_parity(2) == 1);
	assert(xor_parity(3) == 0);
	assert(xor_parity(4) == 1);
	assert(xor_parity(5) == 0);
	assert(xor_parity(6) == 0);
	assert(xor_parity(7) == 1);
	assert(xor_parity(8) == 1);
	assert(xor_parity(9) == 0);
	assert(xor_parity(10) == 0);
}
