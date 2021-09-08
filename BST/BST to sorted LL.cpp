#include<bits/stdc++.h>
using namespace std ;

template<typename T>

class binarytreenode
{
	public: 
	
	T data ;
	binarytreenode* left ;
	binarytreenode* right ;
	
	binarytreenode(T data)
	{
		this -> data = data ;
		left = NULL ;
		right = NULL ;
	}
	
	~binarytreenode()
	{
		delete left ; 
		delete right ;
	}
	
};

template<typename T>
class node{
	
	public: 
	
	T data ;
	node<int>* next ;
	
	node(T data)
	{
		this -> data = data ;
		this -> next = NULL ;
	}
};


binarytreenode<int>* takeinput()
{
	int rootdata ;
	cout<<"enter the root data"<<endl ;
	
	cin>> rootdata ;
	
	if(rootdata == -1)
	{
		return NULL ;
	}
	
	binarytreenode<int>* root = new binarytreenode<int>(rootdata) ;
	
	queue<binarytreenode<int>*> pendingnodes ;
	
	pendingnodes.push(root) ;
	
	while(pendingnodes.size()!=0)
	{
	   binarytreenode<int>* front = pendingnodes.front() ;
	   
	   pendingnodes.pop() ;
	   
	   cout<<"Enter the left child of"<<" "<<front -> data<<endl ;
	   
	   // takeing input of left child
	   
	   int leftchilddata ;
	   cin>>leftchilddata ;
	   
	   if(leftchilddata != -1)
	   {
	   	 binarytreenode<int>* child = new binarytreenode<int>(leftchilddata) ;
	   	 front -> left = child ;
	   	 pendingnodes.push(child) ;
	   }
	   
	   cout<<"Enter the right child of"<<" "<<front -> data<<endl ;
	   int rightchilddata ;
	   cin>>rightchilddata ;
	   
	   // taking input of right child of the node
	   
	   if(rightchilddata!=-1)
	   {
	   	
	   	binarytreenode<int>* child = new binarytreenode<int>(rightchilddata) ;
	   	front -> right  = child ;
	   	pendingnodes.push(child) ;
	   	
	   }
	}
	
	return root ;
}

class base{
	
	public:
		node<int>* head ;
		node<int>* tail ;
		
		base()
		{
		    head = NULL ;
			tail = NULL ;	
		}
};


base construct(binarytreenode<int>* root)
{
	//base combinedlist ;
	
	if(root == NULL)
	{
		base combinedlist ;
		return combinedlist ;
	}
	
	
	base leftlist = construct(root -> left) ;
	base rightlist = construct(root -> right) ;
	
	
	node<int>* newnode = new node<int>(root -> data) ;
	
	
	if(leftlist.head != NULL)
	{
		leftlist.tail -> next = newnode ;
	}
	
	newnode -> next = rightlist.head ;
	
	base combinedlist ;
	
	
	if(leftlist.head != NULL)
	{
		combinedlist.head = leftlist.head ;
	} else
	{
		combinedlist.head = newnode ;
	}
	
	if(rightlist.tail != NULL)
	{
		combinedlist.tail = rightlist.tail ;
	} else
	{
		combinedlist.tail = newnode ;
	}
	
	return combinedlist ;
	
	
	
}

node<int>* helper(binarytreenode<int>* root)
{
	base list = construct(root) ;
	return list.head ;
}


int main()
{
	binarytreenode<int>* root  = takeinput() ;
	node<int>* head = helper(root) ;
	
	while(head != NULL)
	{
	  cout<<head -> data<<" " ;
	  head = head -> next ;
	}
}

























