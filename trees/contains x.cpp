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

bool isp(treenode<int>* root , int x)
{
	queue<treenode<int>*> q ;
	q.push(root) ;
	
	while(!q.empty())
	{
		treenode<int>* p = q.front() ;
		q.pop() ;
		
		
		if(p -> data == x)
		{
			return true ;
		}
		
		for(int i=0 ; i< p -> children.size() ; i++)
		{
			q.push(p -> children[i]) ;
		}
	}
	
	return false ;
}


int main ()
{
	
	treenode<int>* root = takeinput() ;
	int x ;
	cin>>x ;
	cout << (isp(root, x) ? "true" : "false");
}
















