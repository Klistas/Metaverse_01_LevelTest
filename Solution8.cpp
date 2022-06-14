/*
8.	N * N 달팽이 배열 알고리즘을 구현 하시오.
A.	이차원 배열의 크기를 결정할 N을 정수로 입력 받는다.
B.	출력예시)
배열의 크기를 입력하세요 : _5
1	2	3	4	5
16	17	18	19	6
15	24	25	20	7
14	23	22	21	8
13	12	11	10	9


*/


#include <iostream>

using namespace std;
int main()
{
	int arrSize;
	int arr[100][100] = { 0 };
	cout << "배열의 크기를 입력하세요 : ";
	cin >> arrSize;
	cout << endl;
	int prevSize = arrSize;
	int posX = -1; 
	int posY = 0;
	int move = 1;
	int moveCount = 1;
	while (0 < arrSize)
	{
		for (int i = 0; i < arrSize; i++)
		{
			posX += move;
			arr[posY][posX] = moveCount;
			moveCount++;
		}

		arrSize--;

		for (int i = 0; i < arrSize; i++)
		{
			posY += move;
			arr[posY][posX] = moveCount;
			moveCount++;
		}
		move *= -1;
	}

	for (int i = 0; i < prevSize; i++)
	{
		for (int j = 0; j < prevSize; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	


}


//1 2 3
//8 9 4
//7 6 5


