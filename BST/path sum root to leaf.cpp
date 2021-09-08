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

void helper(binarytreenode<int>* root , int k , vector<int> v)
{
	if(root == NULL)
	{
		return ;
	}
	
	
	if(root -> left == NULL && root -> right == NULL)
	{
		if(k - root -> data == 0)
		{
			int i=0 ;
			while(i <v.size())
			{
				cout<<v[i]<<" " ;
				i++ ;
			}
			
			cout<<root -> data<<endl ;
		}
		
		return ;
	}
	
	v.push_back(root -> data) ;
	helper(root -> left , k - root -> data , v) ;
	helper(root -> right , k - root -> data , v) ;
}

void question(binarytreenode<int>* root , int k)
{
	vector<int> v ;
	
	helper(root , k  , v) ;
}


int main()
{
	binarytreenode<int>* root = takeinput() ;
	int k ;
	cin>>k ;
	question(root , k) ;
}

























