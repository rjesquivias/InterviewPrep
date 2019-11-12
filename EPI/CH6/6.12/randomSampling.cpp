#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

/*
	rand() does not uniformly distribute random numbers...
	We are using it here for demonstration but to have a truly 
	valid solution you must use a rng that uniformally distributes 
	its numbers.
*/

void RandomSampling(int k, vector<int>* A_ptr){
	vector<int>& A = *A_ptr;

	// Select a random choice from A and put it towards the beginning
	for(int i = 0; i < k; i++)
	{
		int choice = rand() % A.size() + (i + 1);
		choice -= 1;
		swap(A[i], A[choice]);
	}
}

int main()
{
	srand(time(NULL));

	vector<int> A = {3, 7, 5, 11};
	vector<int>* A_ptr = &A;
	int k = 3;

	RandomSampling(k, A_ptr);

	for(auto x : A)
	{
		cout << x << " ";
	}
	cout << endl;

	return 0;
}