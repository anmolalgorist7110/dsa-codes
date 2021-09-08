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



void converttoarray(binarytreenode<int>* root , vector<int> &output)
{
	if(root == NULL)
	{
		return ;
	}
	
	output.push_back(root -> data) ;
	converttoarray(root -> left , output) ;
	converttoarray(root -> right , output) ;
	
}


void pairsum(binarytreenode<int>* root , int sum){
	vector<int> output ;
	converttoarray(root , output) ;
	
	sort(output.begin() , output.end()) ;
	
	int i=0 , j = output.size() -1  ;
	
	while(i < j)
	{
		if(output[i] + output[j] == sum)
		{
			cout<<output[i]<<" "<<output[j]<<endl ;
			++j ;
			++i ;
		} else if(output[i] + output[j] > sum)
		{
			--j ;
		} else
		{
			++i ;	
		}
	}
}

int main()
{
	binarytreenode<int>* root = takeinput() ;
	int sum ;
	cin>>sum ;
	pairsum(root , sum) ;
}






















