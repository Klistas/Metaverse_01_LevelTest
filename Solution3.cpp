#include <iostream>

using namespace std;

int main()
{
	// 5줄의 별 찍기
	for (int i = 0; i < 5; i++)
	{
		//5번째 줄에는 최대 9개의 별
		for (int j = 9; j > 0; j--)
		{
			// 2개씩 늘어나는 별.
			if (5 + i >= j && 5 - i <= j)
			{
			cout << "*";

			}
			
			else
			cout << " ";
		}
		cout << endl;
	}






	return 0;

}