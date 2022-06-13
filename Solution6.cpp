
/*
6.	Joker�� ������ 53���� ī�带 ���� ��, �� ���� �÷��̾�� 7�徿�� ī�带 ����ϴ� ���α׷��� ����ÿ�.
A.�������� �� ���� ��ȣ + ��ȣ �� ���� A, 2 ~ 10, J, Q, K ���� ī�� ����
B.��¿���)	Player 1 : ��3, Joker, ��A, ��J, ��1, ��10, ��4
Player 2 : ��6, ��2, ��5, ��Q, ��K, ��2, ��3 

ī�带 �� �迭�� �����ϰ�, �������� �÷��̾� �迭�� ����, �ߺ� ó��. 
*/

#include <iostream>
#include <string>
#include <time.h>
#include <sstream>

using namespace std;





// 0 ~ 12 : ��
// 13 ~ 25 : Ŭ
// 26 ~ 38 : ��
// 39 ~ 51 : ��
// 52 : ��
bool isUsedCard[53] = { false };




/// <summary>
/// ī�� 7���� �̴´�.
/// </summary>
int* PickCard();




/// <summary>
///  ī�� 7�� �̱�.
/// </summary>
/// <param name="deck">�÷��̾��� ��</param>
void pickCard(int* deck)
{
	
	// �ߺ����� �ʰ� ī�带 �̾ƾ���.
	// ī��� ���� ��.
	srand(time(NULL));
	for (int i = 0; i < 7; i++)
	{
		 
		int card = 0;
		 do
		 {	
			 card = rand() % 53 + 1;
					 
	     } while (isUsedCard[card]);
		
		deck[i] = card;
		isUsedCard[card] = true;

	}

	
}

std::string ConvertToCardString(int cardIndex)
{
	std::stringstream ss;
	int cardType = cardIndex / 13;
	int cardNumber = cardIndex % 13;

	static const string CARD_TYPE[] = { "��", "��", "��", "��" };
	static const string CARD_NUMBER[] = { "A", "2", "3", "4", "5", "6" , "7", "8", "9" , "10", "J", "Q", "K" };

		if (cardType == 4)
		{
			return "Joker";
		}
		
		else
		{
			return CARD_TYPE[cardType] + CARD_NUMBER[cardNumber];
		}


}


int main()
{
	
	// �� 53���� ī��. -> 14���� �̾ƾ���.
	// �θ��� �÷��̾�� ���� 7���� ���.
	int player1Deck[7] = { 0 };
	pickCard(player1Deck);

	for (int i = 0; i < 7; i++)
	{
		cout << ConvertToCardString(player1Deck[i]) << " ";
	}
	cout << endl;
	
	int player2Deck[7] = { 0 };
	pickCard(player2Deck);

	for (int i = 0; i < 7; i++)
	{
		cout << ConvertToCardString(player2Deck[i]) << " ";
	}
	cout << endl;


	return 0;
}