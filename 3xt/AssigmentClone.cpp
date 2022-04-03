#include<iostream>

using namespace std;

class node
{
	public:
		
	int value;
	node* right , * left;
	
	node(int v )
	{
		value = v;
		right = NULL;
		left = NULL;	
	}
};

class tree
{
	public:
		
	void insertNode(node * new_node) 
	{
      if (root == NULL)
	  {
        root = new_node;
        cout << "Value Inserted as root node!" << endl;
      } 
	  else
	  {
      node * temp = root;
      while (temp != NULL) {
        if (new_node -> value == temp -> value) 
		{
          cout << "Value Already exist," <<
            "Insert another value!" << endl;
          return;  
		}
        else if ((new_node -> value < temp -> value) && (temp -> left == NULL)) 
		{
          temp -> left = new_node;
          cout << "Value Inserted to the left!" << endl;
          break;
        } 
		else if (new_node -> value < temp -> value) 
		{
          temp = temp -> left;
        } 
        else if ((new_node -> value > temp -> value) && (temp -> right == NULL)) 
		{
          temp -> right = new_node;
          cout << "Value Inserted to the right!" << endl;
          break;
        } else 
		{
          temp = temp -> right;
        }
	    }
		}  
	}

	void printInorder(node * r) //  (Left, current node, Right)
    {
      if (r == NULL)
      return;
      printInorder(r -> left);
      cout << r -> value << " ";
    
      printInorder(r -> right);
    }

		
	void statusofnode(node* r)
	{
		if(r == NULL)
		{
			return;
		}
		
		if(r->left == NULL && r->right == NULL)
		{
		   cout<<r->value <<" is child node"<<endl;	
		}
		else
		{
			cout<<r->value<<" is parent node"<<endl;
		}
		
		statusofnode(r->left);
		statusofnode(r->right);
	}
	
	void nodesum(node* r)
	{
	   if(r == NULL)
	   {
	     return;	
	   }	
	   
	   sum = sum +r->value;
	   
	   nodesum(r->left);
	   nodesum(r->right);
	}
	
	void average()
	{
		cout << "average is :" <<count /sum <<endl;
	}
	
	
	void displayevennumbers(node* r)
	{
	   if(r == NULL)
	   {
	     return;	
	   }	
	   
	   if(r->value %2 == 0)
	   {
	   	cout <<r->value<<endl;
	   }
	   
	   displayevennumbers(r->left);
	   displayevennumbers(r->right);
	}
	
	void displaymultipleofthree(node* r)
	{
	   if(r == NULL)
	   {
	     return;	
	   }	
	   
	   if(r->value %3 == 0)
	   {
	   	cout <<r->value<<endl;
	   }
	   
	   displaymultipleofthree(r->left);
	   displaymultipleofthree(r->right);
	}
	
	   
    int validbst(node* node)
    {
      if (node == NULL)
      {
       return 1;
	  }
     
      if (node->left != NULL && node->left->value > node->value)
      {
      	return 0;
	  }
    
     
     if (node->right != NULL && node->right->value < node->value)
     {
     	return 0;     	
	 }
   
      
     if (!validbst(node->left) || !validbst(node->right))
     {
       return 0;	
	 }
     
    return 1;
  }
	
	node* root = NULL;
	int sum;
    int count;		
};

int main () 
{
	tree t;
	t.insertNode(new node(1));
	t.insertNode(new node(2));
	t.insertNode(new node(3));
	t.insertNode(new node(4));
	t.insertNode(new node(5));
	t.statusofnode(t.root);
	t.displayevennumbers(t.root);
	t.displaymultipleofthree(t.root);
	t.nodesum(t.root);
	cout<<"sum is :"<<t.sum<<endl;
	t.printInorder(t.root);
	if(t.validbst(t.root) == 1)
	{
		cout <<"tree is bst"<<endl;
	}
	else
	{
		cout <<"tree is not bst"<<endl;
	}
}