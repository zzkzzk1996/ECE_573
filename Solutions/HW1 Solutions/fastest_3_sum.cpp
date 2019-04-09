// fastest_3_sum.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int a[] = {-6,-5,0,1,2,3,4,5,6};			//sorted array

	int len = 8;	//length of the array
	int initial = 0;		//initial index of the array

	for (int i = 0; i < len - 1; i++)								//this will move from 1st to second last element. We dont need to go beyond it
	{
		int l = i + 1;		 //pointer to begining of search
		int h = len;		//pointer to end of the array
		while (l < h)		//To maintain one pass
		{
			if (a[i] + a[l] + a[h] < 0)			//if the sum is < zero, we need a bigger number. Therefore l++
				l++;
			else if (a[i] + a[l] + a[h] > 0)	//if the sum is > zero, then we need to add a smaller number. h--
				h--;
			else if (a[l] + a[h] + a[i] == 0)
			{
				cout << "(" << a[i] << "," << a[l] << "," << a[h] << ") sum to zero at positions (" << i << "," << l << "," << h << ")" << endl;
				l++;			//found the numbers. If one of them is fixed, then the fixed and one of the two can never make a sum ==0 again
				h--;			//therefore, both of them can move
			}
		}
	}
}
