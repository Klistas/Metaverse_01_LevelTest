#include <stdio.h>
#include <utility>





void sortArray(int* arr, int size)
{
	// n���� ������ ������������ ����
	// ���� ��Ʈ�� ���� ������� �̷�����, �� ���̰� ���� �� �� �� ���Һ��� ����.
	for (int phase = 0; phase < size - 1; phase++)
	{
		for (int i = 0; i < size - 1 - phase; i++)
		{
			
			
			// �迭�� ���Ҹ� ���Ͽ� Ư�� ���Ұ� �ٸ� ���Һ��� �۴ٸ�
			// ������������ ����
			if (arr[i] > arr[i + 1])
			{

				//���� �ٲ���
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
