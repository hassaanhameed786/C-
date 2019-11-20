#include "extPersonType.h"
#include "addressType.h"
#include "dataType.h"

dateType::dateType(int m, int d, int y)
{
	month=m;
	day=d;
	year=y;
}

int dateType::getDay()
{
	return day;
}
int dateType::getMonth()
{
	return month;
}
int dateType::getYear()
{
	return year;
}
void dateType::printDate()
{
	cout<<"DOB: "<<month<<"/"<<day<<"/"<<year<<endl;
}
