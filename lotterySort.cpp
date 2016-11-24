// lotterySort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
bool isNotSorted(int * arr, int size);
void randomize(int * arr, int size);


int main()
{
	srand(time(NULL));//initialize the random to a time seed value

	const int size = 6;
	int * arr;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10 + 1; // random number 1-10
	}

	cout << "initial array: " << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;


	int howLong = 0;
	while (isNotSorted(arr, size))
	{
		randomize(arr, size);
/*		cout << howLong << ": ";
		for (size_t i = 0; i < size; i++)//output current sort to console
		{
			cout << arr[i] << ", ";
		}
		cout << endl;*/
		howLong++;
	}
	cout << "there were a total of " << howLong << " configurations before a sorted array was found" << endl;
    return 0;
}

bool isNotSorted(int * arr, int size)
{
	bool isSorted = true;

	for (size_t i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i+1])
		{
			isSorted = false;
		}
	}

	return !isSorted;
}


//works by starting at an indici and then potentially swapping 
//it with all of the following indicies before moving on to the next indicie
void randomize(int * arr, int size)
{
	for (int j = 0; j < size-1; j++)
	{
		for (int i = j; i < size -1; i++)
		{
			if (rand() % 2 == 0)//50 50 chance of swap
			{
				swap(arr[j], arr[i + 1]);
			}
		}
	}
}

void swap(int * a, int * b)
{
	int * temp = a;
	a = b;
	b = temp;
}