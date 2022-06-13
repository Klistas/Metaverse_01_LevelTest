#include <stdio.h>
#include <utility>





void sortArray(int* arr, int size)
{
	// n개의 정수를 오름차순으로 정렬
	// 버블 소트는 여러 페이즈로 이뤄지며, 각 페이가 끝날 시 맨 끝 원소부터 정렬.
	for (int phase = 0; phase < size - 1; phase++)
	{
		for (int i = 0; i < size - 1 - phase; i++)
		{
			
			
			// 배열의 원소를 비교하여 특정 원소가 다른 원소보다 작다면
			// 오름차순으로 정렬
			if (arr[i] > arr[i + 1])
			{

				//값을 바꿔줌
				std::swap(arr[i], arr[i + 1]);
			}

		}

	}

}
	
int main(void)
{

int arr[5] = { 5, 2, 4, 1, 3 };


sortArray(arr, 5);
for (int i = 0; i < 5; i++)
printf("%d \n", arr[i]);
return 0;
}

// arr : [ 1, 2, 3, 4, 5 ]
