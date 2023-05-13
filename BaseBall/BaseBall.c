#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void BaseballGame();

int main()
{
	BaseballGame();
	return 0;
}

/* ���� ���� : 10�� / ������ 0��(������ �� ���� ���)

3. ���ھ߱� ����	(�迭�����)
��ǻ�ʹ� 0~9���� ������ ���ڸ��� �̴´�. / int computer[3]
�÷��̾�� �� ���ڸ� �����.
��ǻ�� 0 1 2 / �÷��̾� 1 2 3 => 2ball
��ǻ�� 3 5 7 / �÷��̾� 5 1 7 => 1strike 1ball

���� : 3strike
��������?
*/

void BaseballGame()
{

	int ball = 0;
	int strike = 0;

	// ��ǻ�� �� ���� ����
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

	// ���� ���� ����
	while (strike < 3)
	{
		strike = 0;
		ball = 0;

		// �÷��̾� ���� �Է�
		printf("�÷��̾� ���� ���� �Է� :");
		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &player[i]);
		}

		if (player[0] == player[1] || player[1] == player[2] || player[2] == player[0])
		{
			printf("�÷��̾� ���� ���Է� (���� �ߺ��Ұ���):\n");
			continue;
		}

		// ���� ���� ���� Ȯ��
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
		printf("��Ʈ����ũ : %d �� : %d\n", strike, ball);
	}
	printf("���� Ŭ����\n");
}