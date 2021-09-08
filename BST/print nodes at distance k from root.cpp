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


void depth(binarytreenode<int>* root , int k)
{
	if(k<0 || root == NULL)
	{
		return ;
	}
	
	if(k == 0)
	{
		cout<<root -> data<<endl ;
	}
	
	depth(root -> left , k-1) ;
	depth(root -> right , k-1) ;
	
}

int print(binarytreenode<int>* root , int node ,int k)
{
	if(root == NULL)
	{
		return -1 ;
	}
	
	if(root -> data == node)
	{
		depth(root , k) ;
		return 0 ;
	}
	
	int leftd = print(root -> left , node , k) ;
	
	if(leftd != -1)
	{
		if(leftd + 1 == k)
		{
			cout<<root -> data<<endl ;
			return k ;
		}
		
		int	 disfromroot = leftd + 1;
		depth(root -> right , k - disfromroot - 1) ;
		return disfromroot ;	
	}
	
	int rightd = print(root -> right , node , k) ;
	if(rightd != -1)
	{	
		if(rightd + 1 == k)
		{
			cout<<root -> data<<endl ;
			return k ;
		}
		
		int disfromroot = rightd + 1 ;	
		depth(root -> left , k - disfromroot - 1) ;
		return disfromroot ;
	}
	
	return -1 ;
}


void nodeatk(binarytreenode<int>* root , int node  , int k)
{
	int p = print(root , node , k) ;
}


int main()
{
	binarytreenode<int>* root = takeinput() ;
	int target , k ;
	cin>>target>>k ;
	nodeatk(root , target , k) ;
}



																































