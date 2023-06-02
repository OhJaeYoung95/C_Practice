#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 128
#define MAX_PHONE_NUMBER_LEN 128

typedef enum
{
	INSERT = 1,
	DELETE,
	SEARCH,
	PRINTALL,
	SAVE,
	LOAD,
	EXIT
} Item;

typedef struct
{
	char name[MAX_NAME_LEN];
	char num[MAX_PHONE_NUMBER_LEN];
}Info;



//int Insert(Info* arr[], int len, const Info* input, const char* name, const char* phoneNumber);
//int Remove(Info* arr[], int len, const char* name);
//int Find(Info* arr[], int len, const char* name);
//void PrintAll(Info* arr[], int len);
//int Save(Info* arr[], int len, FILE* fp);
//int Load(Info* arr[], int size, FILE* fp);

//void PrintMenu(Item menu, int* count);
void PrintScreen()
{
	printf("***** Menu *****\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Search\n");
	printf("4. Print All\n");
	printf("5. Save\n");
	printf("6. Load\n");
	printf("7. Exit\n\n");
}

int main()
{
	int size = 10;
	int count = 0;

	Item menu = 1;
	int index = 0;
	char selectInfo[20];

	Info** infos = (Info*)malloc(sizeof(Info*) * size);
	//Info* infos = (Info*)malloc(sizeof(Info) * (size));
	//memset(infos, 0, sizeof(infos->name) + sizeof(infos->num));

	// infos memset
	//if (!Load(infos, 10))
	//{
	//	Save(infos, count);
	//}


	while (menu != EXIT)
	{

		PrintScreen();
		printf("Choose the item : ");
		scanf("%d", &menu);
		while (menu <= 0 || menu > 7)
		{
			printf("ReChoose the item : ");
			scanf("%d", &menu);
		}

		switch (menu)
		{
		case INSERT:
			if ((count - 1) == size)
				infos = (Info*)realloc(infos, sizeof(Info) * (size * 2));

			printf("[ INSERT ]\n");
			printf("Input Name : ");
			scanf("%s", infos[count]->name);

			printf("Input Tel Number : ");
			scanf("%s", infos[count]->num);

			printf("                  Data Inserted\n\n\n");
			printf("%s\n", infos[count]->name);
			printf("%s\n", infos[count]->num);

			count++;

			break;
		case DELETE:
			printf("[ DELETE ]\n");
			printf("Delete Info's Name : ");
			scanf("%s", selectInfo);
			index = -1;

			// 확인부분
			for (int i = 0; i < count; i++)
			{
				if (strcmp(infos[i]->name, selectInfo) == 0)
				{
					index = i;
					break;
				}
			}
			// 삭제부분
			if (index != -1)
			{
				infos[index] = infos[count - 1];
				stcpy(infos[count - 1]->name, "");
				stcpy(infos[count - 1]->num, "");
				printf("                  Data Deleted\n\n\n");
			}
			else
			{
				printf("Not Found!\n");
			}
			break;
		case SEARCH:
			printf("[ SEARCH ]\n");
			printf("Serach Info's Name : ");
			scanf("%s", selectInfo);
			index = -1;

			// 확인부분
			for (int i = 0; i < count; i++)
			{
				if (strcmp(infos[i]->name, selectInfo) == 0)
				{
					index = i;
					break;
				}
			}

			// 삭제부분
			if (index != -1)
			{
				printf("Search Name : ");
				printf("%s\n", infos[index]->name);
				printf("Search Tel Number : ");
				printf("%s\n", infos[index]->num);
				printf("                  Data Searched\n\n\n");
			}
			else
			{
				printf("Nof Found!\n");
			}
			break;
		case PRINTALL:
			printf("[ Print All Data ]\n");
			for (int i = 0; i < count; i++)
			{
				printf("Name : %s\n", infos[i]->name);
				printf("Tel Number : %s\n", infos[i]->num);
			}
			printf("                  All Data Printed\n\n\n");

			break;
		case SAVE:

			break;
		case LOAD:

			break;
		}
		if (menu == EXIT)
		{
			printf(" --------------------\n");
			printf("   [ PROGRAM EXIT ] \n");
			printf(" --------------------\n");
		}

	}
	return 0;
}