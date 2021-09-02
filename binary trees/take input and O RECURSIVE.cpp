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
	
	~ binarytreenode()
	{
		delete left ;
		delete right ;
	}
};


void printtree(binarytreenode<int>* root)
{
	if(root == NULL)
	{
		return ;
	}
	
	cout<<root -> data<<":" ;
	
	if(root -> left != NULL)
	{
		cout<<"Left child"<<" "<<root -> left -> data ;
	}
	
	if(root -> right != NULL)
	{
		cout<<"Right child"<<" "<<root -> right -> data ;
	}
	
	cout<<endl ;
	
	// recursive call on right and left child of node root
	
	printtree(root -> left) ;
	printtree(root -> right) ;
}

binarytreenode<int>* takeinput() 
{
	int rootdata ;
	cout<<"Enter data"<<endl ;
	cin>> rootdata ;
	
	if(rootdata == -1)
	{
		return NULL ;
	}
	
	binarytreenode<int>* root = new binarytreenode<int>(rootdata) ;
	
	binarytreenode<int>* leftchild = takeinput() ;
	binarytreenode<int>* rightchild = takeinput() ;
	
	root -> left = leftchild ;
	root -> right = rightchild ;
	
	return root ;
}


int main()
{
	binarytreenode<int>* root = takeinput()  ;
	printtree(root) ;
	delete root ;
}
































