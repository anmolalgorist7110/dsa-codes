#include<bits/stdc++.h>
using namespace std ;

template<typename T>

class binarytreenode
{
	public: 
	
	T data ;
	binarytreenode* left ;
	binarytreenode* right ;
	
	binarytreenode(T data)
	{
		this -> data = data ;
		left = NULL ;
		right = NULL ;
	}
	
	~binarytreenode()
	{
		delete left ; 
		delete right ;
	}
	
};


binarytreenode<int>* takeinput()
{
	int rootdata ;
	cout<<"enter the root data"<<endl ;
	
	cin>> rootdata ;
	
	if(rootdata == -1)
	{
		return NULL ;
	}
	
	binarytreenode<int>* root = new binarytreenode<int>(rootdata) ;
	
	queue<binarytreenode<int>*> pendingnodes ;
	
	pendingnodes.push(root) ;
	
	while(pendingnodes.size()!=0)
	{
	   binarytreenode<int>* front = pendingnodes.front() ;
	   
	   pendingnodes.pop() ;
	   
	   cout<<"Enter the left child of"<<" "<<front -> data<<endl ;
	   
	   // takeing input of left child
	   
	   int leftchilddata ;
	   cin>>leftchilddata ;
	   
	   if(leftchilddata != -1)
	   {
	   	 binarytreenode<int>* child = new binarytreenode<int>(leftchilddata) ;
	   	 front -> left = child ;
	   	 pendingnodes.push(child) ;
	   }
	   
	   cout<<"Enter the right child of"<<" "<<front -> data<<endl ;
	   int rightchilddata ;
	   cin>>rightchilddata ;
	   
	   // taking input of right child of the node
	   
	   if(rightchilddata!=-1)
	   {
	   	
	   	binarytreenode<int>* child = new binarytreenode<int>(rightchilddata) ;
	   	front -> right  = child ;
	   	pendingnodes.push(child) ;
	   	
	   }
	}
	
	return root ;
}


binarytreenode<int>* remove(binarytreenode<int>* root)
{
	if(root == NULL || (root -> left == NULL && root -> right == NULL))
	{
		return NULL ;
	}
	
	root -> left = remove(root -> left) ;
	root -> right = remove(root -> right) ;
	
	return root ;
}

void printLevelWise(binarytreenode<int> *root){
	if(root == NULL)
        return;
    queue <binarytreenode<int>*> q;
    q.push(root);
    q.push(NULL);    //to donate level completion
    
    while(!q.empty()){
        
        binarytreenode<int> *front = q.front();
        q.pop();
        
        if(front == NULL){
        
            if(q.empty())
                break;
                // return;
            
            else{
                cout << endl;
                q.push(NULL);
            }
        }
        
        else{
            // just print the value of front -> data
            
            cout << front -> data << " ";
            
            if(front -> left != NULL)
                q.push(front -> left);
            if(front -> right != NULL)
                q.push(front -> right);
                
        }
    }
}

int main()
{
	binarytreenode<int>* root = takeinput() ;
	remove(root) ;
	printLevelWise(root) ;
}




















