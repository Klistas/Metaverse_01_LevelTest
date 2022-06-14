#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <iostream>

/*	
로또 번호 생성기를 구현 하시오.
A.	최대 번호값과 생성 숫자 개수를 입력하면 해당 조건 내에서 중복되지 않는 숫자를 출력하는 로또 번호 생성기를 구현.
B.	최대값 : 60, 생성숫자 : 10 을 입력하면 1 ~ 60 사이의 중복되지 않는 숫자 10개를 생성한다.

*/

//동적 할당의 문제점. (메모리를 수동으로 관리할 때의 문제점)
// 1. 할당은 했는데 해제를 안했다. -> 메모리 누수.(Memory Leak)
// 2. 이미 해제한 메모리에 대해 또 해제 -> 이중 해제.(Double Free)
//    - 이미 해제한 메모리를 가리키는 포인터 -> 댕글링 포인터(Dangling Pointer)
// 3. 너무 빨리 해제했다. -> 조기 해제(Premature Free)


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
	/// 데이터를 지운다.
	/// </summary>
	void Clear()
	{
		_digitCount = 0;
	}


	/// <summary>
	/// 로또 번호를 생성한다. 이미 생성된 번호가 있다면 지우고 새로 만든다.
	/// </summary>
	/// <param name="maxValue">최대 번호값</param>
	/// <param name="digitCount">생성 숫자 개수</param>
	void Make(int maxValue, int digitCount)
	{
		// digitCount : [1, 100]
		// 1. digitCount가 최소값(1) 보다 작을 때.
		// 2. digitCount가 최대값(100) 보다 클 때.
		// 3. digitCount가 최대값과 최소값의 사이에 있을 때.
		digitCount = max(1, min(digitCount,MAX_DIGIT_COUNT));
	
		// min(a,b) 는 a와 b중에서 작은 수를 반환
		// max(a,b) 는 a와 b중에서 큰 수를 반환.
		Clear();

		// 랜덤 시드 생성
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

	cout << "최대 번호 값을 입력하세요 : ";
	int maxValue;
	cin >> maxValue;
	cout << "생성할 숫자의 개수를 입력하세요 : ";
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
//	/// 데이터를 지운다.
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
//	/// 로또 번호를 생성한다. 이미 생성된 번호가 있다면 지우고 새로 만든다.
//	/// </summary>
//	/// <param name="maxValue">최대 번호값</param>
//	/// <param name="digitCount">생성 숫자 개수</param>
//	void Make(int maxValue, int digitCount)
//	{
//
//		Clear();
//
//		//저장할 배열 생성
//		_lotto = new int[digitCount];
//		
//		// 랜덤 시드 생성
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
//	cout << "최대 번호 값을 입력하세요 : ";
//	int maxValue;
//	cin >> maxValue;
//	cout << "생성할 숫자의 개수를 입력하세요 : ";
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




