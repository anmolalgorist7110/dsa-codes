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


int getLCA(binarytreenode<int>* root , int val1 , int val2)
{
	if(root == NULL)
	{
		return -1 ;
	}
	
	if(root -> data == val1 || root -> data == val2)
	{
		return root -> data ;
	} else if(root -> data > val1 && root -> data > val2)
	{
		return getLCA(root -> left , val1 , val2) ;
	} else if(root -> data < val1 && root -> data < val2)
	{
		return getLCA(root -> right , val1 , val2) ;
	} else
	{
		int left = getLCA(root -> left , val1 , val2) ;
		int right = getLCA(root -> right , val1 , val2) ;
		
		if(left == NULL && right == NULL)
		{
			return -1 ;
		} else if(left == NULL && right != NULL)
		{
			return right ;
		} else if(left != NULL && right == NULL)
		{
			return left ;
		} else
		{
			return root -> data ;
		}
	}
}


int main()
{
	binarytreenode<int>* root = takeinput() ;
	int val1 , val2 ;
	cin>>val1>>val2 ;
	
	int ans = getLCA(root , val1 , val2) ;
	cout<<"LCA of BST is"<<ans<<endl ;
}























