#include <iostream>
#include <time.h>
using namespace std;






bool verticalBingo1 = false;
bool verticalBingo2 = false;
bool verticalBingo3 = false;
bool verticalBingo4 = false;
bool verticalBingo5 = false;

bool horizontalBingo1 = false;
bool horizontalBingo2 = false;
bool horizontalBingo3 = false;
bool horizontalBingo4 = false;
bool horizontalBingo5 = false;

bool diagonalBingo1 = false;
bool diagonalBingo2 = false;
int main()
{
	// �������� 1 ~ 25�� ���� ���� ������ �迭 ����
	srand(time(NULL));

	int bingoElement[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			
				bingoElement[i][j] = rand() % 25 + 1;
			
		}

	}
	// ������ ���� ������ ���� ����
	int bingoCount = 0;

	// �Է°� ���� ����
	int bingoNum;

	// ���� ���� ����
	while (1)
	{
		bool bingoCheck = false;
		// ���� ������ �迭 
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
			
				cout << bingoElement[i][j] << '\t';
		
			}
			cout << endl;
		}
		cout << "���� ������ ���� : " << bingoCount << endl;
		cout << "���ڸ� �Է����ּ���" << endl;
		cin >> bingoNum;

		// �Է°��� ������ ���� ��ġ�ϸ� 0���� ��ȯ
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (bingoNum == bingoElement[i][j])
				{
					bingoElement[i][j] = {  };
				}
				// ������ �ϼ��Ǹ�, ���� ���� count (��ø�� �������� �����ϴ� ���� �������. �����丵 �ʿ�.)
				if (bingoElement[0][0] == NULL && bingoElement[1][1] == NULL && bingoElement[2][2] == NULL && bingoElement[3][3] == NULL && bingoElement[4][4] == NULL && diagonalBingo1 == false)
				{
					bingoCheck = true;
					diagonalBingo1 = true;
					
				}
				if (bingoElement[0][4] == NULL && bingoElement[1][3] == NULL && bingoElement[2][2] == NULL && bingoElement[3][1] == NULL && bingoElement[4][0] == NULL && diagonalBingo2 == false)
				{
					bingoCheck = true;
					diagonalBingo2 = true;
					
				}
						switch (i)
						{
						case 0:
							if (bingoElement[i][0] == NULL && bingoElement[i][1] == NULL && bingoElement[i][2] == NULL && bingoElement[i][3] == NULL && bingoElement[i][4] == NULL && verticalBingo1 == false)
							{
								bingoCheck = true;
								verticalBingo1 = true;
								break;
							}
						case 1:
							if (bingoElement[i][0] == NULL && bingoElement[i][1] == NULL && bingoElement[i][2] == NULL && bingoElement[i][3] == NULL && bingoElement[i][4] == NULL && verticalBingo2 == false)
							{
								bingoCheck = true;
								verticalBingo2 = true;
								break;
							}
						case 2:
							if (bingoElement[i][0] == NULL && bingoElement[i][1] == NULL && bingoElement[i][2] == NULL && bingoElement[i][3] == NULL && bingoElement[i][4] == NULL && verticalBingo3 == false)
							{
								bingoCheck = true;
								verticalBingo3 = true;
								break;
							}
						case 3:
							if (bingoElement[i][0] == NULL && bingoElement[i][1] == NULL && bingoElement[i][2] == NULL && bingoElement[i][3] == NULL && bingoElement[i][4] == NULL && verticalBingo4 == false)
							{
								bingoCheck = true;
								verticalBingo4 = true;
								break;
							}
						case 4:
							if (bingoElement[i][0] == NULL && bingoElement[i][1] == NULL && bingoElement[i][2] == NULL && bingoElement[i][3] == NULL && bingoElement[i][4] == NULL && verticalBingo5 == false)
							{
								bingoCheck = true;
								verticalBingo5 = true;
								break;
							}
						}
					
						switch (j)
						{
						case 0:
							if (bingoElement[0][j] == NULL && bingoElement[1][j] == NULL && bingoElement[2][j] == NULL && bingoElement[3][j] == NULL && bingoElement[4][j] == NULL && horizontalBingo1 == false)
							{
								bingoCheck = true;
								horizontalBingo1 = true;
								break;
							}
						case 1:
							if (bingoElement[0][j] == NULL && bingoElement[1][j] == NULL && bingoElement[2][j] == NULL && bingoElement[3][j] == NULL && bingoElement[4][j] == NULL && horizontalBingo2 == false)
							{
								bingoCheck = true;
								horizontalBingo2 = true;
								break;
							}
						case 2:
							if (bingoElement[0][j] == NULL && bingoElement[1][j] == NULL && bingoElement[2][j] == NULL && bingoElement[3][j] == NULL && bingoElement[4][j] == NULL && horizontalBingo3 == false)
							{
								bingoCheck = true;
								horizontalBingo3 = true;
								break;
							}
						case 3:
							if (bingoElement[0][j] == NULL && bingoElement[1][j] == NULL && bingoElement[2][j] == NULL && bingoElement[3][j] == NULL && bingoElement[4][j] == NULL && horizontalBingo4 == false)
							{
								bingoCheck = true;
								horizontalBingo4 = true;
								break;
							}
						case 4:
							if (bingoElement[0][j] == NULL && bingoElement[1][j] == NULL && bingoElement[2][j] == NULL && bingoElement[3][j] == NULL && bingoElement[4][j] == NULL && horizontalBingo5 == false)
							{
								bingoCheck = true;
								horizontalBingo5 = true;
								break;
							}
						}
						
						
			
			}
		}
		if (bingoCheck == true)
			bingoCount++;
		
		//��ũ�� �ʱ�ȭ
		system("cls");
	}

	return 0;
}