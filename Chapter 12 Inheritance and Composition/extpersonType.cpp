#include "addressType.h"
#include "dataType.h"
#include "extPersonType.h"

extPersonType::extPersonType()
{
}
extPersonType::extPersonType(extPersonType person, dateType dob, addressType address, string ph, int type)
{
	Person=person;
	DOB=dob;
	Address=address;
	Type=type;
	phonenumber=ph;
}
void extPersonType::setType(int type)
{
	if(type>=1 && type<=3)
		Type = type;
	else
		Type=1;
}
string  extPersonType::getType()
{
	if(Type==1)
		return "Family Member";
	else if (Type==2)
		return "Friend";
	else if(Type==3)
		return "Business Associate";
}
void extPersonType::printPersonDetails()
{
	Person.print();
	Address.printAddress();
	DOB.printDate();
	cout<<getType();
	cout<<endl<<"Phone: "<<phonenumber<<endl;
}
void extPersonType::setPhone(string ph)
{
	phonenumber=ph;
}

string extPersonType::getPhone()
{
	return phonenumber;
}
void extPersonType::setPerson(personType person)
{
	Person=person;
}
void extPersonType::setDOB(dateType dob)
{
	DOB=dob;
}
void extPersonType::setAddress(addressType address)
{
	Address=address;
}
personType  extPersonType::getPerson()
{
	return Person;
}

dateType extPersonType::getDate()
{
	return DOB;
}
int extPersonType::getIntType()
{
	return Type;
}

addressType extPersonType::getAddress()
{
	return Address;
}
