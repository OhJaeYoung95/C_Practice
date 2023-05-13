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
1. ���������� ����
�÷��̾�� ��ǻ�Ͱ� ������. / �Է� �ʿ� / ���� 2��
10�Ǹ� �� �� �ִ�. for�� / �������� : 10��
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

		// ���ӽ���
		printf("-----------------------------------------------------\n");
		printf("%d��° ���������� ����! \n", playTryNum
		);
		printf("%d : ����, %d : ����, %d : ��\n", 0, 1, 2);

		// �÷��̾� ���������� �ϱ�
		printf("�÷��̾� �Է� :");
		scanf("%d", &playerSelect);

		// �÷��̾� �Է°� ���� �ٽ��ϱ�
		if (playerSelect < 0 || playerSelect > 2)
		{
			printf("�߸��� �� �Է�\n");
			printf("�ٽ� �Է��Ͻÿ�\n");
			continue;
		}

		// ��ǻ�Ͱ� �÷��̾� ���������� ���� ����
		srand((unsigned int)time(NULL));
		int computerSelect = rand() % 3;
		if (playerSelect == 0)
			printf("�÷��̾� : ����\n");
		else if (playerSelect == 1)
			printf("�÷��̾� : ����\n");
		else if (playerSelect == 2)
			printf("�÷��̾� : ��\n");
		if (computerSelect == 0)
			printf("��ǻ�� : ����\n");
		else if (computerSelect == 1)
			printf("��ǻ�� : ����\n");
		else if (computerSelect == 2)
			printf("��ǻ�� : ��\n");

		// ���Ӱ��
		// �������
		if (playerSelect == computerSelect)
		{
			printf("�����");
			draw++;
			printf("�÷��̾ �̱� Ƚ�� : %d / ��ǻ�Ͱ� �̱� Ƚ�� : %d ��� Ƚ�� : %d\n", playerWin, computerWin, draw);
			playTryNum++;
		}

		// �÷��̾� �¸�
		if ((playerSelect == 0 && computerSelect == 2) ||
			(playerSelect == 1 && computerSelect == 0) ||
			(playerSelect == 2 && computerSelect == 1))
		{
			printf("�÷��̾� �¸�\n");
			playerWin++;
			printf("�÷��̾ �̱� Ƚ�� : %d / ��ǻ�Ͱ� �̱� Ƚ�� : %d ��� Ƚ�� : %d\n", playerWin, computerWin, draw);
			playTryNum++;
			continue;
		}

		// ��ǻ�� �¸�
		if ((computerSelect == 0 && playerSelect == 2) ||
			(computerSelect == 1 && playerSelect == 0) ||
			(computerSelect == 2 && playerSelect == 1))
		{
			printf("��ǻ�� �¸�\n");
			computerWin++;
			printf("�÷��̾ �̱� Ƚ�� : %d / ��ǻ�Ͱ� �̱� Ƚ�� : %d ��� Ƚ�� : %d\n", playerWin, computerWin, draw);
			playTryNum++;
			continue;
		}
	}
}