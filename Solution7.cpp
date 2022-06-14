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
	// 1. 빙고게임 판 생성.
	// 1-1. 2차원 배열

	int board[5][5] = { 0 };

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
		int bingoCount = 0;
	while (1)
	{
	
		bool bingocheck = false;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << board[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "현재" << bingoCount << "줄의 빙고가 완성되었습니다." << endl;

		// 2. 사용자로부터 입력을 받는다.
		cout << "숫자를 입력해주세요 : ";
		int input;
		cin >> input;

		// 2-1. 플레이어의 입력을 의심해라.
		// 3. 사용자의 입력이 유효한지 판단한다.
		if (input <= 0 || input > 25)
		{
			// 3-1. 오입력이라면 1번부터 다시.


		}

		// 4. 숫자를 지워준다.
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (input == board[i][j])
				{
					board[i][j] = {  };
				}
			}

		}
			for (int i = 0; i < 5; i++)
				{
				for (int j = 0; j < 5; j++)
				{

					// 빙고가 완성되면, 빙고 개수 count (중첩된 빙고개수 제외하는 것이 어려웠음. 리팩토링 필요.)
					if (board[0][0] == NULL && board[1][1] == NULL && board[2][2] == NULL && board[3][3] == NULL && board[4][4] == NULL && diagonalBingo1 == false)
					{
						bingocheck = true;
						diagonalBingo1 = true;

					}
					if (board[0][4] == NULL && board[1][3] == NULL && board[2][2] == NULL && board[3][1] == NULL && board[4][0] == NULL && diagonalBingo2 == false)
					{
						bingocheck = true;
						diagonalBingo2 = true;

					}
					switch (i)
					{
					case 0:
						if (board[i][0] == NULL && board[i][1] == NULL && board[i][2] == NULL && board[i][3] == NULL && board[i][4] == NULL && verticalBingo1 == false)
						{
							bingocheck = true;
							verticalBingo1 = true;
							break;
						}
					case 1:
						if (board[i][0] == NULL && board[i][1] == NULL && board[i][2] == NULL && board[i][3] == NULL && board[i][4] == NULL && verticalBingo2 == false)
						{
							bingocheck = true;
							verticalBingo2 = true;
							break;
						}
					case 2:
						if (board[i][0] == NULL && board[i][1] == NULL && board[i][2] == NULL && board[i][3] == NULL && board[i][4] == NULL && verticalBingo3 == false)
						{
							bingocheck = true;
							verticalBingo3 = true;
							break;
						}
					case 3:
						if (board[i][0] == NULL && board[i][1] == NULL && board[i][2] == NULL && board[i][3] == NULL && board[i][4] == NULL && verticalBingo4 == false)
						{
							bingocheck = true;
							verticalBingo4 = true;
							break;
						}
					case 4:
						if (board[i][0] == NULL && board[i][1] == NULL && board[i][2] == NULL && board[i][3] == NULL && board[i][4] == NULL && verticalBingo5 == false)
						{
							bingocheck = true;
							verticalBingo5 = true;
							break;
						}
					}

					switch (j)
					{
					case 0:
						if (board[0][j] == NULL && board[1][j] == NULL && board[2][j] == NULL && board[3][j] == NULL && board[4][j] == NULL && horizontalBingo1 == false)
						{
							bingocheck = true;
							horizontalBingo1 = true;
							break;
						}
					case 1:
						if (board[0][j] == NULL && board[1][j] == NULL && board[2][j] == NULL && board[3][j] == NULL && board[4][j] == NULL && horizontalBingo2 == false)
						{
							bingocheck = true;
							horizontalBingo2 = true;
							break;
						}
					case 2:
						if (board[0][j] == NULL && board[1][j] == NULL && board[2][j] == NULL && board[3][j] == NULL && board[4][j] == NULL && horizontalBingo3 == false)
						{
							bingocheck = true;
							horizontalBingo3 = true;
							break;
						}
					case 3:
						if (board[0][j] == NULL && board[1][j] == NULL && board[2][j] == NULL && board[3][j] == NULL && board[4][j] == NULL && horizontalBingo4 == false)
						{
							bingocheck = true;
							horizontalBingo4 = true;
							break;
						}
					case 4:
						if (board[0][j] == NULL && board[1][j] == NULL && board[2][j] == NULL && board[3][j] == NULL && board[4][j] == NULL && horizontalBingo5 == false)
						{
							bingocheck = true;
							horizontalBingo5 = true;
							break;
						}
					}
				}
			}
			if (bingocheck == true)
				bingoCount++;
				system("cls");
	}
		// 5. 빙고 개수 확인.
								
								
								
					
					
				
		// 6. 1번 부터 반복.

	return 0;

}


































