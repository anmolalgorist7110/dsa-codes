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


void print(binarytreenode<int>* root)
{
	if(root == NULL)
	{
		return ;
	}
	
	queue<binarytreenode<int>*> q ;
	q.push(root) ;
	q.push(NULL) ;
	
	
	while(!q.empty())
	{
		binarytreenode<int>* first = q.front() ;
		q.pop() ;
		
		if(first == NULL)
		{
			if(q.empty())
			{
				break;
			}
			
			cout<<endl ;
			q.push(NULL) ;
			continue ;
		}
		
		cout<<first -> data<<" " ;
		
		if(first -> left != NULL)
		{
			q.push(first -> left) ;
		}
		
		if(first -> right != NULL)
		{
			q.push(first -> right) ;
		}
	}
}


int helper(binarytreenode<int>* root , int sum)
{
	if(root == NULL)
	{
		return sum ;
	}
	
	int ans = helper(root -> right , sum) ;
	
	ans += root -> data ;
	root -> data = ans ;
	ans = root -> data ;
	helper(root -> left , ans) ;
}

void replace(binarytreenode<int>* root)
{
	if(root == NULL)
	{
		return ;
	}
	
	helper(root , 0) ;
}

int main()
{
	
	binarytreenode<int>* root = takeinput() ;
	replace(root) ;
	print(root) ;
	
}























