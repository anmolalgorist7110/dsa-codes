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



treenode<int>* get(treenode<int>* root , int n)
{
	treenode<int>* ans = NULL ;
	
	if(root -> data > n) // we are just storing the addr of elemnet which is largger than n (NOT just larger)
	{
		ans = root ;
	}
	
	for(int i=0 ; i< root -> children.size() ; i++)
	{
		treenode<int> *temp =  get(root -> children[i] , n) ;
		
		// time to decide the just next larger 
		
		if(ans == NULL)
		{
			ans = temp ;
		} else if(temp!=NULL and temp -> data < ans -> data)
		{
			ans = temp ; 
		 } 
	}
	
	return ans  ;
	
	
}

int main()
{
	treenode<int>* root = takeinput() ;
	int x ;
	cin>> x ;
	treenode<int>* ans = get(root , x) ;
	
	cout<<"  answer is "<<" "<<ans -> data<<endl ;
}















