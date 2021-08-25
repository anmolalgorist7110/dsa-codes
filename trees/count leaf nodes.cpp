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



treenode<int>* takeinput()
{
	int rootdata ;
	cout<<"Enter root data"<<endl ;
	cin>> rootdata ;
	
	treenode<int>* root = new treenode<int>(rootdata) ;
	queue<treenode<int>*> pendingnodes ;
	
	pendingnodes.push(root) ;
	
	while(pendingnodes.size()!=0)
	{
		treenode<int>* front = pendingnodes.front() ;
		pendingnodes.pop() ;
		
		cout<<"Enter the num of children"<<front -> data<<endl ;
		int numchild ;
		cin>> numchild ;
		
		for(int i=0 ; i<numchild ; i++)
		{
			int childdata ;
			cout<<"Enter"<<" "<<i<<"ith child of"<<front -> data<<endl ;
			cin>> childdata ;
			
			treenode<int>* child = new treenode<int>(childdata) ;
			
			front -> children.push_back(child) ;
			
			
			pendingnodes.push(child) ;
		}
	}
	
	return root ;
	
}


int count = 0 ;
int leafnodes(treenode<int>* root )
{
	if(root == NULL)
	{
		return 0 ;
	}
	
	if(root -> children.size() == 0)
	{
		count++  ;
	}
	
	for(int i=0 ; i< root -> children.size() ; i++)
	{
		  leafnodes(root -> children[i] , count) ;
	}
	 return count ;

}



int main()
{
	
	treenode<int>* root = takeinput() ;
	int ans = leafnodes(root ) ;
	
	cout<<"count is"<<ans<<endl ;
}



















