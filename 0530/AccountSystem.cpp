#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "AccountSystem.h"

using namespace std;

AccountSystem::AccountSystem(const int _accId, const int _money, const char* _cusName) : accID(_accId), balance(_money)
{
	cusName = new char[strlen(_cusName)+1];
	strcpy(cusName, _cusName);
}

AccountSystem::~AccountSystem()
{
	delete[] cusName;
}

int AccountSystem::GetId()
{
	return accID;
}
int AccountSystem::GetBalance()
{
	return balance;
}

void AccountSystem::DepositMoney(int money)
{
	balance += money;
	cout << "ÇöÀç ÀÜ¾×: " << balance << endl ;
	cout << "--------------" << endl << endl;
}

void AccountSystem::WithdrawMoney(int money)
{
	balance -= money;
	cout << "ÇöÀç ÀÜ¾×: " << balance << endl;
	cout << "--------------" << endl << endl;
}
void AccountSystem::ShowAllAccInfo()
{
	cout << "--------------" << endl;
	cout << "°èÁÂID: " << accID << endl;
	cout << "ÀÌ¸§: " << cusName << endl;
	cout << "ÀÜ¾×: " << balance << endl ;
	cout << "--------------" << endl << endl;

}

