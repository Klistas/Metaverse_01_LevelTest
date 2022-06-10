#include <stdio.h>
#include <utility>





void sortArray(int* arr, int n)
{
	// n개의 정수를 오름차순으로 정렬
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 배열의 원소를 비교하여 특정 원소가 다른 원소보다 작다면
			if (arr[i] < arr[j])
			{
				//값을 바꿔줌
				std::swap(arr[j],arr[i]);
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
