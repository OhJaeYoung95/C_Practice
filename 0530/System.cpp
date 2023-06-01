#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "AccountSystem.h"
#include "System.h"

using namespace std;
const int NAME_LEN = 20;

int accountNum = 0;
AccountSystem* account[100];
// 메뉴 출력
void ShowMenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

// 계좌개설
void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int money;
	cout << "--------------" << endl;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> money;

	account[accountNum++] = new AccountSystem(id, money, name);
	cout << "--------------";
	cout << endl << endl << endl;
}

// 입 금
void DepositMoney()
{
	int money;
	int id;
	cout << "--------------" << endl;
	cout << "[입   금]" << endl;
	cout << "계좌 ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> money;
	cout << "입금완료" << endl;

	// 입급
	for (int i = 0; i < accountNum; i++)
	{
		if (account[i]->GetId() == id)
		{
			account[i]->DepositMoney(money);
			return;
		}
	}
	cout << "--------------";

}

// 출 금
void WithdrawMoney()
{
	int money;
	int id;
	int index;
	cout << "--------------" << endl;
	cout << "[출   금]" << endl;
	cout << "계좌 ID: ";
	cin >> id;
	// id조회
	for (int i = 0; i < accountNum; i++)
	{
		if (account[i]->GetId() == id)
		{
			index = i;
			break;
		}
	}
	cout << "출금액: ";
	cin >> money;
	while (money > account[index]->GetBalance()) 
	{
		cout << "잔고가 부족합니다!" << endl;
		cin >> money;
	}
	cout << "출금완료" << endl;

	// 출금
	for (int i = 0; i < accountNum; i++)
	{
		if (account[i]->GetId() == id)
		{
			account[i]->WithdrawMoney(money);
			break;
		}
	}
	cout << "--------------";
}

// 계좌정보 전체 조회
void ShowAllAccInfo()
{
	for (int i = 0; i < accountNum; i++)
	{
		account[i]->ShowAllAccInfo();
	}
}

void Exit()
{
	for (int i = 0; i < accountNum; i++)
	{
		delete account[i];
	}
	cout << "프로그램 종료!" << endl;
	cout << "--------------";

}