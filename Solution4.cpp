#include <stdio.h>
#include <utility>





void sortArray(int* arr, int n)
{
	// n���� ������ ������������ ����
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// �迭�� ���Ҹ� ���Ͽ� Ư�� ���Ұ� �ٸ� ���Һ��� �۴ٸ�
			if (arr[i] < arr[j])
			{
				//���� �ٲ���
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
