#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(vector<int> prices)
{
	vector<int> maxSellPrices = prices;
	int maximum = maxSellPrices[maxSellPrices.size() - 1];
	for(int i = maxSellPrices.size() - 2; i >= 0; i--)
	{
		if(maxSellPrices[i] > maximum)
		{
			maximum = maxSellPrices[i];
		}

		maxSellPrices[i] = maximum;
	}

	for(int x : maxSellPrices)
	{
		cout << x << " ";
	}
	cout << endl;

	int maxProfit = 0;
	for(int i = 0; i < prices.size() - 1; i++)
	{
		int profit = maxSellPrices[i + 1] - prices[i];
		if(profit > maxProfit)
		{
			maxProfit = profit;
		}
	}

	return maxProfit;
}

int main()
{
	vector<int> prices = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250}; // Answer is 30
	cout << maximumProfit(prices) << endl;

	return 0;
}