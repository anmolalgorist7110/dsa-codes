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
	

	
};



void preorder(binarytreenode<int>* root)
{
	if(root == NULL)
	{
		return ;
	}
	
	cout<<root -> data<<" " ;
	preorder(root -> left) ;
	preorder(root -> right) ; 
}

binarytreenode<int>* tree(int* input , int start , int end)
{
	// base case
	if(start > end)
	{
		return NULL ;
	}
	
	int mid = (start + end)/2 ; // mid of array which is going to be the root of the BST
	binarytreenode<int> * root = new binarytreenode<int>(input[mid]) ;
	
	root -> left = tree(input , start , mid -1) ;
	root -> right = tree(input ,mid+1 , end) ;
	return root ;
}
binarytreenode<int>* constructtree(int* input , int n)
{
	int start = 0 ;
	int end = n-1 ;

	binarytreenode<int>* ans = tree(input , start , end) ;
	return ans ;
}

int main()
{
	int size ;
	cin>> size  ;
	
	
	int *input =  new int[size] ;
	
	
	
	
	for(int i=0 ; i<size ; i++)
	{
		cin>>input[i] ;
	}
	
	
	binarytreenode<int>* root = constructtree(input , size) ;
	preorder(root) ;
	
}

































