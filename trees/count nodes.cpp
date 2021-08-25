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

// funtion to take level wise input 

treenode<int>* takeinput()
{
	int rootdata ;
	cout<<"enter root data"<<endl ;
	cin>>rootdata ;
	
	// queue declared of type treenode
	
	treenode<int>* root = new treenode<int>(rootdata) ;
	queue<treenode<int>*> pendingnodes ;
	
	// root data pushed into queue at first
	
	pendingnodes.push(root) ;
	
	// runs until the queue is not empty
	
	while(pendingnodes.size()!=0)
	{
		treenode<int>* front = pendingnodes.front() ; // stores front of the queue
		pendingnodes.pop() ; // deleted that from pendignodes
		
		cout<<"enter the num of children"<<front -> data<<endl ;
		int numchild ;
		
		cin>>numchild ; // get the number of child nodes
		
		// iterrated over each child node to input it
		
		for(int i=0 ; i<numchild ; i++)
		{
			int childdata ;
			cout<<"Enter"<<i<<"ith child of"<<front -> data<<endl ;
			cin>>childdata ;
			
			treenode<int>* child = new treenode<int>(childdata) ;
			
			front -> children.push_back(child) ;
			pendingnodes.push(child) ;
		}
	 } 
	 
	 return root ;
	
}

int numnodes(treenode<int>* root)
{
	int ans = 1 ;
	
	for(int i=0 ; i< root -> children.size() ; i++)
	{
		ans += numnodes(root -> children[i]) ;
	}
	
	return ans ;
}

int main()
{
	treenode<int>* root = takeinput() ;
	
	int num = numnodes(root) ;
	
	cout<<"num of nodes is"<<" "<<num<<endl ;
}























