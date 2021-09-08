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

int maximum(binarytreenode<int>* root)
{
	if(root == NULL)
	{
		return INT_MIN ;
	}
	
	return max(root -> data , max(maximum(root -> left) , maximum(root -> right))) ;
}

int minimum(binarytreenode<int>* root)
{
	if(root == NULL)
	{
		return INT_MAX ;
	}
	
	return min(root -> data ,min(minimum(root -> left) , minimum(root -> right))) ;
}

bool isBST(binarytreenode<int>* root)
{
	if(root == NULL)
	{
		return true ;
	}
	
	int leftmax = maximum(root -> left) ;
	int rightmin = minimum(root -> right) ;
	
	bool output = (root -> data > leftmax) && (root ->data <= rightmin) && isBST(root -> left) && isBST(root -> right) ;
	
	return output ;
}


int main()
{
	binarytreenode<int>* root = takeinput() ;
	
	bool ans =  isBST(root) ;
	
	if(ans)
	{
		cout<<"true"<<endl ;
	} else
	{
		cout<<"false"<<endl ;
	}
}


























