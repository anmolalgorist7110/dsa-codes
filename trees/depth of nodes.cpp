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

void print(treenode<int>* root , int k)
{
	if(root == NULL)
	{
		return ;
	}
	
	if(k==0)
	{
		cout<<root -> data<<endl ;
		return ;
	}
	
	for(int i=0 ; i< root -> children.size() ; i++)
	{
		print(root -> children[i] , k-1) ;
	}

}

int main()
{
	int  k ;
	cin>> k ;
	treenode<int>* root = takeinput() ;
	print(root , k) ;
	
	
}






























	
