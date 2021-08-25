#include<bits/stdc++.h>
using namespace std ;

template<typename T> 

class treenode{
	public:
		T data ;
		vector<treenode<T>*> children ;
		
		treenode(T data)
		{
			this -> data = data ;
		}
};

// input fuction that returns root node after taking input

treenode<int>* takeinput()
{
	int rootdata ; // to store data
	
	cout<<"enter data"<<endl ;
	cin>> rootdata ;
	
	// dynamically created a root node and intialized with constructor
	
	treenode<int>* root = new treenode<int>(rootdata) ;
	
	int n ; // to store the no of children of the node
	cout<<"Enter num of children of"<<" "<<rootdata<<endl ;
	
	cin>> n ;
	
	for(int i=0 ; i<n ; i++)
	{
		// input taken recurisvely for each child node of the current node
		treenode<int>* child = takeinput() ;
		
		// each child node is inserted into the list of children nodes
		root -> children.push_back(child) ;
	}
	
	return root ;
	
}

// function to print the tree  that takes the root as its argument

void printtree(treenode<int>* root)
{
	// edge case
	
	if(root == NULL)
	{
		return ;
	}
	
	cout<< root -> data<<":" ;
	
	// terversing over the vector of its child nodesa nd printing each of it
	
	for(int i=0 ; i< root-> children.size() ; i++)
	{
		cout<<root -> children[i] -> data<<"," ;
	}
	
	cout<<endl ;
	
	// now recursively calling print function over each child
	
	for(int i=0 ; i< root -> children.size() ; i++)
	{
		printtree(root -> children[i]) ;
	}
}

int main(){
	treenode<int>* root = takeinput() ;
	printtree(root) ;
}

















































