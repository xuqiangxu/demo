#include "factormethod.h"

void factormethodTest()
{
	unique_ptr<IFactory> fac(new UnderGraduateFactory());
	unique_ptr<LeiFeng> student(fac->CreatLeiFeng());
	student->buyRice();
	student->sweep();
	student->wash();
}