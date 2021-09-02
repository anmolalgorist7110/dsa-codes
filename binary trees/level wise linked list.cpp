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


template<typename T>

class node{
	public:
		T data ;
		node<T>*  next ;
		
		node(T data)
		{
			this -> data = data ;
			this -> next = NULL ;
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


void print(node<int>* head)
{
	node<int>* temp = head ;
	
	while(temp != NULL)
	{
		cout<<temp -> data<<" " ;
		temp = temp -> next ;
	}
	
	cout<<endl ;
}

vector<node<int>*> construct(binarytreenode<int>* root)
{
	// if the root is null
	if(root == NULL)
	{
		vector<node<int>*> output ;
		output.push_back(NULL) ;
		return output ;
	}
	
	queue<binarytreenode<int>*> q ;
	q.push(root) ;
	
	int levelrem = 1 ;
	int nextlevel = 0 ;
	
	// output vector which contains head of each level 
	vector<node<int>*> output ;
	
	// head of the current level 
	node<int>* currlevelhead = NULL ;
	
	// tail of the current level 
	node<int>* currleveltail = NULL ;
	
	
	while(!q.empty())
	{
		binarytreenode<int>* first = q.front() ;
		q.pop() ;
		
		node<int>* newnode = new node<int>(first -> data) ;
		
		
		// making the linkelist level wise which is same as what we did in the insertion of lL
		if(currlevelhead == NULL)
		{
			currlevelhead = newnode  ;
			currleveltail = newnode ;
		} else
		{
			currlevelhead -> next = newnode ;
			currleveltail = newnode ;
		}
		
		
		
		if(first -> left != NULL)
		{
			q.push(first -> left) ;
			nextlevel ++ ;
		}
		
		
		if(first -> right != NULL)
		{
			q.push(first -> right) ;
			nextlevel ++ ;
		}
		
		
		levelrem -- ;
		
		if(levelrem == 0)
		{
			output.push_back(currlevelhead) ;
			currlevelhead = NULL ;
			currleveltail = NULL ;
			levelrem = nextlevel ;
			nextlevel = 0 ;
		}
	}
	
	
	return output ;
	
	
	
}

int main()
{
	binarytreenode<int>* root = takeinput() ;
	vector<node<int>*> ans = construct(root) ;
	
	
	for(int i=0 ; i < ans.size() ; i++)
	{
		print(ans[i]) ;
	}
}
































