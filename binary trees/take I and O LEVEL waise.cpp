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
	
	queue<binarytreenode<int>*> pendingnodes ;
	pendingnodes.push(root) ;
	
	
	while(!pendingnodes.empty())
	{
		binarytreenode<int>* frontnode = pendingnodes.front() ;
		pendingnodes.pop() ;
		
		
		// if there is no child 
		if(frontnode == NULL)
		{
			cout<<endl ;
			
			if(!pendingnodes.empty())
			{
				pendingnodes.push(NULL) ;
			}
		}
		
		else
		{
			cout<<frontnode -> data<<":" ;
			
			// printing the left child of the node
			cout<<"L:" ;
			
			if(frontnode -> left)
			{
				pendingnodes.push(frontnode -> left) ;
				cout<<frontnode -> left -> data<<";" ;
			} else
			{ 
			  cout<<-1<<"," ;
			}
			
			// priting the right child of the node
			
			cout<<"R:" ;
			
			if(frontnode -> right)
			{
				pendingnodes.push(frontnode -> right) ;
				cout<<frontnode -> right -> data<<endl ;
			}
			else
			{
				cout<<-1<<endl ;
			}
		}
	}
}

int main()
{
	binarytreenode<int>* root = takeinput() ;
	print(root) ;
	delete root ;
}






















