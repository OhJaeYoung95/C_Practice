#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void BaseballGame();

int main()
{
	BaseballGame();
	return 0;
}

/* 종료 조건 : 10판 / 소지금 0원(배팅할 수 없는 경우)

3. 숫자야구 게임	(배열써야함)
컴퓨터는 0~9까지 랜덤한 세자리를 뽑는다. / int computer[3]
플레이어는 이 숫자를 맞춘다.
컴퓨터 0 1 2 / 플레이어 1 2 3 => 2ball
컴퓨터 3 5 7 / 플레이어 5 1 7 => 1strike 1ball

종료 : 3strike
이중포문?
*/

void BaseballGame()
{

	int ball = 0;
	int strike = 0;

	// 컴퓨터 공 세개 설정
	srand((unsigned int)time(NULL));
	int computerSelect[3] = { rand() % 10, rand() % 10, rand() % 10 };
	while (computerSelect[0] == computerSelect[1] ||
		computerSelect[1] == computerSelect[2] ||
		computerSelect[2] == computerSelect[0])
	{
		for (int i = 0; i < 2; i++)
		{
			computerSelect[i + 1] = rand() % 10;
		}
	}


	int player[3] = { 0 };

	// 게임 종료 조건
	while (strike < 3)
	{
		strike = 0;
		ball = 0;

		// 플레이어 숫자 입력
		printf("플레이어 숫자 세개 입력 :");
		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &player[i]);
		}

		if (player[0] == player[1] || player[1] == player[2] || player[2] == player[0])
		{
			printf("플레이어 숫자 재입력 (숫자 중복불가능):\n");
			continue;
		}

		// 게임 종료 조건 확인
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (player[i] == computerSelect[j] && i == j)
				{
					strike++;
				}
				else if (player[i] == computerSelect[j])
				{
					ball++;
				}
			}
		}
		printf("스트라이크 : %d 볼 : %d\n", strike, ball);
	}
	printf("게임 클리어\n");
}