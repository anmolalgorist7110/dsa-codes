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

class isBSTreturn{
	public: 
	bool isBST ;
	int minimum ;
	int maximum ;
};

isBSTreturn isBST2(binarytreenode<int>* root)
{
	if(root == NULL)
	{
	   isBSTreturn output ;
	   output.isBST = true ;
	   output.minimum = INT_MAX ;
	   output.maximum = INT_MIN ;
	   return output ;
	}
	
	isBSTreturn leftoutput = isBST2(root -> left) ;
	isBSTreturn rightoutput = isBST2(root -> right) ;
	
	int minimum  = min(root -> data , min(leftoutput.minimum , rightoutput.minimum)) ;
	int maximum = max(root -> data , max(leftoutput.maximum , rightoutput.maximum)) ;
	
	bool isBSTfinal = (root -> data > leftoutput.maximum) && (root -> data <= rightoutput.minimum) && leftoutput.isBST && rightoutput.isBST ;
	
	isBSTreturn output ;
	
	output.minimum = minimum ;
	output.maximum = maximum ;
	output.isBST = isBSTfinal ;
	
	return output ;
}

int main()
{
	binarytreenode<int>* root = takeinput() ;
	isBSTreturn ans = isBST2(root) ;
	
	if(ans.isBST)
	{
		cout<<"yes it is a BST"<<endl ;
	} 
	else
	{
		cout<<"no it is not a BST"<<endl ;
	}
}






































