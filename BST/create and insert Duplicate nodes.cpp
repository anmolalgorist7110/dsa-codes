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
				break ;
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

void insert(binarytreenode<int>* root)
{
	if(root == NULL)
	{
		return ;
	}
	
	insert(root -> left) ;
	insert(root -> right) ;
	
	
	binarytreenode<int>* path = root -> left;
	
	binarytreenode<int>* newnode = new binarytreenode<int> (root -> data) ;
	
	
	root -> left = newnode  ;
	newnode -> left = path ;
	
	}


int main()
{
	binarytreenode<int>* root = takeinput() ;
	insert(root) ;
	print(root) ;
}




















