//
//
//bool verticalBingo1 = false;
//bool verticalBingo2 = false;
//bool verticalBingo3 = false;
//bool verticalBingo4 = false;
//bool verticalBingo5 = false;
//
//bool horizontalBingo1 = false;
//bool horizontalBingo2 = false;
//bool horizontalBingo3 = false;
//bool horizontalBingo4 = false;
//bool horizontalBingo5 = false;
//
//bool diagonalBingo1 = false;
//bool diagonalBingo2 = false;
//int main()
//{
//	// 랜덤으로 1 ~ 25의 값을 가진 이차원 배열 생성
//	srand(time(NULL));
//
//	int bingoElement[5][5];
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			
//				bingoElement[i][j] = rand() % 25 + 1;
//			
//		}
//
//	}
//	// 빙고의 수를 세어줄 변수 생성
//	int bingoCount = 0;
//
//	// 입력값 변수 생성
//	int bingoNum;
//
//	// 게임 루프 생성
//	while (1)
//	{
//		bool bingoCheck = false;
//		// 빙고 이차원 배열 
//		for (int i = 0; i < 5; i++)
//		{
//			for (int j = 0; j < 5; j++)
//			{
//			
//				cout << bingoElement[i][j] << '\t';
//		
//			}
//			cout << endl;
//		}
//		cout << "현재 빙고의 개수 : " << bingoCount << endl;
//		cout << "숫자를 입력해주세요" << endl;
//		cin >> bingoNum;
//
//		// 입력값과 빙고의 값이 일치하면 0으로 변환
//		for (int i = 0; i < 5; i++)
//		{
//			for (int j = 0; j < 5; j++)
//			{
//				if (bingoNum == bingoElement[i][j])
//				{
//					bingoElement[i][j] = {  };
//				}
//				// 빙고가 완성되면, 빙고 개수 count (중첩된 빙고개수 제외하는 것이 어려웠음. 리팩토링 필요.)
//				if (bingoElement[0][0] == NULL && bingoElement[1][1] == NULL && bingoElement[2][2] == NULL && bingoElement[3][3] == NULL && bingoElement[4][4] == NULL && diagonalBingo1 == false)
//				{
//					bingoCheck = true;
//					diagonalBingo1 = true;
//					
//				}
//				if (bingoElement[0][4] == NULL && bingoElement[1][3] == NULL && bingoElement[2][2] == NULL && bingoElement[3][1] == NULL && bingoElement[4][0] == NULL && diagonalBingo2 == false)
//				{
//					bingoCheck = true;
//					diagonalBingo2 = true;
//					
//				}
//						switch (i)
//						{
//						case 0:
//							if (bingoElement[i][0] == NULL && bingoElement[i][1] == NULL && bingoElement[i][2] == NULL && bingoElement[i][3] == NULL && bingoElement[i][4] == NULL && verticalBingo1 == false)
//							{
//								bingoCheck = true;
//								verticalBingo1 = true;
//								break;
//							}
//						case 1:
//							if (bingoElement[i][0] == NULL && bingoElement[i][1] == NULL && bingoElement[i][2] == NULL && bingoElement[i][3] == NULL && bingoElement[i][4] == NULL && verticalBingo2 == false)
//							{
//								bingoCheck = true;
//								verticalBingo2 = true;
//								break;
//							}
//						case 2:
//							if (bingoElement[i][0] == NULL && bingoElement[i][1] == NULL && bingoElement[i][2] == NULL && bingoElement[i][3] == NULL && bingoElement[i][4] == NULL && verticalBingo3 == false)
//							{
//								bingoCheck = true;
//								verticalBingo3 = true;
//								break;
//							}
//						case 3:
//							if (bingoElement[i][0] == NULL && bingoElement[i][1] == NULL && bingoElement[i][2] == NULL && bingoElement[i][3] == NULL && bingoElement[i][4] == NULL && verticalBingo4 == false)
//							{
//								bingoCheck = true;
//								verticalBingo4 = true;
//								break;
//							}
//						case 4:
//							if (bingoElement[i][0] == NULL && bingoElement[i][1] == NULL && bingoElement[i][2] == NULL && bingoElement[i][3] == NULL && bingoElement[i][4] == NULL && verticalBingo5 == false)
//							{
//								bingoCheck = true;
//								verticalBingo5 = true;
//								break;
//							}
//						}
//					
//						switch (j)
//						{
//						case 0:
//							if (bingoElement[0][j] == NULL && bingoElement[1][j] == NULL && bingoElement[2][j] == NULL && bingoElement[3][j] == NULL && bingoElement[4][j] == NULL && horizontalBingo1 == false)
//							{
//								bingoCheck = true;
//								horizontalBingo1 = true;
//								break;
//							}
//						case 1:
//							if (bingoElement[0][j] == NULL && bingoElement[1][j] == NULL && bingoElement[2][j] == NULL && bingoElement[3][j] == NULL && bingoElement[4][j] == NULL && horizontalBingo2 == false)
//							{
//								bingoCheck = true;
//								horizontalBingo2 = true;
//								break;
//							}
//						case 2:
//							if (bingoElement[0][j] == NULL && bingoElement[1][j] == NULL && bingoElement[2][j] == NULL && bingoElement[3][j] == NULL && bingoElement[4][j] == NULL && horizontalBingo3 == false)
//							{
//								bingoCheck = true;
//								horizontalBingo3 = true;
//								break;
//							}
//						case 3:
//							if (bingoElement[0][j] == NULL && bingoElement[1][j] == NULL && bingoElement[2][j] == NULL && bingoElement[3][j] == NULL && bingoElement[4][j] == NULL && horizontalBingo4 == false)
//							{
//								bingoCheck = true;
//								horizontalBingo4 = true;
//								break;
//							}
//						case 4:
//							if (bingoElement[0][j] == NULL && bingoElement[1][j] == NULL && bingoElement[2][j] == NULL && bingoElement[3][j] == NULL && bingoElement[4][j] == NULL && horizontalBingo5 == false)
//							{
//								bingoCheck = true;
//								horizontalBingo5 = true;
//								break;
//							}
//						}
//						
//						
//			
//			}
//		}
//		if (bingoCheck == true)
//			bingoCount++;
//		
//		//스크린 초기화
//		system("cls");
//	}
//
//	return 0;
//}