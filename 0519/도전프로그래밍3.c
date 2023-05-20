#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 문제1
void Print1(int(*arr)[4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}
void ArrayRotate(int(*arr)[4])
{
	printf("90도 회전\n");
	int temp[4][4] = { 0 };
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			temp[j][i] = arr[3 - i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = temp[i][j];
		}
	}

}
void Practice1()
{
	int arr[4][4] = { {1,2,3,4,},
	{5, 6, 7, 8},
	{9, 10, 11, 12},
	{13, 14, 15, 16} };
	Print1(arr);
	ArrayRotate(arr);
	Print1(arr);
	ArrayRotate(arr);
	Print1(arr);
	ArrayRotate(arr);
	Print1(arr);
}

// 문제2
void Print2(int(*arr)[10], int num)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}
void SnailSort(int(*arr)[10])
{
	int num = 0;
	int count = 1;
	int side = 0;
	int col = 0;
	int row = 0;
	printf("정수 입력 : ");
	scanf("%d", &num);

	while (side < num)
	{
		if (side % 2 == 0)
		{
			for (int i = side; i < num; i++)
			{
				arr[row][i-col] = count++;
			}
			col++;
			side++;
			//if (side == num - 1)
			//	break;

			for (int i = side; i < num; i++)
			{
				arr[side- row][num - col] = count++;
			}
			row++;

		}
		else if (side % 2 != 0)
		{
			for (int i = num - side; i >= 0; i--)
			{
				arr[num - row][i - side] = count++;
			}
			side++;
			for (int i = num - side; i >= 1; i--)
			{
				arr[i][col-1] = count++;
			}

		}

	}

	Print2(arr, num);
}
void Practice2()
{
	int arr[10][10] = { 0 };

	SnailSort(arr);
}

// 문제3
void Practice3()
{
	srand((unsigned int)time(NULL));
	printf("난수의 범위 0부터 %d까지\n", RAND_MAX & 99);
	for (int i = 0; i < 5; i++)
		printf("%d ", rand() % 100);
}

// 문제4
void Practice4()
{
	srand((unsigned int)time(NULL));
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;

	printf("주사위1 의 결과 : %d\n", dice1);
	printf("주사위2 의 결과 : %d\n", dice2);
}

// 문제5
void Practice5()
{
	// 플레이어 가위바위보
	int playerSelect = 0;

	// 컴퓨터 가위바위보
	int comSelect = 0;

	// 승패변수
	int win = 0;
	int lose = 0;
	int draw = 0;

	srand((unsigned int)time(NULL));
	while (lose < 1)
	{
		comSelect = rand() % 3 + 1;

		printf("바위는 1 가위는 2, 보는 3 : ");
		scanf("%d", &playerSelect);

		if (playerSelect < 1 || playerSelect >= 4)
			continue;
		switch (playerSelect - comSelect)
		{
		case 2:
			printf("당신은 보 선택, 컴퓨터는 바위 선택, 이겼습니다!\n");
			win++;
			break;
		case 1:
			printf("당신은 가위 선택, 컴퓨터는 바위 선택, 졌습니다!\n");
			lose++;
			break;
		case 0:
			if (playerSelect == 1)
				printf("당신은 바위 선택, 컴퓨터는 바위 선택, 비겼습니다!\n");
			else if (playerSelect == 2)
				printf("당신은 가위 선택, 컴퓨터는 가위 선택, 비겼습니다!\n");
			else if (playerSelect == 3)
				printf("당신은 보 선택, 컴퓨터는 보 선택, 비겼습니다!\n");
			draw++;
			break;
		case -1:
			printf("당신은 바위 선택, 컴퓨터는 가위 선택, 이겼습니다!\n");
			win++;
			break;
		case -2:
			printf("당신은 바위 선택, 컴퓨터는 보 선택, 졌습니다!\n");
			lose++;
			break;
		}
	}

	printf("게임의 결과 : %d승, %d무\n", win, draw);
}

// 문제6
void Practice6()
{
	int strike = 0;
	int ball = 0;

	int playerSelect[3] = { 0 };
	int tryNum = 0;

	srand((unsigned int)time(NULL));
	int comSelect[3] = { rand() % 10, rand() % 10, rand() % 10 };
	while (comSelect[0] == comSelect[1] ||
		comSelect[1] == comSelect[2] ||
		comSelect[0] == comSelect[2])
	{
		comSelect[1] = rand() % 10;
		comSelect[2] = rand() % 10;
	}
	while (strike < 3)
	{
		strike = 0;
		ball = 0;
		printf("플레이어 숫자 입력 : ");
		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &playerSelect[i]);
		}

		if (playerSelect[0] == playerSelect[1] ||
			playerSelect[1] == playerSelect[2] ||
			playerSelect[0] == playerSelect[2])
		{
			printf("잘못된 값 입력 : \n");
			continue;
		}

		//printf("컴퓨터 출력 %d %d %d", comSelect[0], comSelect[1], comSelect[2]);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (playerSelect[i] == comSelect[j] && i == j)
					strike++;
				else if (playerSelect[i] == comSelect[j])
					ball++;
			}
		}
		tryNum++;
		printf("%d번째 도전 결과 : %dStrike %dBall !!\n", tryNum, strike, ball);
	}



}

int main()
{
	Practice2();
	return 0;
}