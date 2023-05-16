#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
������
1. ī��� 52��
2. ��Ʈ ���̾� �����̵� Ŭ�ι� // ���� 4��
3. A (1)/ 2~10 / J Q K ( 11, 12, 13)

���� ��
����(PC)��2���� ī�带 �����ϰ� ����.
�����ٶ��� ������� ���;��Ѵ�.

�÷��̾ ī�� �������ʶ� ������ ���� ī�� �ΰ� ������ ���� ���;� �̱��.
���� ������ ���� ī�� �ΰ��� �ϳ��� ũ�Ⱑ ������ �й�
����
��Ʈ J 11 / ���̾� K 12 / Ŭ�ι� 12    //�й�
��Ʈ 1 / ���̾� 2 / ��Ʈ 3             // �¸�

���� �ý����� �ִ�. / ������ ���þ�
�¸��� ���ñ� �ι�
���д� ���ñ� ����

���� ��
����� ���ñ� 1/2�� ����

�� ���ӿ� �� ī�� 3���� ������ ������.
����ī�尡 3���� �ȵǰų� or ���� �� ���� ����
�ϼ� ǥ�� / ������ ǥ��
*/
void BetweenTwoCardsGame();
void DeckInit();
void Shuffle();
int SameCardShuffle();
void CardPrint();
void PlayerBetting();
void PlayerChoiceCard();
void PlayerCardShuffle();

// �÷��̾�
int playerMoney = 10000;
int bettingMoney = 0;
int playerCard = 0;
int dealChoice = 0;

// ī�� ��
int hart[13];		// 1~13
int diamond[13];
int spade[13];
int clover[13];

// ���� ��
int previousCard = 0;
int nextCard = 0;

int deckShuffle[52] = { 0 };
int deckCount = 52;
int gameCount = 1;


int main()
{
	printf("���� ����! \n");
	BetweenTwoCardsGame();
	return 0;
}

// ī�����
void BetweenTwoCardsGame()
{
	DeckInit();			// �� ����
	while (deckCount > 2 && playerMoney > 0)
	{
		printf("========================\n");
		printf("%d��° ��\n", gameCount);
		PlayerBetting();	// ���þ� ����
		Shuffle();				// ī�� ����
		PlayerChoiceCard();		// �÷��̾� ī�� ����
		deckCount = deckCount - 3;		// �Ǽ� ����
		gameCount++;
		printf("���� �м� :%d\n", deckCount);
	}

}

// �� ����
void DeckInit()
{
	// ī�� �� ���� 
	for (int i = 0; i < 13; i++)	// 		1��° ī�弼Ʈ : 1 ~ 13ī�弳��
	{
		hart[i] = ((i + 1) + (13*0));
	}
	for (int i = 0; i < 13; i++)	// 		2��° ī�弼Ʈ : 14 ~ 27ī�弳��
	{
		diamond[i] = ((i + 1) + (13 * 1));
	}
	for (int i = 0; i < 13; i++)	// 		3��° ī�弼Ʈ : 27 ~ 39ī�弳��
	{
		spade[i] = ((i + 1) +(13 * 2));
	}
	for (int i = 0; i < 13; i++)	// 		4��° ī�弼Ʈ : 40 ~ 52ī�弳��
	{
		clover[i] = ((i + 1) + (13 * 3));
	}
}


