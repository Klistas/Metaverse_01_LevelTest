#include <stdio.h>


// 1000�̸��� 3�� �¼��� ���ʴ�� ���

int main(void)
{
	
	for (int i = 0; i < 1000; i += 3)
	{
		// 3�� �¼� answer
		int answer = i * 3;
		// answer�� 1000 �̸�.
		if (answer < 1000)
		{
			answer * 3;
			printf("%d \n", answer);
		}
	}

	return 0;

}