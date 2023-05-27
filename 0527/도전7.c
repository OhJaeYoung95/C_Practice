#define _CRT_SECURE_NO_WARNINGS
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
} Info;

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

int Save(Info** infos, int count)
{
    FILE* fp = fopen("infodata.txt", "wb");
    if (fp == NULL)
    {
        printf("Not Found\n");
        return 0;
    }
    
    for (int i = 0; i < count; i++)
    {
        fwrite(infos[i]->name, sizeof(infos[i]->name, 1, fp);
        fwrite(infos[i]->num, sizeof(infos[i]->name, 1, fp);
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s %s\n", infos[i]->name, infos[i]->num);
    }

    fclose(fp);
    return 1;
}
int Load(Info** infos, int* count)
{
    // 기존 데이터 삭제
    for (int i = 0; i < *count; i++)
    {
        free(infos[i]);
    }
    *count = 0;

    FILE* fp = fopen("infodata.txt", "rb");
    if (fp == NULL)
    {
        printf("No saved data found.\n");
        return 0;
    }

    char name[MAX_NAME_LEN];
    char num[MAX_PHONE_NUMBER_LEN];

    while (fscanf(fp, "%s %s", name, num) == 2)
    {
        Info* newInfo = (Info*)malloc(sizeof(Info));
        strcpy(newInfo->name, name);
        strcpy(newInfo->num, num);

        infos[*count] = newInfo;
        (*count)++;
    }

    fclose(fp);
    return 1;
}

int Insert(Info* infos[], int* size, int*count)
{
    if (*count == *size)
    {
        *size *= 2;
        infos = (Info**)realloc(infos, sizeof(Info*) * *size);
    }
    printf("-----------------------------------\n");
    printf("[ INSERT ]\n");
    infos[*count] = (Info*)malloc(sizeof(Info));

    printf("Input Name : ");
    scanf("%s", infos[*count]->name);

    printf("Input Tel Number : ");
    scanf("%s", infos[*count]->num);

    printf("                  Data Inserted\n");
    printf("-----------------------------------\n\n\n");
    (*count)++;

}
int Find(Info* arr[], int len, const char* name);
void PrintAll(Info* arr[], int len);

int main()
{
    int size = 10;
    int count = 0;

    Item menu = 1;
    int index = 0;
    char selectInfo[20];

    Info** infos = (Info**)malloc(sizeof(Info*) * size);

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
            Insert(infos, &size, &count);
            break;
        case DELETE:
            printf("-----------------------------------\n");
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
                free(infos[index]);
                infos[index] = infos[count - 1];
                count--;
                printf("                  Data Deleted\n");
                printf("-----------------------------------\n\n\n");
            }
            else
            {
                printf("Not Found!\n");
                printf("-----------------------------------\n\n\n");
            }
            break;
        case SEARCH:
            printf("-----------------------------------\n");
            printf("[ SEARCH ]\n");
            printf("Search Info's Name : ");
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

            // 검색부분
            if (index != -1)
            {
                printf("Search Name : %s\n", infos[index]->name);
                printf("Search Tel Number : %s\n", infos[index]->num);
                printf("                  Data Searched\n");
                printf("-----------------------------------\n\n\n");
            }
            else
            {
                printf("Not Found!\n");
                printf("-----------------------------------\n\n\n");
            }
            break;
        case PRINTALL:
            printf("-----------------------------------\n");
            printf("[ Print All Data ]\n");
            for (int i = 0; i < count; i++)
            {
                printf("Name : %s\n", infos[i]->name);
                printf("Tel Number : %s\n", infos[i]->num);
            }
            printf("                  All Data Printed\n");
            printf("-----------------------------------\n\n\n");

            break;
        case SAVE:
            if (Save(infos, count))
            {
                printf("-----------------------------------\n");
                printf("[ Save the Data ]\n");
                printf("Data saved successfully.\n");
                printf("-----------------------------------\n\n\n");
            }
            else
            {
                printf("Failed to save data.\n");
                printf("-----------------------------------\n\n\n");
            }
            break;
        case LOAD:
            if (Load(infos, &count))
            {
                printf("-----------------------------------\n");
                printf("[ Load the Data ]\n");
                printf("Data loaded successfully.\n");
                printf("-----------------------------------\n\n\n");
            }
            else
            {
                printf("No saved data found.\n");
                printf("-----------------------------------\n\n\n");
            }
            break;
        }
    }

    // 할당된 메모리 해제
    for (int i = 0; i < count; i++)
    {
        free(infos[i]);
    }
    free(infos);

    printf(" --------------------\n");
    printf("   [ PROGRAM EXIT ] \n");
    printf(" --------------------\n");

    return 0;
}