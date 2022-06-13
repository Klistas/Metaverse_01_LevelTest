#include <stdio.h>
#include <utility>


// arr[10] = { 1 , 31 , 27 , 11 , 32 , 65 , 2 , 8 , 44 , 89 }

void bubbleSort(int* arr, int size)
{
	for (int phase = 0; phase < size - 1; phase++)
	{
		for (int i = 0; i < size - 1 - phase; i++)
		{
			if (arr[i] < arr[i + 1])
			{
				std::swap(arr[i], arr[i + 1]);
			}
		}
	}
}

void selectionSort(int* arr, int size)
{
	
	for (int phase = 0; phase < size - 1; phase++)
	{
		int indexMin = phase;
		for (int i = phase + 1; i < size; i++)
		{
			if (arr[i] < arr[indexMin])
			{
				indexMin = i;
			}
		}
		std::swap(arr[indexMin],arr[phase]);
	}

}

int main(void)
{
	int arr[10] = { 1 , 31 , 27 , 11 , 32 , 65 , 2 , 8 , 44 , 89 };
	selectionSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d \n", arr[i]);
	}

	return 0;
}