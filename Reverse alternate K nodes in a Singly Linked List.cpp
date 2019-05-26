#include<stdio.h> 
#include<stdlib.h> 

/* Link list node */
struct node 
{ 
	int data; 
	struct node* next; 
}; 

/* Helper function for kAltReverse() */
struct node * _kAltReverse(struct node *node, int k, bool b); 

/* Alternatively reverses the given linked list in groups of 
given size k. */
struct node *kAltReverse(struct node *head, int k) 
{ 
return _kAltReverse(head, k, true); 
} 

/* Helper function for kAltReverse(). It reverses k nodes of the list only if 
	the third parameter b is passed as true, otherwise moves the pointer k 
	nodes ahead and recursively calls iteself */
struct node * _kAltReverse(struct node *node, int k, bool b) 
{ 
if(node == NULL) 
	return NULL; 

int count = 1; 
struct node *prev = NULL; 
struct node *current = node; 
struct node *next; 

/* The loop serves two purposes 
	1) If b is true, then it reverses the k nodes 
	2) If b is false, then it moves the current pointer */
while(current != NULL && count <= k) 
{ 
	next = current->next; 

	/* Reverse the nodes only if b is true*/
	if(b == true) 
		current->next = prev; 
			
	prev = current; 
	current = next; 
	count++; 
} 
	
/* 3) If b is true, then node is the kth node. 
	So attach rest of the list after node. 
	4) After attaching, return the new head */
if(b == true) 
{ 
		node->next = _kAltReverse(current,k,!b); 
		return prev;		 
} 
	
/* If b is not true, then attach rest of the list after prev. 
	So attach rest of the list after prev */	
else
{ 
		prev->next = _kAltReverse(current, k, !b); 
		return node;	 
} 
} 


/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(struct node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct node* new_node = 
			(struct node*) malloc(sizeof(struct node)); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Function to print linked list */
void printList(struct node *node) 
{ 
	int count = 0; 
	while(node != NULL) 
	{ 
		printf("%d ", node->data); 
		node = node->next; 
		count++; 
	} 
} 

/* Drier program to test above function*/
int main(void) 
{ 
	/* Start with the empty list */
	struct node* head = NULL; 
	int i; 

	// create a list 1->2->3->4->5...... ->20 
	for(i = 20; i > 0; i--) 
	push(&head, i); 

	printf("\n Given linked list \n"); 
	printList(head); 
	head = kAltReverse(head, 4); 

	printf("\n Modified Linked list \n"); 
	printList(head); 

	getchar(); 
	return(0); 
} 

