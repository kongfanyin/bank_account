#define _CRT_SECURE_NO_WARNINGS 1
//ʹ���鷽��
#include<string>
#include<fstream>
#include<iostream>
#include"account.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
const int LIMIT = 4;
int main(char argc, char** argv)
{
	BRASS* p_clients[LIMIT];
	string temp;
	long tempnum;
	double tempbal;
	char kind;
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "enter client["<<i<<"]'s name: \n";
		getline(cin,temp);
		cout << "enter client[" << i << "]'s count number:\n";
		cin >> tempnum;
		cout << "enter opening balance: $";
		cin >> tempbal;
		cout << "enter 1 for brass acount,or 2 for brassplus acount.\n";
		//�������Ĳ���1����2����һֱ����whileѭ��
		while (cin>>kind&&(kind!='1'&&kind!='2'))
		{
			cout << "enter either 1 or 2";
		}
		if (kind == '1')
		{
			p_clients[i] = new BRASS(temp, tempnum, tempbal);
		}
		else
		{
			double tmax, trate;
			cout << "enter the overtraft limit: $\n";
			cin >> tmax;
			cout << "enter the interest rate:\n";
			cin >> trate;
			p_clients[i] = new BRASS_PLUS(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get()!='\n')
		{
			continue;
		}
	}
	//��̬
	for (int i = 0; i < LIMIT; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	//�ͷ��ڴ�
	for (int i = 0; i < LIMIT; i++)
	{
		delete p_clients[i];
	}
	cout << "Done.";
	return 0;
}