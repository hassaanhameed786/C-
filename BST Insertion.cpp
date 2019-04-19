#include<iostream>
using namespace std;

struct node
{
	int   info;
	node* left;
	node* right;	
};

class BST
{
	//private:
		//no need 
	
	public:
		node *root;
	
	BST(){
		root = NULL;
		
	}
	void preorder(node *temp)
	{
		if (temp!=NULL){
			cout<<temp->info<<"p    ";
			preorder(temp->left);
			preorder(temp->right);
			
		}
	}
		
	void inorder(node *temp)
	{
		if (temp!=NULL){
			inorder(temp->left);
			cout<<temp->info<<"i   ";
			inorder(temp->right);
			
		}
	}
	void insert(node *temp, int data){
		
		//when root is NULL
		if(root == NULL)
		{
	//		cout << "**Binary Tree is empty** " <<endl; 
			root = new node;
			root->left = NULL;
			root->right = NULL;
			root->info = data;
	//		cout << "root inserted" << endl;
			return;
		}
		//
		if(temp->info  == data)
		{
	//		cout << "** node already present ** " <<endl;
			return;
		}
		// data is inserted on the right side of tree
		// when data is gretaer then temp
		if( temp->info < data )
		{
			if(temp->right == NULL )
			{
				temp->right = new node;
				temp->right->info  = data;
				temp->right->right = NULL;
				temp->right->left  = NULL;
	//			cout << "node inserted on right " << endl;
				return;	
			}
			
			else
			{
				insert(temp->right,data);
				return;
			}
			
		}
		//insert on the left side of tree 
		
		if(temp->info > data)
		{
			if(temp->left == NULL)
			{
				temp->left = new node;
				temp->left->info = data;
				temp->left->left = NULL;
				temp->left->right = NULL;
	//			cout << " node inserted on the left" << endl;
				return;
			}
			
			else
			{
				insert(temp->left,data);
				return;
			}
		}
		
		
		
	}
		
};

int main(){
	BST obj;
	obj.insert(obj.root, 4); 		obj.inorder(obj.root);cout<<endl; 	obj.preorder(obj.root); cout<<endl;  cout<<endl;

	obj.insert(obj.root, 15); obj.inorder(obj.root); cout<<endl;	obj.preorder(obj.root); cout<<endl;cout<<endl;
	obj.insert(obj.root, 6);obj.inorder(obj.root); cout<<endl;	obj.preorder(obj.root);cout<<endl;cout<<endl;
	obj.insert(obj.root, 9);obj.inorder(obj.root); 	cout<<endl;obj.preorder(obj.root);cout<<endl;cout<<endl;
	obj.insert(obj.root, 4);obj.inorder(obj.root); cout<<endl;	obj.preorder(obj.root);cout<<endl;
	obj.insert(obj.root, 16);obj.inorder(obj.root); cout<<endl;	obj.preorder(obj.root);cout<<endl;cout<<endl;
	obj.insert(obj.root, 46);obj.inorder(obj.root); cout<<endl;	obj.preorder(obj.root);cout<<endl;cout<<endl;
	obj.insert(obj.root, 56);obj.inorder(obj.root); cout<<endl;	obj.preorder(obj.root);cout<<endl;cout<<endl;
	obj.insert(obj.root, 23);obj.inorder(obj.root); cout<<endl;	obj.preorder(obj.root);cout<<endl;cout<<endl;
	
}
