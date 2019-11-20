	  #include "addressType.h"
	#include "extPersonType.h"
	#include "dataType.h"


	addressType::addressType(void)
	{
		StreetAddress="";
		City="";
		State="";
		Zip="";
	}


	addressType::addressType(string address, string city, string state, string zip)
	{
		StreetAddress=address;
		City=city;
		State=state;
		Zip=zip;
	}
	void addressType::printAddress()
	{
		cout<<"Street Address: "<<StreetAddress<<endl;
		cout<<"City          : "<<City<<endl;
		cout<<"State         : "<<State<<endl;
		cout<<"Zip code      : "<<Zip<<endl;
	}

	string  addressType::getStreet()
	{
		return StreetAddress;
	}
	string addressType::getCity()
	{
		return City;
	}
	string addressType::getState()
	{
		return State;
	}
	string addressType::getZip()
	{
		return Zip;
	}
