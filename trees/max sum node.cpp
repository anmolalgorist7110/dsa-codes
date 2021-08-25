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

treenode<int>* maxsum(treenode<int>* root)
{
	queue<treenode<int>*> q ;
	stack<treenode<int>*> s ;
	
	int large =  0 ;
	q.push(root) ;
	
	while(!q.empty())
	{
		int maxsum = q.front() -> data  ;
		
		for(int i=0 ; i < root -> children.size() ;  i++)
		{
			q.push(root -> children[i]) ;
			maxsum += root -> children[i] -> data ;
		}
		
		if(maxsum > large)
		{
			s.push(q.front()) ; // we are pushing the node here so on the top there will be node with conating the ans
			large = maxsum  ;
		}
		
		q.pop() ;
		root = q.front() ;
		
		
	}
	
	return s.top() ;
}


int main()
{
	treenode<int>* root = takeinput() ;
	
	treenode<int>* ans = maxsum(root) ;
	
	cout<<"the answer is"<<ans -> data<<endl ;
}

















