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
	//������ �迭 ����
	int* lotteryNum = new int[makeNum];
	
	for (int curPos = 0; curPos < maxNum; curPos++)
	{
		int candidate = 0;
		lotteryNum[curPos] = rand() % maxNum + 1;
		bool isExist = false;
		for (int i = 0; i < maxNum; i++)
		{
			candidate = lotteryNum[curPos];
			isExist = false;
			do
			{
				if (lotteryNum[curPos] == lotteryNum[i])
				{
					isExist = true;
					lotteryNum[curPos] = rand() % maxNum + 1;
					candidate = lotteryNum[curPos];
					break;
				}
			} while (isExist);
		}
		printf("%d \n", lotteryNum[curPos]);
	}

	
	delete[] lotteryNum;
}





int main(void)
{

	int maxNum, makeNum;
	scanf_s("%d\n",&maxNum);
	scanf_s("%d",&makeNum);
	lotteryMaker(maxNum, makeNum);
	return 0;

}













//
//
//void lotteryMaker(int maxNum, int makeNum)
//{
//	// ���� �õ� ����
//	srand(time(NULL));
//	//������ �迭 ����
//	int* lotteryNum = new int[makeNum];
//	for (int i = 0; i < makeNum; i++)
//	{
//
//		// ���� �õ忡 maxNum�� ������ �����Ͽ� �ִ� �̳��� �� ����
//		int checkNum = rand() % maxNum;
//
//		// lotteryNum[checkNum]���� �ε����� ������ ��.
//		lotteryNum[i] = 0;
//
//		// ���� true�� false�� �༭ true�� �� �������� ���ϰ�.
//		if (lotteryNum[checkNum] == 0)
//		{
//			lotteryNum[checkNum] = 1;
//		}
//		else
//			checkNum = rand() % maxNum;
//
//
//
//		// ��½� �ε����� 1�� ����.
//		// ���
//		printf("%d\n", checkNum + 1);
//
//	}
//	delete[] lotteryNum;
//}


