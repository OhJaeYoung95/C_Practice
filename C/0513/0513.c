#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
월남뽕
1. 카드는 52장
2. 하트 다이아 스페이드 클로버 // 문양 4개
3. A (1)/ 2~10 / J Q K ( 11, 12, 13)

게임 룰
딜러(PC)가2개의 카드를 랜덤하게 공개.
보여줄때는 문양까지 나와야한다.

플레이어가 카드 오픈차례때 딜러가 뽑은 카드 두개 사이의 수가 나와야 이긴다.
만약 딜러가 뽑은 카드 두개중 하나와 크기가 같더라도 패배
예시
하트 J 11 / 다이아 K 12 / 클로버 12    //패배
하트 1 / 다이아 2 / 하트 3             // 승리

배팅 시스템이 있다. / 소지금 배팅액
승리는 베팅금 두배
실패는 베팅금 차감

베팅 후
포기시 베팅금 1/2배 차감

한 게임에 쓴 카드 3장은 덱에서 버린다.
남은카드가 3장이 안되거나 or 탕진 시 게임 종료
턴수 표기 / 소지금 표기
*/
void BetweenTwoCardsGame();
void DeckInit();
void Shuffle();
int SameCardShuffle();
void CardPrint();
void PlayerBetting();
void PlayerChoiceCard();
void PlayerCardShuffle();

// 플레이어
int playerMoney = 10000;
int bettingMoney = 0;
int playerCard = 0;
int dealChoice = 0;

// 카드 덱
int hart[13];		// 1~13
int diamond[13];
int spade[13];
int clover[13];

// 셔플 덱
int previousCard = 0;
int nextCard = 0;

int deckShuffle[52] = { 0 };
int deckCount = 52;
int gameCount = 1;


int main()
{
	printf("게임 시작! \n");
	BetweenTwoCardsGame();
	return 0;
}

// 카드게임
void BetweenTwoCardsGame()
{
	DeckInit();			// 덱 설정
	while (deckCount > 2 && playerMoney > 0)
	{
		printf("========================\n");
		printf("%d번째 판\n", gameCount);
		PlayerBetting();	// 배팅액 설정
		Shuffle();				// 카드 섞기
		PlayerChoiceCard();		// 플레이어 카드 선택
		deckCount = deckCount - 3;		// 판수 조절
		gameCount++;
		printf("남은 패수 :%d\n", deckCount);
	}

}

// 덱 설정
void DeckInit()
{
	// 카드 값 설정 
	for (int i = 0; i < 13; i++)	// 		1번째 카드세트 : 1 ~ 13카드설정
	{
		hart[i] = ((i + 1) + (13*0));
	}
	for (int i = 0; i < 13; i++)	// 		2번째 카드세트 : 14 ~ 27카드설정
	{
		diamond[i] = ((i + 1) + (13 * 1));
	}
	for (int i = 0; i < 13; i++)	// 		3번째 카드세트 : 27 ~ 39카드설정
	{
		spade[i] = ((i + 1) +(13 * 2));
	}
	for (int i = 0; i < 13; i++)	// 		4번째 카드세트 : 40 ~ 52카드설정
	{
		clover[i] = ((i + 1) + (13 * 3));
	}
}


// 카드 섞기
void Shuffle()
{
	// 1~52 카드 셔플
	srand((unsigned int)time(NULL));
	int cardShuffle1 = rand() % 52 + 1;
	int cardShuffle2 = rand() % 52 + 1;

	// 뽑은 카드 뽑았던 카드 비교  재귀함수로
	for (int i = 0; i < 52; i++)
	{
		cardShuffle1 == deckShuffle[i] ? SameCardShuffle(cardShuffle1) : cardShuffle1;
	}

	// 같은 카드 뽑기 방지
	while (cardShuffle1 == cardShuffle2)
	{
		cardShuffle2 = rand() % 52 + 1;
	}
	// 뽑은 카드 뽑았던 카드 비교  재귀함수로
	for (int i = 0; i < 52; i++)
	{
		cardShuffle2 == deckShuffle[i] ? SameCardShuffle(cardShuffle2) : cardShuffle2;
	}

	// 뽑았던 카드 버리기 / deckShuffle[i] 에 값을 넣어서 두번 다시 못뽑게 하기용
	for (int i = 0; i < 52; i++)
	{
		if (deckShuffle[i] != cardShuffle1 && deckShuffle[i] ==0)
		{
			deckShuffle[i] = cardShuffle1;
			previousCard = cardShuffle1;
			cardShuffle1 = 0;	// 이걸 안하면 문자가 하나 안나옴
			continue;
		}

		if (deckShuffle[i] != cardShuffle2 && deckShuffle[i] == 0)
		{
			deckShuffle[i] = cardShuffle2;
			nextCard = cardShuffle2;
			cardShuffle2 = 0;
			break;
		}
	}

	// 카드 크기 비교 (출력 순서대로 하기 위해서)  // 출력부분
	if ((previousCard %13) < (nextCard %13))
	{
		CardPrint(previousCard);
		CardPrint(nextCard);
		printf("\n");
	}
	else if ((previousCard % 13) > (nextCard % 13))
	{
		CardPrint(nextCard);
		CardPrint(previousCard);
		printf("\n");
	}

}

