#include "account.h"
#include<iostream>
using std::cout;
using std::string;
using std::endl;
//模板相关
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
		cout << "存钱值不能为负值。\n 操作取消";
	}
	else
	{
		remain_money += x;
	}
}

void BRASS::withdraw(double amt)
{
	//设置输出格式模板
	format initialState = setFormat();
	precis prec = cout.precision(2);
	double bal = balance();
	if (amt<0)
	{
		cout << "取钱值不能为负值\n";
	}
	else if(amt<=remain_money)
	{
		remain_money -= amt;
	}
	else
	{
		cout << "余额不足，交易取消\n";
	}
	restore(initialState, prec);
}

double BRASS::balance() const
{
	//当前余额
	return remain_money;
}

void BRASS::ViewAcct() const
{
	//设置浮点输出格式
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "用户名：" << name << endl;
	cout << "账号：" << acount_num << endl;
	cout << "当前余额: " << remain_money << endl;
	restore(initialState, prec);
}

//继承类  BRASSplus 方法

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
//重定义ViewAcct函数
void BRASS_PLUS::ViewAcct() const
{
	//设置模板 ###.##
	format initialState = setFormat();
	precis prec = cout.precision(2);//输出格式设置为两位小数

	//使用基类函数
	BRASS::ViewAcct();
	cout << "超支利率：" <<100* InteRating <<'%'<< endl;
	cout<< "最大超值额度：" << maxloan << endl;
	cout << "当前超支额度：" << NowOverdraft << endl;
	restore(initialState,prec);
}

void BRASS_PLUS::withdraw(double amt)
{
	//输出格式设置为两位小数
	format initialState = setFormat();
	precis prec = cout.precision(2);
	double bal = balance();
	if (amt <= bal)//取款值小于或等于当前余额
	{
		BRASS::withdraw(amt);
	}
	else if (amt <= bal + maxloan - NowOverdraft)//取款值<=当前余额+最大超值额度-当前超支额度
	{
		double advance = amt - bal;
		NowOverdraft += advance * (1 + InteRating);
		cout << "此次交易预支额度：" << advance << "$" << endl;
		cout << "预支利息：" << advance * InteRating << '$' << endl;
		deposit(advance);
		BRASS::withdraw(amt);
	}
	else
	{
		cout << "信用卡取款额度超限，交易取消\n";
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
