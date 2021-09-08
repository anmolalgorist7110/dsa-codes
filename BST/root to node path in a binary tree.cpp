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

vector<int>* getPath(binarytreenode<int>* root , int data)
{
	if(root == NULL)
	{
		return NULL ;
	}
	
	if(root -> data == data)
	{
		vector<int>* output = new vector<int>() ;
		output -> push_back(root -> data) ;
		return output ;
	}
	
	vector<int>* leftoutput = getPath(root -> left , data) ;
	
	if(leftoutput != NULL)
	{
		leftoutput -> push_back(root -> data) ;
		return leftoutput ;
	}
	
	vector<int>* rightoutput = getPath(root -> right , data) ;
	
	if(rightoutput != NULL)
	{
		rightoutput -> push_back(root -> data) ;
		return rightoutput ;
	} else
	{
		return NULL ;
	}
}


int main()
{
	binarytreenode<int>* root = takeinput() ;
	int data ;
	cin>>data ;
	vector<int>* output = getPath(root , data ) ;
	
	for(int i=0 ; i< output -> size() ; i++)
	{
		cout<<output -> at(i)<<" ";
	}
	
	delete output ;
	
}


























