#include "builder.h"


void BuildTest()
{
	PersonThinBuilder* ptb = new PersonThinBuilder();
	PersonDirector* pb = new PersonDirector(ptb);
	pb->CreatPerson();

}