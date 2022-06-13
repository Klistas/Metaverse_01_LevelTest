#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*	
로또 번호 생성기를 구현 하시오.
A.	최대 번호값과 생성 숫자 개수를 입력하면 해당 조건 내에서 중복되지 않는 숫자를 출력하는 로또 번호 생성기를 구현.
B.	최대값 : 60, 생성숫자 : 10 을 입력하면 1 ~ 60 사이의 중복되지 않는 숫자 10개를 생성한다.

*/




void lotteryMaker(int maxNum, int makeNum)
{
	// 랜덤 시드 생성
	srand(time(NULL));
	//저장할 배열 생성
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
//	// 랜덤 시드 생성
//	srand(time(NULL));
//	//저장할 배열 생성
//	int* lotteryNum = new int[makeNum];
//	for (int i = 0; i < makeNum; i++)
//	{
//
//		// 랜덤 시드에 maxNum을 나머지 연산하여 최댓값 이내의 값 도출
//		int checkNum = rand() % maxNum;
//
//		// lotteryNum[checkNum]으로 인덱스가 난수가 됨.
//		lotteryNum[i] = 0;
//
//		// 값을 true와 false로 줘서 true일 때 접근하지 못하게.
//		if (lotteryNum[checkNum] == 0)
//		{
//			lotteryNum[checkNum] = 1;
//		}
//		else
//			checkNum = rand() % maxNum;
//
//
//
//		// 출력시 인덱스에 1을 더함.
//		// 출력
//		printf("%d\n", checkNum + 1);
//
//	}
//	delete[] lotteryNum;
//}


