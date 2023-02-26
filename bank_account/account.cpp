#include "account.h"
#include<iostream>
using std::cout;
using std::string;
using std::endl;
//ģ�����
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format F, precis P);
BRASS::BRASS(const string & S, long an, double bal)
{
	name = S;
	acount_num = an;
	remain_money = bal;
}
void BRASS::deposit(double x)
{
	if (x < 0)
	{
		cout << "��Ǯֵ����Ϊ��ֵ��\n ����ȡ��";
	}
	else
	{
		remain_money += x;
	}
}

void BRASS::withdraw(double amt)
{
	//���������ʽģ��
	format initialState = setFormat();
	precis prec = cout.precision(2);
	double bal = balance();
	if (amt<0)
	{
		cout << "ȡǮֵ����Ϊ��ֵ\n";
	}
	else if(amt<=remain_money)
	{
		remain_money -= amt;
	}
	else
	{
		cout << "���㣬����ȡ��\n";
	}
	restore(initialState, prec);
}

double BRASS::balance() const
{
	//��ǰ���
	return remain_money;
}

void BRASS::ViewAcct() const
{
	//���ø��������ʽ
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "�û�����" << name << endl;
	cout << "�˺ţ�" << acount_num << endl;
	cout << "��ǰ���: " << remain_money << endl;
	restore(initialState, prec);
}

//�̳���  BRASSplus ����

BRASS_PLUS::BRASS_PLUS(const string & s, long an, double remainM, double mloan, double rate):BRASS(s,an,remainM)
{
	maxloan = mloan;
	InteRating = rate;
	NowOverdraft = 0.0;
}

BRASS_PLUS::BRASS_PLUS(const BRASS & b, double ir, double ov) :BRASS(b)
{
	maxloan = ov;
	InteRating = ir;
	NowOverdraft = 0.0;
}
//�ض���ViewAcct����
void BRASS_PLUS::ViewAcct() const
{
	//����ģ�� ###.##
	format initialState = setFormat();
	precis prec = cout.precision(2);//�����ʽ����Ϊ��λС��

	//ʹ�û��ຯ��
	BRASS::ViewAcct();
	cout << "��֧���ʣ�" <<100* InteRating <<'%'<< endl;
	cout<< "���ֵ��ȣ�" << maxloan << endl;
	cout << "��ǰ��֧��ȣ�" << NowOverdraft << endl;
	restore(initialState,prec);
}

void BRASS_PLUS::withdraw(double amt)
{
	//�����ʽ����Ϊ��λС��
	format initialState = setFormat();
	precis prec = cout.precision(2);
	double bal = balance();
	if (amt <= bal)//ȡ��ֵС�ڻ���ڵ�ǰ���
	{
		BRASS::withdraw(amt);
	}
	else if (amt <= bal + maxloan - NowOverdraft)//ȡ��ֵ<=��ǰ���+���ֵ���-��ǰ��֧���
	{
		double advance = amt - bal;
		NowOverdraft += advance * (1 + InteRating);
		cout << "�˴ν���Ԥ֧��ȣ�" << advance << "$" << endl;
		cout << "Ԥ֧��Ϣ��" << advance * InteRating << '$' << endl;
		deposit(advance);
		BRASS::withdraw(amt);
	}
	else
	{
		cout << "���ÿ�ȡ���ȳ��ޣ�����ȡ��\n";
	}
	restore(initialState, prec);
}

void BRASS_PLUS::resetMAX(double m)
{
	maxloan = m;
}

void BRASS_PLUS::resetRate(double r)
{
	InteRating = r;
}

format setFormat()
{
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format F, precis P)
{
	cout.setf(F, std::ios_base::floatfield);
	cout.precision(P);
}
