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
	for (int i = 0; i < makeNum; i++)
	{
		//저장할 배열 생성
		int lotteryNum[1000];

		// 랜덤 시드에 maxNum을 나머지 연산하여 최댓값 이내의 값 도출
			lotteryNum[i] = rand() % maxNum + 1;
		// 생성숫자만큼 반복
		for (int j = 0; j < makeNum; j++)
		{
		
				if (i != j)
				{
						// 중복된 값 제외 (잘 안됨...)
						if (lotteryNum[i] == lotteryNum[j])
						lotteryNum[i] = rand() % maxNum + 1;
						
				}
			
		
		}
	
		// 출력
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