// ī�� ����
void Shuffle()
{
	// 1~52 ī�� ����
	srand((unsigned int)time(NULL));
	int cardShuffle1 = rand() % 52 + 1;
	int cardShuffle2 = rand() % 52 + 1;

	// ���� ī�� �̾Ҵ� ī�� ��  ����Լ���
	for (int i = 0; i < 52; i++)
	{
		cardShuffle1 == deckShuffle[i] ? SameCardShuffle(cardShuffle1) : cardShuffle1;
	}

	// ���� ī�� �̱� ����
	while (cardShuffle1 == cardShuffle2)
	{
		cardShuffle2 = rand() % 52 + 1;
	}
	// ���� ī�� �̾Ҵ� ī�� ��  ����Լ���
	for (int i = 0; i < 52; i++)
	{
		cardShuffle2 == deckShuffle[i] ? SameCardShuffle(cardShuffle2) : cardShuffle2;
	}

	// �̾Ҵ� ī�� ������ / deckShuffle[i] �� ���� �־ �ι� �ٽ� ���̰� �ϱ��
	for (int i = 0; i < 52; i++)
	{
		if (deckShuffle[i] != cardShuffle1 && deckShuffle[i] ==0)
		{
			deckShuffle[i] = cardShuffle1;
			previousCard = cardShuffle1;
			cardShuffle1 = 0;	// �̰� ���ϸ� ���ڰ� �ϳ� �ȳ���
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

	// ī�� ũ�� �� (��� ������� �ϱ� ���ؼ�)  // ��ºκ�
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

// �̾Ҵ� ī��� ���� ������ �ٽ� ����
int SameCardShuffle(int cardShuffle)
{
	// �������ִ� �κ�
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

// ī�� ���
void CardPrint(int cardNum)
{
	// ����κ� ��� 
	if (cardNum > 0 && cardNum < 14)
		printf("|��");
	else if (cardNum >= 14 && cardNum < 27)
		printf("|��");
	else if (cardNum >= 27 && cardNum < 40)
		printf("|��");
	else if (cardNum >= 40 && cardNum < 53)
		printf("|��");

	// ���ںκ� ���
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
			printf("%d| ", (cardNum % 13) + 1);		// ������±���
			break;
	}
}

void PlayerBetting()
{
	// ���þ� ����
	printf("���þ��� ������ �ּ��� : ");
	scanf("%d", &bettingMoney);
	while (bettingMoney > playerMoney)
	{
		printf("------------------------\n");
		printf("���þ��� �����ݺ��� Ů�ϴ� \n");
		printf("���þ��� �缳���� �ּ��� : ");
		scanf("%d", &bettingMoney);
	}
	while (bettingMoney <= 0)
	{
		printf("------------------------\n");
		printf("���þ��� ����� �Է����ּ��� \n");
		printf("���þ��� �缳���� �ּ��� : ");
		scanf("%d", &bettingMoney);
	}
}

// �÷��̾� ����
void PlayerChoiceCard()
{
	printf("�÷��̾� ���ýð� ��:1 / ���� :2  \n");
	scanf("%d", &dealChoice);

	while (dealChoice != 1 && dealChoice != 2)
	{
		printf("------------------------\n");
		printf("�缱�� ��:1 / ���� :2  \n");
		scanf("%d", &dealChoice);
	}

	if (dealChoice == 2)
	{
		printf("������ ���� : ���þ��� ����\n");
		playerMoney -= bettingMoney / 2;
		printf("�÷��̾� ���� ������ : %d\n", playerMoney);
		dealChoice = 0;
		return;
	}

	// �÷��̾� ī�� ����
	PlayerCardShuffle();

	// ī�� ũ�� �� (��� ������� �ϱ� ���ؼ�)  // ��ºκ�
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

	// �¸�
	if ((playerCard % 13 > previousCard % 13) && 
		(playerCard % 13 < nextCard % 13))
	{
		printf("�÷��̾� �¸�!!\n");
		printf("���þ� �ι� ȹ��! : %d\n", bettingMoney * 2);
		playerMoney += bettingMoney * 2;
		printf("�÷��̾� ���� ������ : %d\n", playerMoney);
	}
	// �й�
	else if(playerCard % 13 <= previousCard % 13)
	{
		printf("�÷��̾� �й�!!\n");
		printf("���þ� ����! : %d\n", bettingMoney);
		playerMoney -= bettingMoney;
		printf("�÷��̾� ���� ������ : %d\n", playerMoney);

		if (playerMoney <= 0)
		{
			printf("�÷��̾� �Ļ�!\n");
			printf("���� ����!\n");
		}
	}
	else if (playerCard % 13 >= nextCard % 13)
	{
		printf("�÷��̾� �й�!!\n");
		printf("���þ� ����! : %d\n", bettingMoney);
		playerMoney -= bettingMoney;
		printf("�÷��̾� ���� ������ : %d\n", playerMoney);

		if (playerMoney <= 0)
		{
			printf("�÷��̾� �Ļ�!\n");
			printf("���� ����!\n");
		}
	}
}

// �÷��̾� ī�� ����
void PlayerCardShuffle()
{
	srand((unsigned int)time(NULL));
	playerCard = rand() % 52 + 1;

	for (int i = 0; i < 53; i++)
	{
		if (playerCard == deckShuffle[i])
			playerCard = rand() % 52 + 1;
	}
	// �÷��̾� �� ��� �� ������
	for (int i = 0; i < 53; i++)
	{
		if (deckShuffle[i] != playerCard && deckShuffle[i] == 0)
		{
			deckShuffle[i] = playerCard;
			break;
		}
	}
}