/*
8.	N * N ������ �迭 �˰����� ���� �Ͻÿ�.
A.	������ �迭�� ũ�⸦ ������ N�� ������ �Է� �޴´�.
B.	��¿���)
�迭�� ũ�⸦ �Է��ϼ��� : _5
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
	// 1. �迭 �����
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	int size;
	cin >> size;

	int* arr = new int[size * size];
	memset(arr, 0, sizeof(int) * size * size);

	// 2.������ �迭 ����
	// 2 - 1. ������ ������ �ʱ�ȭ
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
		// 2-2 ������ ������. ���ڱ��� �����.
		arr[posX * size + posY] = footstep;
		++footstep;


		// 2-3 �̵��� ��ġ�� ����Ѵ�.
		
		static const int deltaX[] = { 1, 0, -1, 0 };
		static const int deltaY[] = { 0, 1, 0, -1 };

		int newX = posX + deltaX[(int)direction];
		int newY = posY + deltaY[(int)direction];
		
		// 2-4 �̵��� ������ �� �Ǻ��Ѵ�.
		// 2-4-1 ���� ����� �� => posX, posY�� ��ġ�� [0, size]
		// 2-4-2 �̹� ������ ���� �� => arr[newX][newY] != 0
		if (newY < 0 || newY >= size || newX < 0 || newX >= size ||
			arr[newY * size + newX] != NOT_VISITED)
		{
			// 2-5. �̵��� �Ұ����ϹǷ� ���� ��ȯ�� �Ѵ�.
			direction = (Direction)((direction + 1) % DIR_MAX);

			// 2-6 ��ġ���� �ٽ� ����Ѵ�.
			int newX = posX + deltaX[(int)direction];
			int newY = posY + deltaY[(int)direction];
		}
		// 2-7 �̵��Ѵ�.
		posX = newX;
		posY = newY;
	}


	// 3. ���
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
//2���� �迭�� �����Ҵ�
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
//	// �迭�� ũ��
//	int arrSize;
//
//
//	// ����� �Է�
//	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
//	cin >> arrSize;
//	cout << endl;
//
//	// ������ �迭
//	int** arr = new int* [arrSize];
//	for (int i = 0; i < arrSize; i++)
//	{
//		arr[i] = new int[arrSize];
//	}
// 
//	// ���� �迭�� ũ�⸦ ������ ����
//	int prevSize = arrSize;
//	
//	// x��ǥ (0�� ��, �� ĭ �з� ��µ�.)
//	int posX = -1; 
//	
//	// y��ǥ
//	int posY = 0;
//
//	// �迭�� ��ǥ�� �̵���Ű��, �̵������� �ٲ���
//	int move = 1;
//
//	// �迭�� ���� �־��� ����
//	int moveCount = 1;
//
//	// �迭�� ũ�⸸ŭ ����Ŭ�� ������
//	while (0 < arrSize)
//	{
//		// ù��° ��
//		for (int i = 0; i < arrSize; i++)
//		{
//			// x��ǥ�� ��ĭ�� �̵���Ŵ.
//			posX += move;
//
//			// �̵��� ��ǥ�� ���� �־���
//			arr[posY][posX] = moveCount;
//
//			// ��ǥ�� �̵��� �� ���� ����.
//			moveCount++;
//		}
//
//		// �迭�� ũ�⸸ŭ �̵��ϸ�, ������ �ٲٰ�, (arrSize - 1) ��ŭ �̵��ؾ��ϹǷ�
//		// �迭�� ũ�⸦ ��������.
//		arrSize--;
//
//		// ������ �ٲ� y��ǥ�� �̵���Ŵ.
//		for (int i = 0; i < arrSize; i++)
//		{
//			// y��ǥ�� ��ĭ�� �̵���Ŵ.
//			posY += move;
//
//			// �̵��� ��ǥ�� ���� �־���
//			arr[posY][posX] = moveCount;
//
//			// ��ǥ�� �̵��� ������ ����
//			moveCount++;
//		}
//		//ù��° ����Ŭ�� ������ �ݴ�� �̵��ؾ��ϹǷ� ��ȣ�� �ٲ���.
//		move *= -1;
//	}
//
// 
//
//	// ��� : �迭�� ũ�Ⱑ ���� ó���ο��� �پ����� ������, 
//	// �̸� �����ص� �迭�� ũ�⸦ ����Ͽ� ���.
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
