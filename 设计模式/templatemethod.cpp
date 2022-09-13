#include "templatemethod.h"


void TemplateMethodTest()
{
	TestPaper* stuA = new Student1();
	TestPaper* stuB = new Student2();
	stuA->TestQuestion1();
	stuA->TestQuestion2();
	stuA->TestQuestion3();
	stuB->TestQuestion1();
	stuB->TestQuestion2();
	stuB->TestQuestion3();
}