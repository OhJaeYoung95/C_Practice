#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void GuessTheNumberNBat();

int main()
{
	GuessTheNumberNBat();
	return 0;
}
/*
* 2. 컴퓨터가 낸 숫자 맞추기 게임
0~20까지 뽑아낸다.
컴퓨터가 낸 숫자 외에는 플레이어가 입력할 수 없다. / 예외처리 0~20이외를 쓰면
플레이어는 소지금을 가지고 있음 . 만원
플레이어는 배팅할 수 있다.
Up & down
배팅액은 한판당 최소 1000원
배팅액 차감은 확률로
맞출경우 내가 배팅한 금액 x2 / 틀릴경우 틀릴때마다 배팅한 금액 차감.
내가 가진 소지금보다 배팅을 더할 수 없다.

*/

void GuessTheNumberNBat()
{
	int playerMaxMoney = 10000;
	int playerMoney = 10000;
	int playerBett = 0;
	int playerPickNum = 0;
	int temp = 5;

	while (playerMoney > 0)
	{
		// 컴퓨터 1~999까지 숫자 고르기
		srand((unsigned int)time(NULL));
		int computerPickNum = rand() % 999;

		//printf("컴퓨터 픽%d", computerPickNum);
		// 배팅액 설정
		printf("게임 시작!\n");
		printf("배팅액을 설정하세요 : ");
		scanf("%d", &playerBett);

		// 배팅액 조건 설정
		if (playerMoney < playerBett && playerBett <= 1000)
		{
			while (playerMoney < playerBett && playerBett <= 1000)
			{
				printf("배팅액을 다시 설정하세요 : ");
				scanf("%d", playerBett);
			}
		}

		// 정답 맞추기 전까지 반복실행
		while (playerPickNum != computerPickNum)
		{
			if (playerMoney < 0)
			{
				printf("플레이어 파산!\n");
				break;
			}

			// 플레이어 숫자 뽑기
			printf("--------------------------\n");
			printf("플레이어 숫자 뽑기 : ");
			scanf("%d", &playerPickNum);
			printf("플레이어가 뽑은 숫자 : %d \n", playerPickNum);

			// 플레이어가 범위 밖 숫자 선택시 재선택
			if (playerPickNum < 0 || playerPickNum > 999)
			{
				printf("잘못된 카드를 뽑았다\n");
				printf("카드를 1~999사이에서 재선택 해주세요\n");
				continue;
			}


			// 크리티컬 확률 설정
			int criticalBatMoney = rand() % temp;


			// 플레이어 숫자 와 컴퓨터 숫자 비교 
			if (playerPickNum > computerPickNum)
			{
				if (criticalBatMoney == 0)
				{
					printf("Down!\n");
					printf("크리티컬 발생!\n");
					playerMoney -= (playerBett * 2);
					printf("플레이어 소지금 : %d\n", playerMoney);
					temp = 5;
					continue;
				}
				playerMoney -= (playerBett / 2);
				printf("Down!\n");
				printf("플레이어 소지금 : %d\n", playerMoney);
				temp--;

			}
			else if (playerPickNum < computerPickNum)
			{
				if (criticalBatMoney == 0)
				{
					printf("Up!\n");
					printf("크리티컬 발생!\n");
					playerMoney -= (playerBett * 2);
					printf("플레이어 소지금 : %d\n", playerMoney);
					temp = 5;

					continue;
				}
				playerMoney -= (playerBett / 2);
				printf("Up!\n");
				printf("플레이어 소지금 : %d\n", playerMoney);
				temp--;
			}
			else
			{
				playerMoney += (playerBett * 2);
				printf("정답!\n");
				printf("플레이어 소지금 : %d\n", playerMoney);
				break;
			}
		}
	}
}