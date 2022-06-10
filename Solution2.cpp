#include <stdio.h>


// 1000미만의 3의 승수를 차례대로 출력

int main(void)
{
	
	for (int i = 0; i < 1000; i += 3)
	{
		// 3의 승수 answer
		int answer = i * 3;
		// answer는 1000 미만.
		if (answer < 1000)
		{
			answer * 3;
			printf("%d \n", answer);
		}
	}

	return 0;

}