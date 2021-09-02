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


void zigzag(binarytreenode<int>* root)
{
	stack<binarytreenode<int>*> s1 ; // R to L
	stack<binarytreenode<int>*> s2 ; // L to R
	
	s1.push(root) ;
	
	while(s1.size()!=0 || s2.size()!=0)
	{
		while(s1.size()!=0)
		{
			binarytreenode<int>* curr = s1.top() ;
			cout<<curr -> data<<" " ;
			s1.pop() ;
			
			if(curr -> left != NULL)
			{
				s2.push(curr -> left) ;
			}
			
			if(curr -> right != NULL)
			{
				s2.push(curr -> right) ;
			}
			
			if(s1.size() == 0)
			{
				cout<<endl ;
			}
				
		}
		
		while(s2.size() != 0)
		{
			binarytreenode<int>* curr = s2.top() ;
			cout<<curr -> data<<" " ;
			s2.pop() ;
			
			if(curr -> right != NULL)
			{
				s1.push(curr -> right) ;
			}
			
			if(curr -> left != NULL)
			{
				s1.push(curr -> left) ;
			}
			
			if(s2.size() == 0)
			{
				cout<<endl ;
			}
		}
	}
}
int main()
{
	binarytreenode<int>* root = takeinput() ;
	zigzag(root) ;
}






























