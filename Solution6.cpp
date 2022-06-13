
/*
6.	Joker를 포함한 53장의 카드를 섞은 후, 두 명의 플레이어에게 7장씩의 카드를 배분하는 프로그램을 만드시오.
A.♠♣♥◆ 네 개의 기호 + 기호 별 각각 A, 2 ~ 10, J, Q, K 값의 카드 존재
B.출력예시)	Player 1 : ♥3, Joker, ♣A, ♣J, ◆1, ◆10, ♠4
Player 2 : ♥6, ◆2, ◆5, ♠Q, ♠K, ♣2, ♣3 

카드를 덱 배열에 저장하고, 랜덤으로 플레이어 배열로 나눔, 중복 처리. 
*/

#include <iostream>
#include <string>
#include <time.h>
#include <sstream>

using namespace std;





// 0 ~ 12 : 스
// 13 ~ 25 : 클
// 26 ~ 38 : 하
// 39 ~ 51 : 다
// 52 : 조
bool isUsedCard[53] = { false };




/// <summary>
/// 카드 7장을 뽑는다.
/// </summary>
int* PickCard();




/// <summary>
///  카드 7장 뽑기.
/// </summary>
/// <param name="deck">플레이어의 덱</param>
void pickCard(int* deck)
{
	
	// 중복되지 않게 카드를 뽑아야함.
	// 카드는 정수 값.
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

	static const string CARD_TYPE[] = { "♠", "♣", "♥", "◆" };
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
	
	// 총 53장의 카드. -> 14개를 뽑아야함.
	// 두명의 플레이어에게 각각 7장을 배부.
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