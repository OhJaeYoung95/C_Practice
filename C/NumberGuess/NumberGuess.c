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
* 2. ��ǻ�Ͱ� �� ���� ���߱� ����
0~20���� �̾Ƴ���.
��ǻ�Ͱ� �� ���� �ܿ��� �÷��̾ �Է��� �� ����. / ����ó�� 0~20�ܸ̿� ����
�÷��̾�� �������� ������ ���� . ����
�÷��̾�� ������ �� �ִ�.
Up & down
���þ��� ���Ǵ� �ּ� 1000��
���þ� ������ Ȯ����
������ ���� ������ �ݾ� x2 / Ʋ����� Ʋ�������� ������ �ݾ� ����.
���� ���� �����ݺ��� ������ ���� �� ����.

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
		// ��ǻ�� 1~999���� ���� ����
		srand((unsigned int)time(NULL));
		int computerPickNum = rand() % 999;

		//printf("��ǻ�� ��%d", computerPickNum);
		// ���þ� ����
		printf("���� ����!\n");
		printf("���þ��� �����ϼ��� : ");
		scanf("%d", &playerBett);

		// ���þ� ���� ����
		if (playerMoney < playerBett && playerBett <= 1000)
		{
			while (playerMoney < playerBett && playerBett <= 1000)
			{
				printf("���þ��� �ٽ� �����ϼ��� : ");
				scanf("%d", playerBett);
			}
		}

		// ���� ���߱� ������ �ݺ�����
		while (playerPickNum != computerPickNum)
		{
			if (playerMoney < 0)
			{
				printf("�÷��̾� �Ļ�!\n");
				break;
			}

			// �÷��̾� ���� �̱�
			printf("--------------------------\n");
			printf("�÷��̾� ���� �̱� : ");
			scanf("%d", &playerPickNum);
			printf("�÷��̾ ���� ���� : %d \n", playerPickNum);

			// �÷��̾ ���� �� ���� ���ý� �缱��
			if (playerPickNum < 0 || playerPickNum > 999)
			{
				printf("�߸��� ī�带 �̾Ҵ�\n");
				printf("ī�带 1~999���̿��� �缱�� ���ּ���\n");
				continue;
			}


			// ũ��Ƽ�� Ȯ�� ����
			int criticalBatMoney = rand() % temp;


			// �÷��̾� ���� �� ��ǻ�� ���� �� 
			if (playerPickNum > computerPickNum)
			{
				if (criticalBatMoney == 0)
				{
					printf("Down!\n");
					printf("ũ��Ƽ�� �߻�!\n");
					playerMoney -= (playerBett * 2);
					printf("�÷��̾� ������ : %d\n", playerMoney);
					temp = 5;
					continue;
				}
				playerMoney -= (playerBett / 2);
				printf("Down!\n");
				printf("�÷��̾� ������ : %d\n", playerMoney);
				temp--;

			}
			else if (playerPickNum < computerPickNum)
			{
				if (criticalBatMoney == 0)
				{
					printf("Up!\n");
					printf("ũ��Ƽ�� �߻�!\n");
					playerMoney -= (playerBett * 2);
					printf("�÷��̾� ������ : %d\n", playerMoney);
					temp = 5;

					continue;
				}
				playerMoney -= (playerBett / 2);
				printf("Up!\n");
				printf("�÷��̾� ������ : %d\n", playerMoney);
				temp--;
			}
			else
			{
				playerMoney += (playerBett * 2);
				printf("����!\n");
				printf("�÷��̾� ������ : %d\n", playerMoney);
				break;
			}
		}
	}
}