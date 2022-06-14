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
		// 1-2. 랜덤하게 수를 배치.
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
		// 2. 사용자로부터 입력을 받는다.
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
		cout << "현재" << bingoCount << "줄의 빙고가 완성되었습니다." << endl;

		
		cout << "숫자를 입력해주세요 : ";
		
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
		// 5. 빙고 개수 확인.
		// - 가로의 모든 숫자를 지운 것
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
		// - 세로의 모든 숫자를 지운 것
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
		// 대각선 1
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


		//대각선 2.
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
	// 1. 빙고게임 판 생성.
	// 1-1. 2차원 배열

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
//	// 1. 빙고게임 판 생성.
//	// 1-1. 2차원 배열
//
//	int board[5][5] = { 0 };
//
//	// 1-2. 랜덤하게 수를 배치.
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
//		cout << "현재" << bingoCount << "줄의 빙고가 완성되었습니다." << endl;
//
//		// 2. 사용자로부터 입력을 받는다.
//		cout << "숫자를 입력해주세요 : ";
//		int input;
//		cin >> input;
//
//		// 2-1. 플레이어의 입력을 의심해라.
//		// 3. 사용자의 입력이 유효한지 판단한다.
//		if (input <= 0 || input > 25)
//		{
//			// 3-1. 오입력이라면 1번부터 다시.
//
//
//		}
//
//		// 4. 숫자를 지워준다.
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
//		// 5. 빙고 개수 확인.
//		// - 가로의 모든 숫자를 지운 것
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
//		// - 세로의 모든 숫자를 지운 것
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
//		// 대각선 1
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
//		//대각선 2.
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
//	// 6. 1번 부터 반복.
//
//	return 0;
//
//}
//
//
//



















