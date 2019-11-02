#include <iostream>
#include <vector>
using namespace std;

void partition(vector<int>& v, int i)
{
	int partitionValue = v[i];

	int leftInsertionIndex = 0;
	int rightInsertionIndex = v.size() - 1;
	int iterator = 0;

	while(iterator <= rightInsertionIndex)
	{
		if(v[iterator] < partitionValue)
		{
			swap(v[iterator], v[leftInsertionIndex++]);
			iterator++; // Don't increment when swapping with the right value since we haven't looked at that value yet
		}
		else if(v[iterator] > partitionValue)
		{
			swap(v[iterator], v[rightInsertionIndex--]);
		}
		else
		{
			iterator++;
		}
	}
}

int main()
{
	vector<int> v = { 5, 1, 9, 2, 4, 1, 13, 24, 9, 12, 32, 3, 17, 14, 38, 32 };

	partition(v, 6);

	for(auto x : v)
	{
		cout << x << " ";
	}

	cout << endl;

	return 0;
}