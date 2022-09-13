#include "prototype.h"
#include <ctime>

void prototypeTest()
{
	Resume* xxq = new Resume("xxq");
	xxq->SetPersonInfo("nan", "26");
	xxq->SetWorkExperience("3year", "wy");
	Resume* xxq1 = (Resume*)xxq->clone();
	xxq1->SetWorkExperience("sd", "sd");
	xxq->Display();
	xxq1->Display();
}



