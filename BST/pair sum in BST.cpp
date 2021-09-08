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

int countnodes(binarytreenode<int>* root)
{
	if(root == NULL)
	{
		return 0 ;
	}
	
	return countnodes(root -> left) + countnodes(root -> right) + 1 ;
}

void printnodes(binarytreenode<int>* root , int s)
{
	if(root == NULL)
	{
		return ;
	}
	
	int total = countnodes(root) ;
	int count = 0 ;
	
	
	stack<binarytreenode<int>*> inorder ;
	stack<binarytreenode<int>*> revorder ;
	
	
	binarytreenode<int>* currnode = root;
	
	while(currnode != NULL)
	{
		inorder.push(currnode) ;
		currnode = currnode -> left ;
	}
	
	currnode = root ;
	
	while(currnode != NULL)
	{
		revorder.push(currnode) ;
		currnode = currnode -> right ;
	}
	
	// now the main operation is going to start 
	
	while(count < total - 1)
	{
		binarytreenode<int>* intop = inorder.top() ;
		binarytreenode<int>* revtop = revorder.top() ;
		
		if(intop -> data + revtop -> data == s)
		{
			cout<<intop -> data<<" "<<revtop -> data<<endl ;
			
			binarytreenode<int>* top = intop ;
			inorder.pop() ;
			count++ ;
			
			if(top -> right != NULL)
			{
				top = top -> right ;
				while(top != NULL)
				{
					inorder.push(top) ;
					top = top -> left ;
				}
			}
			
			top = revtop ;
			revorder.pop() ;
			
			count ++ ;
			
			if(top -> left != NULL)
			{
				top = top -> left ;
				while(top != NULL)
				{
					top = top -> right ;
					revorder.push(top) ;
					top = top -> right ;
				}
			}
		
		} else if(intop -> data + revtop -> data > s)
		{
			binarytreenode<int>* top = revtop ;
			revorder.pop() ;
			count++ ;
			
			if(top -> left != NULL)
			{
				top = top -> left ;
				while(top != NULL)
				{
					revorder.push(top) ;
					top = top -> right ;	
				}
			}
		} else {
			
			binarytreenode<int>* top = intop ;
			inorder.pop() ;
			count++ ;
			
			if(top -> right != NULL)
			{
				top = top -> right ;
				while(top != NULL)
				{
					inorder.push(top) ;
					top = top -> left ;
				}
			}
		}
		
		 

	}
}


int main()
{
	binarytreenode<int>* root = takeinput() ;
	int k ;
	cin>> k ;
	printnodes(root , k) ;
}
























