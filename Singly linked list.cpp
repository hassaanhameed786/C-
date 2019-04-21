#include<iostream>
using namespace std;

struct node{
	int info;
	node* next;
	
};

class Linkedlist{
	
	private:
		node * head, *tail;
		
	public:
		
	Linkedlist()
	{
		head = NULL;
		tail = NULL;
	}
	// Inserting a node in Linked list
	void AddNode(int data)
	{
		node* temp = new node;
		temp->info = data;
		temp->next = NULL;
		
		if(head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else 
		{
			tail->next = temp;
			tail =temp;	
		}
	}
	node* gethead()
	{
		return head;
	}
	
	node Display_Linkedlist(node* head)
	{	
		if(head == NULL)	cout << "NULL" <<endl;
		
		else
		{
		cout << head->info <<endl;
		Display_Linkedlist(head->next);
		}
		
	}
	
};

int main()
{
	Linkedlist l;
	l.AddNode(2);
	l.AddNode(3);
	l.AddNode(4);
	l.AddNode(5);
	l.Display_Linkedlist(l.gethead());
	
}
