#include<iostream>
#include<vector>
#include<unordered_set>
#include "charpter1.h"
#include <time.h>¡¡
#include <random>
#include<string>
#include <queue>

#include "decorator.h"
using namespace std;


void decoratorTest()
{
	Person xc("Ð¡²Ë");
	Sneakers* pqx = new Sneakers();
	BigTrouser* kk = new BigTrouser();
	Tshirts* dtx = new Tshirts();

	pqx->Decorate(&xc);
	kk->Decorate(pqx);
	dtx->Decorate(kk);
	dtx->show();

}