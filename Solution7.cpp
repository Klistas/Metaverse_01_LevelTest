#include <iostream>
#include <time.h>
using namespace std;


class Bingo
{
public :

	Bingo() = default;
	Bingo(const Bingo& other) = delete;
	Bingo& operator=(const Bingo& other) = delete;
	~Bingo() = default;


	void bingoMap()
	{
		// 1-2. �����ϰ� ���� ��ġ.
		srand(time(NULL));
		bool isExist[26] = { false };

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int boardNum = 0;
				do
				{
					boardNum = rand() % 25 + 1;

				} while (isExist[boardNum]);

				board[i][j] = boardNum;
				isExist[boardNum] = true;
			}
		}
	}

	void bingoInput(int input)
	{
		// 2. ����ڷκ��� �Է��� �޴´�.
		_input = input;
	}
	void bingoPrint()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (board[i][j] != NULL)
					cout << board[i][j] << "\t";
				else
					cout << "\t";
			}
			cout << endl;
		}
		cout << "����" << bingoCount << "���� ���� �ϼ��Ǿ����ϴ�." << endl;

		
		cout << "���ڸ� �Է����ּ��� : ";
		
	}
	
	void bingoUpdate()
	{

		
		for (int i = 0; i < 5; i++)
		{
			bool isExit = false;
			for (int j = 0; j < 5; j++)
			{
				if (_input == board[i][j])
				{
					board[i][j] = {  };
					isExit = true;
					break;
					//goto OUT;
				}
			}
			if (isExit)
			{
				break;
			}


		}
	}

	void bingoCheck()
	{
		// 5. ���� ���� Ȯ��.
		// - ������ ��� ���ڸ� ���� ��
		int count = 0;

		for (int i = 0; i < 5; ++i)
		{
			bool isBingo = true;
			for (int j = 0; j < 5; j++)
			{
				if (board[i][j] != NULL)
				{
					isBingo = false;
					break;
				}

			}
			if (isBingo)
			{
				count++;
			}
		}
		// - ������ ��� ���ڸ� ���� ��
		for (int i = 0; i < 5; ++i)
		{
			bool isBingo = true;
			for (int j = 0; j < 5; j++)
			{
				if (board[j][i] != NULL)
				{
					isBingo = false;
					break;
				}

			}
			if (isBingo)
			{
				count++;
			}
		}
		// �밢�� 1
		{
			bool isBingo = true;
			for (int i = 0; i < 5; ++i)
			{
				if (board[i][i] != NULL)
				{
					isBingo = false;
					break;
				}
			}

			if (isBingo)
			{
				count++;
			}

		}


		//�밢�� 2.
		{
			bool isBingo = true;
			for (int i = 0; i <= 2; ++i)
			{
				if (board[i][4 - i] != NULL || board[4 - i][i] != NULL)
				{
					isBingo = false;
					break;
				}
			}

			if (isBingo)
			{
				count++;
			}
		}
		bingoCount = count;
	}



private :
	int board[5][5] = { 0 };
	bool bingocheck = false;
	int _input = 0;
	int bingoCount = 0;
	
};



int main()
{
	// 1. ������� �� ����.
	// 1-1. 2���� �迭

	Bingo bingo;
	
	
	bingo.bingoMap();
	
	while (1)
	{
	
		int input;
		bingo.bingoPrint();
		cin >> input;
		bingo.bingoInput(input);
		bingo.bingoUpdate();
		bingo.bingoCheck();

		system("cls");

	}

	

	return 0;

}










//
//
//int main()
//{
//	// 1. ������� �� ����.
//	// 1-1. 2���� �迭
//
//	int board[5][5] = { 0 };
//
//	// 1-2. �����ϰ� ���� ��ġ.
//	srand(time(NULL));
//	bool isExist[26] = { false };
//
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			int boardNum = 0;
//			do
//			{
//				boardNum = rand() % 25 + 1;
//
//			} while (isExist[boardNum]);
//
//			board[i][j] = boardNum;
//			isExist[boardNum] = true;
//		}
//	}
//
//	int bingoCount = 0;
//
//	while (1)
//	{
//
//		bool bingocheck = false;
//		for (int i = 0; i < 5; i++)
//		{
//			for (int j = 0; j < 5; j++)
//			{
//				if (board[i][j] != NULL)
//					cout << board[i][j] << "\t";
//				else
//					cout << "\t";
//			}
//			cout << endl;
//		}
//		cout << "����" << bingoCount << "���� ���� �ϼ��Ǿ����ϴ�." << endl;
//
//		// 2. ����ڷκ��� �Է��� �޴´�.
//		cout << "���ڸ� �Է����ּ��� : ";
//		int input;
//		cin >> input;
//
//		// 2-1. �÷��̾��� �Է��� �ǽ��ض�.
//		// 3. ������� �Է��� ��ȿ���� �Ǵ��Ѵ�.
//		if (input <= 0 || input > 25)
//		{
//			// 3-1. ���Է��̶�� 1������ �ٽ�.
//
//
//		}
//
//		// 4. ���ڸ� �����ش�.
//		for (int i = 0; i < 5; i++)
//		{
//			bool isExit = false;
//			for (int j = 0; j < 5; j++)
//			{
//				if (input == board[i][j])
//				{
//					board[i][j] = {  };
//					isExit = true;
//					break;
//					//goto OUT;
//				}
//			}
//			if (isExit)
//			{
//				break;
//			}
//
//
//		}
//		//OUT:
//		// 
//		// 5. ���� ���� Ȯ��.
//		// - ������ ��� ���ڸ� ���� ��
//		int count = 0;
//
//		for (int i = 0; i < 5; ++i)
//		{
//			bool isBingo = true;
//			for (int j = 0; j < 5; j++)
//			{
//				if (board[i][j] != NULL)
//				{
//					isBingo = false;
//					break;
//				}
//
//			}
//			if (isBingo)
//			{
//				count++;
//			}
//		}
//		// - ������ ��� ���ڸ� ���� ��
//		for (int i = 0; i < 5; ++i)
//		{
//			bool isBingo = true;
//			for (int j = 0; j < 5; j++)
//			{
//				if (board[j][i] != NULL)
//				{
//					isBingo = false;
//					break;
//				}
//
//			}
//			if (isBingo)
//			{
//				count++;
//			}
//		}
//		// �밢�� 1
//		{
//			bool isBingo = true;
//			for (int i = 0; i < 5; ++i)
//			{
//				if (board[i][i] != NULL)
//				{
//					isBingo = false;
//					break;
//				}
//			}
//
//			if (isBingo)
//			{
//				count++;
//			}
//
//		}
//
//
//		//�밢�� 2.
//		{
//			bool isBingo = true;
//			for (int i = 0; i <= 2; ++i)
//			{
//				if (board[i][4 - i] != NULL || board[4 - i][i] != NULL)
//				{
//					isBingo = false;
//					break;
//				}
//			}
//
//			if (isBingo)
//			{
//				count++;
//			}
//		}
//
//		system("cls");
//		bingoCount = count;
//
//	}
//
//	// 6. 1�� ���� �ݺ�.
//
//	return 0;
//
//}
//
//
//



















