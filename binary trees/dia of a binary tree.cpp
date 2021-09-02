#include<bits/stdc++.h>
using namespace std ;

template<typename T>


class binarytreenode{
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
	cout<<"Enter root data"<<endl ;
	cin>> rootdata ;
	
	if(rootdata == -1)
	{
		return NULL ;
	}
	
	binarytreenode<int>* root = new binarytreenode<int>(rootdata) ;
	queue<binarytreenode<int>*> pendingnodes ;
	pendingnodes.push(root) ;
	
	while(pendingnodes.size() != 0)
	{
		binarytreenode<int>* front = pendingnodes.front() ;
		pendingnodes.pop() ;
		
		cout<<"Enter the left child of"<<" "<<front -> data<<endl ;
		int leftchilddata ;
		cin>> leftchilddata ;
		
		if(leftchilddata != -1)
		{
			binarytreenode<int>* child = new binarytreenode<int>(leftchilddata) ;
			front -> left = child ;
			pendingnodes.push(child) ;
		}
		
		
		cout<<"Enter right child of"<<" "<<front -> data<<endl ;
		int rightchilddata ;
		cin>> rightchilddata ;
		
		if(rightchilddata != -1)
		{
			binarytreenode<int>* child = new binarytreenode<int>(rightchilddata) ;
			
			front -> right = child ;
			pendingnodes.push(child) ;
		}
		
		
		
		
		
		
		
		
		
		
		
	}
	
	return root ;
}


// naive solution for finding dia of a binary tree

int height(binarytreenode<int>* root)
{
	if(root == NULL)
	{
		return 0 ;
	}
	
	int ans = 1 + max(height(root -> left) , height(root -> right)) ;
	
	return ans ;
}

int diameter(binarytreenode<int>* root)
{
	if(root == NULL)
	{
		return 0 ;
	}
	
	int option1 = height(root -> left) + height(root -> right) ;
	int option2 = diameter(root -> left) ;
	int option3 = diameter(root -> right) ;
	
	return max(option1 , max(option2 , option3)) ;
}

// better solution using pair class funtion

pair<int , int> heightdia(binarytreenode<int>* root)
{
	if(root == NULL)
	{
		pair<int , int> p ;
		p.first = 0 ;
		p.second = 0 ;
		return p ;
	}
	
	pair<int , int> leftans = heightdia(root -> left) ;
	pair<int , int> rightans = heightdia(root -> right) ;
	
	int ld  = leftans.second ;
	int lh = leftans.first ;
	
	int rd = rightans.second ;
	int rh = rightans.first ;
	
	int height = 1 + max(lh , rh) ;
	int diameter = max(lh + rh , max(ld , rd)) ;
	
	pair<int , int> p ;
	p.first = height ;
	p.second = diameter ;
	
	
	return p ;
	
}

int main()
{
	binarytreenode<int>* root = takeinput() ;
	
	cout<<"dia via naive soln is"<<" "<<diameter(root)<<endl ;
	pair<int , int> ans = heightdia(root) ;
	
	cout<<"dia via better approach will be"<<" "<<ans.second<<endl ;
}






























