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
		treenode<int>* front = pendingnodes.front() ; //stores front of the queue
		
		pendingnodes.pop() ; // deleted that node from queue
		
		cout<<"Enter the num of children of"<<" "<<front -> data<<endl ;
		int numchild ;
		cin>>numchild ; // get the number of child nodes
		
		// iterated over each child node to input it
		for(int i=0 ; i<numchild ; i++)
		{
			int childdata ;
			cout<<"enter"<<" "<<i<<"ith child of"<<front -> data<<endl ;
			cin>>childdata ;
			
			treenode<int>* child = new treenode<int>(childdata) ;
			front -> children.push_back(child) ;
			
			// each child nodes is pushed into the queue as well as the list of child nodes as it is taken input so that next time we can
			//take its children as input while we kept moving in the level wise fashion
			
			pendingnodes.push(child) ;
		}
		
	}
	
	return root ;
}

// print level wise

void printtree(treenode<int>* root)
{
	queue<treenode<int>*> pendingnodes ;
	pendingnodes.push(root) ;
	
	while(!pendingnodes.empty())
	{
		treenode<int>* front = pendingnodes.front() ;
		pendingnodes.pop() ;
		
		cout<<front -> data<<":" ;
		
		for(int i=0 ; i< front -> children.size() ; i++)
		{
			if(i<((front -> children.size()) - 1))
			{
				cout<<front -> children[i] -> data<<"," ;
			}
			else
			{
				cout<<front -> children[i] ->data ;
			}
			
			pendingnodes.push(front -> children[i]) ;
		}
		
		cout<<endl ;
	}
}

int main()
{
	treenode<int>* root = takeinput() ;
	printtree(root) ;
}




























