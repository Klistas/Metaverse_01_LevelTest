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

#define NOT_VISITED 0


int main()
{
	// 1. 배열 만들기
	cout << "배열의 크기를 입력하세요 : ";
	int size;
	cin >> size;

	int* arr = new int[size * size];
	memset(arr, 0, sizeof(int) * size * size);

	// 2.달팽이 배열 세팅
	// 2 - 1. 달팽이 데이터 초기화
	enum Direction 
	{ 
		DIR_RIGHT,
		DIR_DOWN,
		DIR_LEFT,
		DIR_UP,
		DIR_MAX
	};

	int posX = 0;
	int posY = 0;
	int footstep = 1;
	Direction direction = DIR_RIGHT;

	for (int i = 0; i < size * size; i++)
	{
		// 2-2 달팽이 움직임. 발자국을 남긴다.
		arr[posX * size + posY] = footstep;
		++footstep;


		// 2-3 이동할 위치를 계산한다.
		
		static const int deltaX[] = { 1, 0, -1, 0 };
		static const int deltaY[] = { 0, 1, 0, -1 };

		int newX = posX + deltaX[(int)direction];
		int newY = posY + deltaY[(int)direction];
		
		// 2-4 이동이 가능한 지 판별한다.
		// 2-4-1 벽에 닿았을 때 => posX, posY의 위치가 [0, size]
		// 2-4-2 이미 지나온 곳일 때 => arr[newX][newY] != 0
		if (newY < 0 || newY >= size || newX < 0 || newX >= size ||
			arr[newY * size + newX] != NOT_VISITED)
		{
			// 2-5. 이동이 불가능하므로 방향 전환을 한다.
			direction = (Direction)((direction + 1) % DIR_MAX);

			// 2-6 위치값을 다시 계산한다.
			int newX = posX + deltaX[(int)direction];
			int newY = posY + deltaY[(int)direction];
		}
		// 2-7 이동한다.
		posX = newX;
		posY = newY;
	}


	// 3. 출력
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i * size + j] << "\t";
		}

		cout << "\n";
	}
}










//
//2차원 배열의 동적할당
//int** arr = new int* [size];
//for (int i = 0; i < size; i++)
//{
//	arr[i] = new int[size];
//}
//
//
//for (int i = 0; i < size; i++)
//{
//	delete[] arr[i];
//}
//delete[] arr;



//
//int main()
//{
//	// 배열의 크기
//	int arrSize;
//
//
//	// 사용자 입력
//	cout << "배열의 크기를 입력하세요 : ";
//	cin >> arrSize;
//	cout << endl;
//
//	// 저장할 배열
//	int** arr = new int* [arrSize];
//	for (int i = 0; i < arrSize; i++)
//	{
//		arr[i] = new int[arrSize];
//	}
// 
//	// 현재 배열의 크기를 저장할 변수
//	int prevSize = arrSize;
//	
//	// x좌표 (0일 시, 한 칸 밀려 출력됨.)
//	int posX = -1; 
//	
//	// y좌표
//	int posY = 0;
//
//	// 배열의 좌표를 이동시키고, 이동방향을 바꿔줌
//	int move = 1;
//
//	// 배열에 값을 넣어줄 변수
//	int moveCount = 1;
//
//	// 배열의 크기만큼 사이클을 돌린다
//	while (0 < arrSize)
//	{
//		// 첫번째 줄
//		for (int i = 0; i < arrSize; i++)
//		{
//			// x좌표를 한칸씩 이동시킴.
//			posX += move;
//
//			// 이동한 좌표에 값을 넣어줌
//			arr[posY][posX] = moveCount;
//
//			// 좌표가 이동할 때 마다 가산.
//			moveCount++;
//		}
//
//		// 배열의 크기만큼 이동하면, 방향을 바꾸고, (arrSize - 1) 만큼 이동해야하므로
//		// 배열의 크기를 감산해줌.
//		arrSize--;
//
//		// 방향을 바꿔 y좌표를 이동시킴.
//		for (int i = 0; i < arrSize; i++)
//		{
//			// y좌표를 한칸씩 이동시킴.
//			posY += move;
//
//			// 이동한 좌표에 값을 넣어줌
//			arr[posY][posX] = moveCount;
//
//			// 좌표가 이동할 때마다 가산
//			moveCount++;
//		}
//		//첫번째 사이클이 끝나면 반대로 이동해야하므로 부호를 바꿔줌.
//		move *= -1;
//	}
//
// 
//
//	// 출력 : 배열의 크기가 위의 처리부에서 줄어들었기 때문에, 
//	// 미리 저장해둔 배열의 크기를 사용하여 출력.
//	for (int i = 0; i < prevSize; i++)
//	{
//		for (int j = 0; j < prevSize; j++)
//		{
//			cout << arr[i][j] << "\t";
//		}
//		cout << endl;
//	}
//	
//	for (int i = 0; i < prevSize; i++)
//	{
//		delete[] arr[i];
//	}
// 
//	delete[] arr;
//
//}
//
//
