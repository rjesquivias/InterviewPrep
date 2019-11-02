#include <iostream>
using namespace std;

struct Rectangle {
	int x, y, width, height;
};

bool intersection(Rectangle one, Rectangle two)
{
	if( ((one.x >= two.x && one.x <= two.x + two.width) || (two.x >= one.x && two.x <= one.x + one.width)) && 
		((one.y >= two.y && one.y <= two.y + two.height) || (two.y >= one.y && two.y <= one.y + one.height))
	  )
	{
		return true;
	}

	return false;
}

Rectangle isIntersecting(Rectangle one, Rectangle two)
{
	Rectangle solution;
	if(!intersection(one, two))
	{
		solution.x = 0;
		solution.y = 0;
		solution.width = -1;
		solution.height = -1;
		return solution;
	}

	int x = max(one.x, two.x);
	int y = max(one.y, two.y);
	int width = min(abs(x - (one.x + one.width)), abs(x - (two.x + two.width)));
	int height = min(abs(y - (one.y + one.height)), abs(y - (two.y + two.height)));

	return {x, y, width, height};
}

int main()
{
	Rectangle one, two;
	
	one.x = 8;
	one.y = 2;
	one.width = 1;
	one.height = 1;

	two.x = 9;
	two.y = 2;
	two.width = 1;
	two.height = 2;

	Rectangle intersect = isIntersecting(one, two);
	cout << intersect.x << " " << intersect.y << " " << intersect.width << " " << intersect.height << endl;

	return 0;
}