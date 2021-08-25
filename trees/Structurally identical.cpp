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



bool check(treenode<int>* root1 , treenode<int>* root2)
{
	if(root1 == NULL && root2 == NULL)
	{
		return true ;
	}
	
	if((root1 == NULL && root2!=NULL) || (root2 == NULL && root1!=NULL))
	{
		return false ;
	}
	
	if((root1 -> data != root2 -> data) || (root1 -> children.size() != root2 -> children.size()))
	{
		return false ;
	}
	
	int i = 0 ;
	
	
	while(i < root1 -> children.size())
	{
		treenode<int>* child1 = root1 -> children[i] ;
		treenode<int>* child2 = root2 -> children[i] ;
		
		if(check(child1 , child2))
		{
			i++ ;
		} else
		{ 
			return false ;
		}
	}
	
	return true ;
}

int main()
{
	treenode<int>* root1 = takeinput() ;
	treenode<int>* root2 = takeinput() ;
	
	cout << (check(root1, root2) ? "true" : "false");
}















