#pragma once
#define WORDLEN 1024
class Printer
{
private:
	char words[WORDLEN];
public:
	void SetString(const char* words);
	void ShowString();
};