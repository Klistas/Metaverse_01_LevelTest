#include <iostream>

using namespace std;

int main()
{
	// 5���� �� ���
	for (int i = 0; i < 5; i++)
	{
		//5��° �ٿ��� �ִ� 9���� ��
		for (int j = 9; j > 0; j--)
		{
			// 2���� �þ�� ��.
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