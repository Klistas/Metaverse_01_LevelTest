#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <iostream>

/*	
�ζ� ��ȣ �����⸦ ���� �Ͻÿ�.
A.	�ִ� ��ȣ���� ���� ���� ������ �Է��ϸ� �ش� ���� ������ �ߺ����� �ʴ� ���ڸ� ����ϴ� �ζ� ��ȣ �����⸦ ����.
B.	�ִ밪 : 60, �������� : 10 �� �Է��ϸ� 1 ~ 60 ������ �ߺ����� �ʴ� ���� 10���� �����Ѵ�.

*/

//���� �Ҵ��� ������. (�޸𸮸� �������� ������ ���� ������)
// 1. �Ҵ��� �ߴµ� ������ ���ߴ�. -> �޸� ����.(Memory Leak)
// 2. �̹� ������ �޸𸮿� ���� �� ���� -> ���� ����.(Double Free)
//    - �̹� ������ �޸𸮸� ����Ű�� ������ -> ��۸� ������(Dangling Pointer)
// 3. �ʹ� ���� �����ߴ�. -> ���� ����(Premature Free)


using namespace std;



class LimitedLotto
{
	static const int MAX_DIGIT_COUNT = 100;

public:
	LimitedLotto() = default;
	LimitedLotto(const LimitedLotto& other) = delete;
	LimitedLotto& operator=(const LimitedLotto& other) = delete;
	~LimitedLotto()
	{
		Clear();
	}


	/// <summary>
	/// �����͸� �����.
	/// </summary>
	void Clear()
	{
		_digitCount = 0;
	}


	/// <summary>
	/// �ζ� ��ȣ�� �����Ѵ�. �̹� ������ ��ȣ�� �ִٸ� ����� ���� �����.
	/// </summary>
	/// <param name="maxValue">�ִ� ��ȣ��</param>
	/// <param name="digitCount">���� ���� ����</param>
	void Make(int maxValue, int digitCount)
	{
		// digitCount : [1, 100]
		// 1. digitCount�� �ּҰ�(1) ���� ���� ��.
		// 2. digitCount�� �ִ밪(100) ���� Ŭ ��.
		// 3. digitCount�� �ִ밪�� �ּҰ��� ���̿� ���� ��.
		digitCount = max(1, min(digitCount,MAX_DIGIT_COUNT));
	
		// min(a,b) �� a�� b�߿��� ���� ���� ��ȯ
		// max(a,b) �� a�� b�߿��� ū ���� ��ȯ.
		Clear();

		// ���� �õ� ����
		srand(time(NULL));

		_digitCount = digitCount;

		for (int curPos = 0; curPos < digitCount; curPos++)
		{
			int candidate = 0;

			_lotto[curPos] = rand() % digitCount + 1;

			bool isExist = false;

			for (int i = 0; i < digitCount; i++)
			{
				candidate = _lotto[curPos];
				isExist = false;
				do
				{
					if (_lotto[curPos] == _lotto[i])
					{
						isExist = true;
						_lotto[curPos] = rand() % digitCount + 1;
						candidate = _lotto[curPos];
						break;
					}
				} while (isExist);
			}

			_lotto[curPos] = candidate;
			isExist = true;
			printf("%d \n", _lotto[curPos]);
		}


	}
	void Print()
	{
		for (int i = 0; i < _digitCount; i++)
		{
			cout << _lotto[i] << " ";
		}
		cout << endl;
	}




private:
	int _lotto[MAX_DIGIT_COUNT] = { 0 };
	int  _digitCount = 0;
};







int main(void)
{

	cout << "�ִ� ��ȣ ���� �Է��ϼ��� : ";
	int maxValue;
	cin >> maxValue;
	cout << "������ ������ ������ �Է��ϼ��� : ";
	int digitCount;
	cin >> digitCount;

	LimitedLotto lotto;
	lotto.Make(maxValue, digitCount);
	lotto.Print();

	return 0;

}
















//
//class Lotto
//{
//public :	
//	Lotto() = default;
//	Lotto(const Lotto& other) = delete;
//	Lotto& operator=(const Lotto& other) = delete;
//	~Lotto()
//	{
//		Clear();
//	}
//
//
//	/// <summary>
//	/// �����͸� �����.
//	/// </summary>
//	void Clear()
//	{
//		delete[] _lotto;
//		_lotto = nullptr;
//
//		_digitCount = 0;
//	}
//
//
//	/// <summary>
//	/// �ζ� ��ȣ�� �����Ѵ�. �̹� ������ ��ȣ�� �ִٸ� ����� ���� �����.
//	/// </summary>
//	/// <param name="maxValue">�ִ� ��ȣ��</param>
//	/// <param name="digitCount">���� ���� ����</param>
//	void Make(int maxValue, int digitCount)
//	{
//
//		Clear();
//
//		//������ �迭 ����
//		_lotto = new int[digitCount];
//		
//		// ���� �õ� ����
//		srand(time(NULL));
//			
//			
//		for (int curPos = 0; curPos < digitCount; curPos++)
//		{
//			int candidate = 0;
//			
//			_lotto[curPos] = rand() % digitCount + 1;
//
//			bool isExist = false;
//
//			do
//			{
//			candidate = _lotto[curPos];
//			isExist = false;
//			for (int i = 0; i < digitCount; i++)
//			{
//					if (_lotto[curPos] == _lotto[i])
//					{
//						isExist = true;

//						break;
//					}
//				} while (isExist);
//			}		
//
//			_lotto[curPos] = candidate;
//			printf("%d \n", _lotto[curPos]);
//		}
//
//
//	}
//	void Print()
//	{
//		for (int i = 0; i < _digitCount; i++)
//		{
//			cout << _lotto[i] << " ";
//		}
//		cout << endl;
//	}
//
//
//
//
//private :
//	int* _lotto = nullptr;
//	int  _digitCount = 0;
//};
//
//
//
//
//
//
//
//int main(void)
//{
//
//	cout << "�ִ� ��ȣ ���� �Է��ϼ��� : ";
//	int maxValue;
//	cin >> maxValue;
//	cout << "������ ������ ������ �Է��ϼ��� : ";
//	int digitCount;
//	cin >> digitCount;
//
//	Lotto lotto;
//	lotto.Make(maxValue, digitCount);
//	lotto.Print();
//
//	return 0;
//
//}




