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

treenode<int>* get(treenode<int>* root)
{
	queue<treenode<int>*> q ;
	
	treenode<int>* large = new treenode<int>(0) ;
	treenode<int>* slarge ;
	
	if (root -> children.size() < 1)
	{
		return 0 ;
	}
	
	q.push(root) ;
	
	while(!q.empty())
	{
		if( q.front() -> data > large -> data)
		{
			slarge = large  ;
			large = q.front() ;
		} else if(q.front() -> data > slarge -> data) 
		{
			if ( q.front() -> data != large -> data)
			slarge =  q.front() ;
			else 	
		 return NULL ;
		} 
		
			for(int i=0 ; i < root -> children.size() ; i++)
	{
		q.push(root -> children[i]) ;
	}
	
	q.pop() ;
	root = q.front() ;
	}
	
return slarge ;

}

int main()
{
	treenode<int>* root = takeinput() ;
	treenode<int>* ans = get(root) ;
	
	cout<<"ANSER IS"<<" "<<ans -> data<<endl ;
}

