// 뽑았던 카드와 비교해 같으면 다시 셔플
int SameCardShuffle(int cardShuffle)
{
	// 제한해주는 부분
	if (cardShuffle == 53)
		cardShuffle = 1;
	for (int i = 0; i < 52; i++) 
	{
		if (deckShuffle[i] == 0)
			continue;
		cardShuffle == deckShuffle[i] ? SameCardShuffle(cardShuffle + 1) : cardShuffle;
	}
	return cardShuffle;
}

// 카드 출력
void CardPrint(int cardNum)
{
	// 문양부분 출력 
	if (cardNum > 0 && cardNum < 14)
		printf("|♥");
	else if (cardNum >= 14 && cardNum < 27)
		printf("|◆");
	else if (cardNum >= 27 && cardNum < 40)
		printf("|♠");
	else if (cardNum >= 40 && cardNum < 53)
		printf("|♣");

	// 숫자부분 출력
	switch ((cardNum % 13) + 1)
	{
		case 1:
			printf("A| ");
			break;
		case 11:
			printf("J| ");
			break;
		case 12:
			printf("Q| ");
			break;
		case 13:
			printf("K| ");
			break;
		default :
			printf("%d| ", (cardNum % 13) + 1);		// 숫자출력구간
			break;
	}
}

void PlayerBetting()
{
	// 배팅액 설정
	printf("배팅액을 설정해 주세요 : ");
	scanf("%d", &bettingMoney);
	while (bettingMoney > playerMoney)
	{
		printf("------------------------\n");
		printf("배팅액이 소지금보다 큽니다 \n");
		printf("배팅액을 재설정해 주세요 : ");
		scanf("%d", &bettingMoney);
	}
	while (bettingMoney <= 0)
	{
		printf("------------------------\n");
		printf("배팅액을 제대로 입력해주세요 \n");
		printf("배팅액을 재설정해 주세요 : ");
		scanf("%d", &bettingMoney);
	}
}

// 플레이어 선택
void PlayerChoiceCard()
{
	printf("플레이어 선택시간 콜:1 / 다이 :2  \n");
	scanf("%d", &dealChoice);

	while (dealChoice != 1 && dealChoice != 2)
	{
		printf("------------------------\n");
		printf("재선택 콜:1 / 다이 :2  \n");
		scanf("%d", &dealChoice);
	}

	if (dealChoice == 2)
	{
		printf("소지금 차감 : 배팅액의 절반\n");
		playerMoney -= bettingMoney / 2;
		printf("플레이어 현재 소지금 : %d\n", playerMoney);
		dealChoice = 0;
		return;
	}

	// 플레이어 카드 셔플
	PlayerCardShuffle();

	// 카드 크기 비교 (출력 순서대로 하기 위해서)  // 출력부분
	if ((previousCard % 13) < (nextCard % 13))
	{
		CardPrint(previousCard);
		CardPrint(playerCard);
		CardPrint(nextCard);
		printf("\n");
	}
	else if ((previousCard % 13) > (nextCard % 13))
	{
		int temp = previousCard;
		previousCard = nextCard;
		nextCard = temp;

		CardPrint(previousCard);
		CardPrint(playerCard);
		CardPrint(nextCard);
		printf("\n");
	}

	// 승리
	if ((playerCard % 13 > previousCard % 13) && 
		(playerCard % 13 < nextCard % 13))
	{
		printf("플레이어 승리!!\n");
		printf("배팅액 두배 획득! : %d\n", bettingMoney * 2);
		playerMoney += bettingMoney * 2;
		printf("플레이어 현재 소지금 : %d\n", playerMoney);
	}
	// 패배
	else if(playerCard % 13 <= previousCard % 13)
	{
		printf("플레이어 패배!!\n");
		printf("배팅액 차감! : %d\n", bettingMoney);
		playerMoney -= bettingMoney;
		printf("플레이어 현재 소지금 : %d\n", playerMoney);

		if (playerMoney <= 0)
		{
			printf("플레이어 파산!\n");
			printf("게임 종료!\n");
		}
	}
	else if (playerCard % 13 >= nextCard % 13)
	{
		printf("플레이어 패배!!\n");
		printf("배팅액 차감! : %d\n", bettingMoney);
		playerMoney -= bettingMoney;
		printf("플레이어 현재 소지금 : %d\n", playerMoney);

		if (playerMoney <= 0)
		{
			printf("플레이어 파산!\n");
			printf("게임 종료!\n");
		}
	}
}

// 플레이어 카드 셔플
void PlayerCardShuffle()
{
	srand((unsigned int)time(NULL));
	playerCard = rand() % 52 + 1;

	for (int i = 0; i < 53; i++)
	{
		if (playerCard == deckShuffle[i])
			playerCard = rand() % 52 + 1;
	}
	// 플레이어 덱 사용 후 버리기
	for (int i = 0; i < 53; i++)
	{
		if (deckShuffle[i] != playerCard && deckShuffle[i] == 0)
		{
			deckShuffle[i] = playerCard;
			break;
		}
	}
}