#pragma once
#ifndef BANK_ACOUNT
#define BANK_ACOUNT
#include<string>
#include<iostream>
using std::string;
class BRASS
{
public:
	BRASS(const string &S="nullbody",long an=-1,double bal=0.0);
	virtual ~BRASS() {};
	void deposit(double x);
	virtual void withdraw(double amt);
	double balance()const;
	virtual void Viewacct()const;
private:
	string name;
	long acount_num;
	double remain_money;
};
class BRASS_PLUS :public BRASS
{
public:
	BRASS_PLUS(const string &s="nullbody",long an=-1,double remainM=0.0, double mloan=500, double rate=0.11125);
	BRASS_PLUS(const BRASS &b, double ir=500.0, double ov=0.11125); 
	virtual ~BRASS_PLUS() {};
	virtual void ViewAcct()const; 
	virtual void withdraw(double amt);
	void resetMAX(double m);
	void resetRate(double r);
	void resetOwes() { NowOverdraft = 0; };
private:
	double InteRating;//超支利率
	double maxloan;//最大超支额度
	double NowOverdraft;//当前超支额度
};


#endif // !BANK_ACOUNT
