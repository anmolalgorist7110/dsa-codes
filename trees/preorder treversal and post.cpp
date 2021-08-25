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

 // in preorder treversal we visit teh current node first Starting with the root and then we traverse the left subtree 
 
 void printPreOrder(treenode<int>* root)
 {
 	if(root == NULL)
 	{
 		return  ;
	 }
	 
	 cout<<root -> data<<" " ;
	 
	 
	 for(int i=0 ; i< root -> children.size() ; i++)
	 {
	 	printPreOrder(root -> children[i]) ;
	 }
	 
			}           
             
             // in post order traversal we visit all the child nodes first (from left to right order) and then we visit the current node
             
             
        void  printPostOrder(treenode<int>* root)
		{
			if(root == NULL)
			{
				return ;
			}
			
			for(int i=0 ; i< root -> children.size() ; i++)
			{
				printPostOrder(root -> children[i]) ;
			}
			
			cout<<root -> data<<" " ;
			
			
			}    
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             




int main() {
    treenode<int>* root = takeinput();
    printPostOrder(root);
    printPreOrder(root) ;
}
