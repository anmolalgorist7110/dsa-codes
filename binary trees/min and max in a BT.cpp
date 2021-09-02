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


pair<int , int> find(binarytreenode<int>* root)
{
	//pair<int , int> ret = make_pair(INT_MAX , INT_MIN) ;
	
	if(root == NULL)
	{
		pair<int , int> ret = make_pair(INT_MAX , INT_MIN) ;
		return ret ;
	}
	
	pair<int , int> leftpair = find(root -> left) ;
	pair<int , int> rightpair = find(root -> right) ;
	
	pair<int , int> ans ;
	ans.first = min(min(leftpair.first ,rightpair.first) , root -> data) ;
	ans.second = max(max(leftpair.second , rightpair.second) , root -> data) ;
	
	return ans ;
}

int main()
{
	binarytreenode<int>* root = takeinput() ;
	
	pair<int , int> ans = find(root) ;
	
	cout<<"min is"<<" "<<ans.first<<endl ;
	cout<<"max is"<<" "<<ans.second<<endl ;
}

















