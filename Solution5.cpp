#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*	
�ζ� ��ȣ �����⸦ ���� �Ͻÿ�.
A.	�ִ� ��ȣ���� ���� ���� ������ �Է��ϸ� �ش� ���� ������ �ߺ����� �ʴ� ���ڸ� ����ϴ� �ζ� ��ȣ �����⸦ ����.
B.	�ִ밪 : 60, �������� : 10 �� �Է��ϸ� 1 ~ 60 ������ �ߺ����� �ʴ� ���� 10���� �����Ѵ�.

*/

void lotteryMaker(int maxNum, int makeNum)
{
	// ���� �õ� ����
	srand(time(NULL));
	for (int i = 0; i < makeNum; i++)
	{
		//������ �迭 ����
		int lotteryNum[1000];

		// ���� �õ忡 maxNum�� ������ �����Ͽ� �ִ� �̳��� �� ����
			lotteryNum[i] = rand() % maxNum + 1;
		// �������ڸ�ŭ �ݺ�
		for (int j = 0; j < makeNum; j++)
		{
		
				if (i != j)
				{
						// �ߺ��� �� ���� (�� �ȵ�...)
						if (lotteryNum[i] == lotteryNum[j])
						lotteryNum[i] = rand() % maxNum + 1;
						
				}
			
		
		}
	
		// ���
		printf("%d\n", lotteryNum[i]);
		
	}

}



int main(void)
{

	int maxNum, makeNum;
	scanf_s("%d %d", &maxNum, &makeNum);
	lotteryMaker(maxNum, makeNum);
	return 0;

}