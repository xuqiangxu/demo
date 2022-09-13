#pragma once

#include <iostream>

enum class CashType {�����շ�=0,��300��100,�����};

class CashSuper {
public:
	virtual double acceptCash(double money) {
		return money;
	}
private:
	double total = 0.0;

};

/********************������*******************/
class CashNormal : public CashSuper {
public:
	double acceptCash(double money) override { return money; }
};

/*******************�˷�����*******************/
class CashRebate : public CashSuper {
	double moneyRebate = 1.0;
public:
	CashRebate(double Rebate) {
		this->moneyRebate = Rebate;
	}
	double acceptCash(double money) override { return money*this->moneyRebate; }
};

/*******************����*******************/
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

/*******************�򵥹���ģʽ***************************/
class CashFac {
public: 
	static CashSuper* createCashAccept(CashType type) {
		CashSuper* cs = nullptr;
		switch (type)
		{
		case CashType::�����շ�:
			cs = new CashNormal();
			break;
		case CashType::�����:
			cs = new CashRebate(0.8);
			break;
		case CashType::��300��100:
			cs = new CashReturn(300, 100);
			break;
		}
		return cs;
	}
};


/*******************����ģʽ***************************/
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


/****************������Ϊ����ģʽ����,���Զ�����cs**************/
/********************�򵥹���+����ģʽ*******************/
class CashContextFac
{
	CashSuper* cs;
public:
	CashContextFac(CashType type) {
		cs = nullptr;
		switch (type)
		{
		case CashType::�����շ�:
			cs = new CashNormal();
			break;
		case CashType::�����:
			cs = new CashRebate(0.8);
			break;
		case CashType::��300��100:
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