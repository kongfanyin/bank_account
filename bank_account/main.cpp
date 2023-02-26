#define _CRT_SECURE_NO_WARNINGS 1
#include"account.h"

#include<string>
#include<fstream>
#include<iostream>
using std::cout;
using std::endl;
using std::string;
int main(char argc, char** argv)
{
	BRASS piggy("porcelo piggy", 381299, 4000.00);
	BRASS_PLUS hoggy("horatio hoggy", 382288, 3000.00);
	piggy.Viewacct();
	cout << endl;
	hoggy.ViewAcct();
	cout << endl;
	cout << "给hoggy存1000块钱\n";
	hoggy.deposit(1000);
	cout << "hoggy 现在有：" << hoggy.balance()<<endl;
	cout << "从piggy账户取出 6000块\n";
	piggy.withdraw(6000);
	cout << "piggy 现在还剩：" << piggy.balance()<<"块钱\n";
	cout << "从 hoggy账户里取出6000块\n";
	hoggy.withdraw(6000);
	hoggy.ViewAcct();
	return 0;
}