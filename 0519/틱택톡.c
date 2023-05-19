#include <stdio.h>
void BoardPrint(int(*board)[3], int(*playerX)[3], int(*playerO)[3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 1 && playerX[i][j] == 1)
			{
				printf("| %c ", 'X');
				continue;
			}

			if (board[i][j] == 1 && playerO[i][j] == 1)
			{
				printf("| %c ", 'O');
				continue;
			}
			printf("| %c ", '\0');

		}
		printf("|\n");
	}

	//printf("| %c | %c | %c |\n", '\0', '\0', '\0');
	//printf("| - | - | - |\n");
	//printf("| %c | %c | %c |\n", '\0', '\0', '\0');
	//printf("| - | - | - |\n");
	//printf("| %c | %c | %c |\n", '\0', '\0', '\0');

}


int CheckCount(int(*player)[3], int playerRow, int playerCol)
{

}

int main()
{
	int playerXrow = 0;
	int playerXcol = 0;
	int playerX[3][3] = { 0 };

	int playerOrow = 0;
	int playerOcol = 0;
	int playerO[3][3] = { 0 };

	int board[3][3] = { 0 };
	int count = 0;
	int playerTurn = 0;
	int emptyCount = 9;

	while (count < 2 && emptyCount >0)
	{
		playerTurn = 0;
		if (playerTurn == 0)	// X 차례
		{
			printf("Player X, 움직임을 입력하세요(행[0 - 2]과 열[0 - 2]) : ");
			scanf("%d %d", &playerXrow, &playerXcol);
		}

		//보드판 채우기 중복 검사 , 잘못된 입력
		if (board[playerXrow][playerXcol] == 1 || playerXrow > 2 || playerXcol > 2 || playerXrow < 0 || playerXcol < 0)
		{
			printf("잘못된 움직임! 다시 시도해주세요.\n");
			continue;
		}

		// 보드판 채우기
		board[playerXrow][playerXcol] = 1;
		playerX[playerXrow][playerXcol] = 1;

		// 빈칸
		emptyCount--;

		count = CheckCount(playerX, playerXrow, playerXcol);
		// 보드판 출력
		BoardPrint(board, playerX, playerO);

		count = 0;

		//턴넘김
		playerTurn++;
		while (count < 2 && playerTurn == 1 && emptyCount >0)
		{
			if (playerTurn == 1)	// O 차례
			{
				printf("Player O, 움직임을 입력하세요(행[0 - 2]과 열[0 - 2]) : ");
				scanf("%d %d", &playerXrow, &playerXcol);
			}

			//보드판 채우기 중복 검사 , 잘못된 입력
			if (board[playerXrow][playerXcol] == 1 || playerXrow > 2 || playerXcol > 2 || playerXrow < 0 || playerXcol < 0)
			{
				printf("잘못된 움직임! 다시 시도해주세요.\n");
				continue;
			}

			// 보드판 채우기
			board[playerOrow][playerOcol] = 1;
			playerO[playerOrow][playerOcol] = 1;


			// 빈칸
			emptyCount--;

			count = CheckCount(playerO, playerOrow, playerOcol);

			// 보드판 출력
			BoardPrint(board, playerX, playerO);

			count = 0;



			// 턴 종료
			playerTurn = 0;
		}



		//출력


	}
	printf("게임 종료");
	return 0;
}