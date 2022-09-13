#pragma once

#include <iostream>

enum class CashType {正常收费=0,满300减100,打八折};

class CashSuper {
public:
	virtual double acceptCash(double money) {
		return money;
	}
private:
	double total = 0.0;

};

/********************不打折*******************/
class CashNormal : public CashSuper {
public:
	double acceptCash(double money) override { return money; }
};

/*******************乘法打折*******************/
class CashRebate : public CashSuper {
	double moneyRebate = 1.0;
public:
	CashRebate(double Rebate) {
		this->moneyRebate = Rebate;
	}
	double acceptCash(double money) override { return money*this->moneyRebate; }
};

/*******************满减*******************/
class CashReturn : public CashSuper {
	double moneyCondition = 0.0;
	double moneyReturn = 0.0;
public:
	CashReturn(double Condition,double Return) {
		this->moneyCondition = Condition;
		this->moneyReturn = Return;
	}

	double acceptCash(double money) override { 
		return money - floor(money / (this->moneyCondition)) * moneyReturn;
	}
};

/*******************简单工厂模式***************************/
class CashFac {
public: 
	static CashSuper* createCashAccept(CashType type) {
		CashSuper* cs = nullptr;
		switch (type)
		{
		case CashType::正常收费:
			cs = new CashNormal();
			break;
		case CashType::打八折:
			cs = new CashRebate(0.8);
			break;
		case CashType::满300减100:
			cs = new CashReturn(300, 100);
			break;
		}
		return cs;
	}
};


/*******************策略模式***************************/
class CashContext
{
	CashSuper* cs;
public:
	CashContext(CashSuper* cssuper) {
		this->cs = cssuper;
	}
	double GetResult(double money) {
		return cs->acceptCash(money);
	}
	virtual ~CashContext() {
		if (cs)
		{
			delete cs;
		}
	}
};


/****************个人认为这种模式更好,能自动回收cs**************/
/********************简单工厂+策略模式*******************/
class CashContextFac
{
	CashSuper* cs;
public:
	CashContextFac(CashType type) {
		cs = nullptr;
		switch (type)
		{
		case CashType::正常收费:
			cs = new CashNormal();
			break;
		case CashType::打八折:
			cs = new CashRebate(0.8);
			break;
		case CashType::满300减100:
			cs = new CashReturn(300, 100);
			break;
		}
	}
	double GetResult(double money) {
		return cs->acceptCash(money);
	}

	virtual ~CashContextFac() {
		if (cs)
		{
			delete cs;
		}
	}
};