#pragma once
class AccountSystem
{
private:
	int accID;	// ���¹�ȣ
	int balance;	// �ܾ�
	char* cusName;	// ���̸�

public:
	AccountSystem(const int _accId, const int _money, const char* _cusName);
	~AccountSystem();
	int GetId();
	int GetBalance();
	void DepositMoney(int money);
	void WithdrawMoney(int money);
	void ShowAllAccInfo();
};