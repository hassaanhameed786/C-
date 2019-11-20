#include <string>
#include <iostream>

using namespace std;

const int MAX_LIST = 10;
typedef int ListItemType;

class List
{
	public:
	List();
bool isEmpty() const;
int getLength(int size) const;
void insert(int index, const ListItemType& newItem, bool& success);
void remove(int index, bool& success);

};

	int List::getLength(int size) const
{
 return size;
}
	void List::insert(int index, const ListItemType& newItem, bool& success);
{
	success = (index >= 1) && (index <= size + 1) && (size < MAX_LIST);
 	if (success)
 {
 	for (int pos = size; pos >= index; --pos)
 	items[pos] = items[pos-1];
 	items[index-1] = newItem;
	 ++size; // increase the size of the list by one
 }
}
 void List::remove(int index, bool& success)
{
 	success = (index >= 1) && (index <= size);
 	if (success)
 {
 	for (int i = index;i < size-1;++i)
 	items[i] = items[i+1];
	 --size; // decrease the size of the list by one
 } // end if
} 

int main()
{
 	List myArrayList;
	cout << myArrayList.getLength() << endl;
 	if (myArrayList.isEmpty()) // tests before
 	cout << "This list is empty \n" << endl;
 	else
	 cout << "List is not empty! \n"<< endl;
 	myArrayList.insert(1, 2, mainsucc);
 	myArrayList.retrieve(1,mainsucc);
}
