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
	cout << "��hoggy��1000��Ǯ\n";
	hoggy.deposit(1000);
	cout << "hoggy �����У�" << hoggy.balance()<<endl;
	cout << "��piggy�˻�ȡ�� 6000��\n";
	piggy.withdraw(6000);
	cout << "piggy ���ڻ�ʣ��" << piggy.balance()<<"��Ǯ\n";
	cout << "�� hoggy�˻���ȡ��6000��\n";
	hoggy.withdraw(6000);
	hoggy.ViewAcct();
	return 0;
}