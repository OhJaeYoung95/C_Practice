#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RockPaperScissors();

int main()
{
	RockPaperScissors();
	return 0;
}

/*
1. 가위바위보 게임
플레이어와 컴퓨터가 존재함. / 입력 필요 / 난수 2개
10판만 할 수 있다. for문 / 종료조건 : 10판
*/

void RockPaperScissors()
{
	int playerSelect = 0;
	int playerWin = 0;
	int computerWin = 0;
	int draw = 0;
	int playTryNum = 1;

	while (playTryNum <= 10)
	{

		// 게임시작
		printf("-----------------------------------------------------\n");
		printf("%d번째 가위바위보 시작! \n", playTryNum
		);
		printf("%d : 가위, %d : 바위, %d : 보\n", 0, 1, 2);

		// 플레이어 가위바위보 하기
		printf("플레이어 입력 :");
		scanf("%d", &playerSelect);

		// 플레이어 입력값 오류 다시하기
		if (playerSelect < 0 || playerSelect > 2)
		{
			printf("잘못된 수 입력\n");
			printf("다시 입력하시오\n");
			continue;
		}

		// 컴퓨터가 플레이어 가위바위보 정보 띄우기
		srand((unsigned int)time(NULL));
		int computerSelect = rand() % 3;
		if (playerSelect == 0)
			printf("플레이어 : 가위\n");
		else if (playerSelect == 1)
			printf("플레이어 : 바위\n");
		else if (playerSelect == 2)
			printf("플레이어 : 보\n");
		if (computerSelect == 0)
			printf("컴퓨터 : 가위\n");
		else if (computerSelect == 1)
			printf("컴퓨터 : 바위\n");
		else if (computerSelect == 2)
			printf("컴퓨터 : 보\n");

		// 게임결과
		// 비겼을때
		if (playerSelect == computerSelect)
		{
			printf("비겼음");
			draw++;
			printf("플레이어가 이긴 횟수 : %d / 컴퓨터가 이긴 횟수 : %d 비긴 횟수 : %d\n", playerWin, computerWin, draw);
			playTryNum++;
		}

		// 플레이어 승리
		if ((playerSelect == 0 && computerSelect == 2) ||
			(playerSelect == 1 && computerSelect == 0) ||
			(playerSelect == 2 && computerSelect == 1))
		{
			printf("플레이어 승리\n");
			playerWin++;
			printf("플레이어가 이긴 횟수 : %d / 컴퓨터가 이긴 횟수 : %d 비긴 횟수 : %d\n", playerWin, computerWin, draw);
			playTryNum++;
			continue;
		}

		// 컴퓨터 승리
		if ((computerSelect == 0 && playerSelect == 2) ||
			(computerSelect == 1 && playerSelect == 0) ||
			(computerSelect == 2 && playerSelect == 1))
		{
			printf("컴퓨터 승리\n");
			computerWin++;
			printf("플레이어가 이긴 횟수 : %d / 컴퓨터가 이긴 횟수 : %d 비긴 횟수 : %d\n", playerWin, computerWin, draw);
			playTryNum++;
			continue;
		}
	}
}