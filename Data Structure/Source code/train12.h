#include<iostream>
using namespace std;
struct Train{
	string firstname;
	string lastname; 
	string cell_no;
	string email;
	string post;	//rank of the post	
	int id;			// unique id
	Train *right, *left;
	int height;
};
class avlimplementation{
	private:
		Train *temp;
		Train *ptr;
		
	public:
		Train *root;		
	avlimplementation()
	{
		root = temp = ptr = NULL;
	}
int Findmax(int n1, int n2)
	{
		if(n1 > n2)
		{
			return n1;
		}
		else
		{
			return n2;
		}
	}	
int height(Train *temp)
	{
		if(temp == NULL)
		{
			return 0;
		}
		int lh = height(temp->left);
		int rh = height(temp->right);		
		if(lh > rh)
		{
			return lh+1;
		}
		
		else
		{
			return rh+1;
		}
	}	
Train *left_rotation(Train *temp)
	{
		
		ptr = temp->right;
		temp->right = ptr->left;
		ptr->left = temp;
		
		temp->height = max(height(temp->left), height(ptr->right)) + 1;
		ptr->height = max(height(temp->left), height(ptr->right)) + 1;
		
		return ptr;
	}	
	Train *right_rotation(Train *temp)
	{	
	
		ptr = temp->left;
		temp->left = ptr->right;
		ptr->right = temp;
		
		temp->height = max(height(temp->left), height(temp->right)) +1;
		ptr->height = max(height(ptr->left), height(ptr->right)) +1;
		
		return ptr;
	}	
	Train *right_left_rotation(Train *temp)
	{	
	
		temp->right = right_rotation(temp->right);
		return left_rotation(temp);
	}
	
	Train *left_right_rotation(Train *temp)
	{	
		
		temp->left = left_rotation(temp->left);
		return right_rotation(temp);
	}
Train *insertion(Train *temp, int number,string firstname, string lastname, string cell_no,string email,string post ) // number is Id
	{
		if(temp == NULL)
		{
			temp = new Train;
			temp->id = number;
			temp->firstname = firstname;
			temp->lastname =lastname;
			temp->cell_no = cell_no;
			temp->email = email;
			temp->post = post;
			temp->left = temp->right = NULL;
			temp->height = 0;
		}
		if(number < temp->id)
		{
			temp->left = insertion(temp->left, number,firstname, lastname, cell_no,email,post);
			
			if(height(temp->left) - height(temp->right) == 2)
			{
				if(number < temp->left->id)
				{
					temp = right_rotation(temp);
				}
				else
				{
					temp = left_right_rotation(temp);
				}
			}
		}
		if(number > temp->id)
		{
			temp->right = insertion(temp->right, number,firstname, lastname, cell_no,email,post);
			
			if(height(temp->right) - height(temp->left) == 2)
			{
				if(number > temp->right->id)
				{
					temp = left_rotation(temp);
				}
				else
				{
					temp = right_left_rotation(temp);
				}
			}
		}
		temp->height = max(height(temp->left), height(temp->right)) +1 ;
		return temp;
	}
	
	///////////////////////////////////////////////////////////////////////////////////
	
	Train *min(Train *temp)
	{
		if(temp == NULL)
		{
			return 0;	
		}	
		if(temp->left == NULL)
		{
			return temp;
		}
		else
		{
			min(temp->left);
		}
		
	}		
	Train *balance(Train *temp)
	{
		if(temp == NULL)
		{
			cout<<"No rotation is found "<<endl;
		}
		else if( height(temp->left)-height(temp->right) > 1)
		{
			if(height(temp->left->left) >= height(temp->left->right))
			{
				temp = right_rotation(temp);
			}
			else
			{
				temp = left_right_rotation(temp);
			}
		}
		else if( height(temp->right) - height(temp->left) > 1)
		{
			
			if(height(temp->right->right) >= height(temp->right->left))
			{
				temp = left_rotation(temp);
			}
			else
			{
				temp =right_left_rotation(temp);
			}
		}
		temp->height = max(height(temp->left), height(temp->right)) + 1;
		return temp;
	}

	Train *deletion_in_avl(Train *temp, int number)
	{
		if(temp == NULL)
		{
			cout<<"The value is not found "<<endl;
			
		}
		else if(number < temp->id)
		{  
			temp->left = deletion_in_avl(temp->left, number);
		}
		else if(number > temp->id)
		{
			temp->right = deletion_in_avl(temp->right, number);
		}
		else if(temp->left && temp->right)
		{
			ptr = min(temp->right);
			temp->id = ptr->id;
			temp->firstname =ptr->firstname;
			temp->lastname  =ptr->lastname;
			temp->cell_no = ptr->cell_no;
			temp->email = ptr->email;
			temp->post = ptr->post;
			
			
			
			temp->right = deletion_in_avl(temp->right, temp->id);
		}
		else
		{
			ptr = temp;
			if(temp->left == NULL)
			{ 
				temp = temp->right;
			}
			else if(temp->right == NULL)
			{
				temp = temp->left;
			}
			delete ptr;
		}
		if(temp != NULL)
		{
			temp = balance(temp);
		}

		return temp;
		
	}		
	///////////////////////////////////////////////////////////////////////////////////
	void in_order(Train *temp)
	{
		if(temp->left != NULL)
		{
			in_order(temp->left);
		}
		cout << temp->id << "    ";
		if(temp->right != NULL)
		{
			in_order(temp->right);
		}
	}
	void pre_order(Train *temp)
	{
		if(temp!=NULL){
			
			pre_order(temp->left);
			
			cout<<"..............................................."<<endl;		
			cout <<"id: "<< temp->id 	   <<"   "<<endl;
			cout <<"firstname: "<< temp->firstname<<"   "<<endl;
			cout <<"lastname: "<< temp->lastname <<"   "<<endl;
			cout <<"cell_no: "<< temp->cell_no  <<"   "<<endl;
			cout <<"email: "<< temp->email    <<"   "<<endl;
			cout <<"post: "<< temp->post     <<"   "<<endl; 
			cout <<"<-------------------------------------->"<<endl;
			
			pre_order(temp->right);	
		}	
	}
Train* Find(int id, Train* T)
 {
if (T == NULL)
 {
 return NULL;
 }
 if (id < T->id)
 {
 return Find(id, T->left);
 }
 else if (id > T->id)
 {
 return Find(id, T->right);
 }
else
 return T;
}

void Update_Staff_firstname(int id,string firstname,string lastname, string email,string cell_no,string post)
{
	temp = Find(id, root);
	
	if(temp == NULL)
	{
		cout << "There is a wrong id check it again " << endl;
		
	}	
	else
	{
		temp->firstname = firstname;
		temp->lastname = lastname;
		temp->email = email;
		temp->cell_no = cell_no;
		temp->post = post;
	}
}
	

void Search_Staff_Member(int id)

{	
	temp  =	 Find(id, root);
	if(temp  == NULL)
	{
		cout << "You entered a  wrong id , u messed up " << endl;
		
	}
	else
	{		cout<<"..............................................."<<endl;
			cout <<"id: "<< temp->id 	   <<"   "<<endl;
			cout <<"firstname: "<< temp->firstname<<"   "<<endl;
			cout <<"lastname: "<< temp->lastname <<"   "<<endl;
			cout <<"cell_no: "<< temp->cell_no  <<"   "<<endl;
			cout <<"email: "<< temp->email    <<"   "<<endl;
			cout <<"post: "<< temp->post     <<"   "<<endl; 
			cout<<"..................................................."<<endl;
	
}





	
	
};


