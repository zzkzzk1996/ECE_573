// HW1_pair_sum.cpp

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int a[] = {-6,-5,-3,1,2,3,4,5,6};
	int l = 0;		//initial iterator
	int h = 8;		//iterator to the end of the array
	while (l < h)	// this ensures we scan the array once
	{
		if (a[l] + a[h] == 0)
		{
			cout << "There is a pair at (" << l << "," << h << ")" << endl;
			l = l + 1;
			h = h - 1;
		}
		else if (a[h] + a[l] < 0)		//sum is less than 0, thus we have need a bigger value. 
			l = l + 1;
		else if (a[h] + a[l] > 0)
			h = h - 1;					//sum is more than zero, thus we need a smaller value.
	}
}
