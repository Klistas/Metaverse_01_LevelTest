
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

// Deck타입
// 1. 모든 덱은 카드가 중복되지 않아야 한다.
// Make() : 카드를 7장 뽑아서 덱을 구성한다. 
//			단, 카드가 충분치 않은 경우 만들어지지 못할 수 있다.
//			Deck decks[7]; decks.Make();
// 
// ToString() : 현재 덱의 카드를 표현하는 문자열을 만든다.	
//				카드가 없는 경우 "The Deck Is Empty" 메세지 반환.
// 


// 0 ~ 12 : 스
// 13 ~ 25 : 클
// 26 ~ 38 : 하
// 39 ~ 51 : 다
// 52 : 조



class Deck
{
public:

	Deck() = default;
	Deck(const Deck & other) = delete;
	Deck& operator=(const Deck& other) = delete;
	~Deck() = default;

	/// <summary>
	///  카드를 7장 뽑아서 덱을 구성한다.
	/// 카드는 중복되지 않아야 한다.
	/// </summary>
	/// <returns> 덱이 성공적으로 구성됐을 경우 true, 아니면 false </returns>
	bool Make()
	{
		
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

	string ToString(int cardIndex)
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

	void printCard(int playerCount)
	{
		_deck[7] = { 0 };
		Make(_deck);
		cout << "Player" << playerCount << " : ";
		for (int i = 0; i < 7; i++)
		{
			cout << ToString(_deck[i]) << " ";
		}
		cout << endl;
	}



private:
	int _deck[7] = {0};
	bool isUsedCard[53] = { false };



};





///// <summary>
///// 카드 7장을 뽑는다.
///// </summary>
//int* PickCard();
//
//
//
//
///// <summary>
/////  카드 7장 뽑기.
///// </summary>
///// <param name="deck">플레이어의 덱</param>
//void pickCard(int* deck)
//{
//	
//	// 중복되지 않게 카드를 뽑아야함.
//	// 카드는 정수 값.
//	srand(time(NULL));
//	for (int i = 0; i < 7; i++)
//	{
//		 
//		int card = 0;
//		 do
//		 {	
//			 card = rand() % 53 + 1;
//					 
//	     } while (isUsedCard[card]);
//		
//		deck[i] = card;
//		isUsedCard[card] = true;
//
//	}
//
//	
//}
//
//std::string ConvertToCardString(int cardIndex)
//{
//	std::stringstream ss;
//	int cardType = cardIndex / 13;
//	int cardNumber = cardIndex % 13;
//
//	static const string CARD_TYPE[] = { "♠", "♣", "♥", "◆" };
//	static const string CARD_NUMBER[] = { "A", "2", "3", "4", "5", "6" , "7", "8", "9" , "10", "J", "Q", "K" };
//
//		if (cardType == 4)
//		{
//			return "Joker";
//		}
//		
//		else
//		{
//			return CARD_TYPE[cardType] + CARD_NUMBER[cardNumber];
//		}
//
//
//}


int main()
{
	
	Deck deck;

	
	// 총 53장의 카드. -> 14개를 뽑아야함.
	// 두명의 플레이어에게 각각 7장을 배부.
	deck.printCard(1);
	deck.printCard(2);
	deck.printCard(3);
	deck.printCard(4);
	deck.printCard(5);
	



	return 0;
}