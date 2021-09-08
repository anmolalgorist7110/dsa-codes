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


class trio{
	public:
		int minimum ;
		int maximum ;
		bool isbst ;
		int height ;
};

trio bst(binarytreenode<int>* root)
{
	if(root == NULL)
	{
		trio obj ;
		obj.minimum = INT_MAX ;
		obj.maximum = INT_MIN ;
		obj.isbst = true ;
		obj.height = 0 ;
		return obj ;	
	}
	
	
	trio left = bst(root -> left) ;
	trio right = bst(root -> right) ;
	
	int minimum = min(root -> data , min(left.minimum , right.minimum)) ;
	int maximum = max(root -> data , max(left.maximum , right.maximum)) ;
	
	bool isBSTfinal = (root -> data > left.maximum) && (root -> data < right.minimum) && left.isbst && right.isbst ;
	
	trio obj ;
	obj.minimum = minimum ;
	obj.maximum = maximum ;
	obj.isbst = isBSTfinal ;
	
	if(isBSTfinal)
	{
		obj.height = 1 + max(left.height , right.height) ;
	} else 
	{
		obj.height = max(left.height , right.height) ;
	}
	return obj ;
}


int main()
{
	binarytreenode<int>* root = takeinput() ;
	
	trio ans = bst(root) ;
	
	cout<<"Largest BST is of height"<<" "<<ans.height<<endl ;
}



























