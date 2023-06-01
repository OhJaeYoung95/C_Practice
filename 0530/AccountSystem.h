#pragma once
class AccountSystem
{
private:
	int accID;	// °èÁÂ¹øÈ£
	int balance;	// ÀÜ¾×
	char* cusName;	// °í°´ÀÌ¸§

public:
	AccountSystem(const int _accId, const int _money, const char* _cusName);
	~AccountSystem();
	int GetId();
	int GetBalance();
	void DepositMoney(int money);
	void WithdrawMoney(int money);
	void ShowAllAccInfo();
};