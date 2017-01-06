// Implemented by: Chris Spreadborough
// Description: A implementation of the BogoSort sorting algorithm
// Initial Creation: 11/23/2016
// Last modified: 1/6/2017


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
bool isNotSorted(int * arr, int size);
void randomize(int * arr, int size);
int sort(int * arr, int size);


int main()
{
	srand(time(NULL));//initialize the random to a time seed value


	//Generate an Array and print out the initial generated configuration
	const int size = 5;
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

	//Call to the actual algorithm
	int howLong = sort(arr, size);

	//Tells the user how many permutaions were needed before the array was sorted
	cout << "there were a total of " << howLong << " configurations before a sorted array was found" << endl;
    return 0;
}


int sort(int * arr, int size)
{
	int howLong = 0;
	while (isNotSorted(arr, size))
	{
		randomize(arr, size);
		cout << howLong << ": ";
		for (int i = 0; i < size; i++)//output current sort to console
		{
			cout << arr[i] << ", ";
		}
		cout << endl;
		howLong++;
	}
	return howLong;
}


bool isNotSorted(int * arr, int size)
{
	bool isSorted = true;

	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i+1])
		{
			isSorted = false;
		}
	}

	return !isSorted;
}


//Randomly chooses whether or not to swap any two elements
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
