#include<bits/stdc++.h>
using namespace std ;


class trienode{
	public:
		char data ;
		trienode** children ;
		bool isterminal ;
		
		trienode(char data)
		{
			this -> data = data ;
			children = new trienode*[26] ;
			for(int i=0 ; i<26 ; i++)
			{
				children[i] = NULL ;
			}
			
			isterminal = false ;
		}
};

class trie{ 
 
   trienode* root ;
   
   public:
   	
   	trie()
   	{
   		root = new trienode('\0') ;
	   }
	   
	   
	   
	   // searching that word if  present true otherwise false ;
	   bool search(trienode* root , string word)
	   {
	   	if(word.size() == 0)
	   	{
	   		return root -> isterminal ;
		   }
		   
		   
		   // small calculation
		   int index = word[0] - 'a' ;
		   trienode* child ;
		   
		   if(root -> children[index] != NULL)
		   {
		   		child = root -> children[index] ;
		   } else
		   {
		   	return false ;
		   }
		   
		   
		   // recursive call
		   return search(child , word.substr(1)) ;
	   }
	   
	   bool search(string word)
	   {
	   	return search(root , word) ;
	   }
      
      
      
      
      // insert the word
      void insertword(trienode* root ,string word)
      {
      	// base case
      	if(word.size() == 0)
      	{
      		root -> isterminal = true ;
      		return ;
		  }
		  
		  
		  // small calculation
		  int index = word[0] - 'a' ;
		  trienode* child ;
		  if(root -> children[index] != NULL)
		  {
		  	child = root -> children[index] ;
		  } else
		  {
		  	child = new trienode(word[0]) ;
		  	root -> children[index] = child ;
		  }
		  
		  // recursive call
		  insertword(child , word.substr(1)) ;
	  }
	  
	  // for user
	  void insertword(string word)
	  {
	  	insertword(root , word) ;
	  }
	  
	  // remove the word
	  void removeword(trienode* root , string word)
	  {
	  	// base case
	  	if(word.size() == 0)
	  	{
	  		root -> isterminal = false ;	
	  		return 	;
		  }
		  
		  // small calculation
		  trienode* child ;
		  int index = word[0] - 'a' ;
		  if(root -> children[index] != NULL)
		  {
		  	child = root -> children[index] ;
		  } else {
		  	// word not found
		  	return ;
		  }
		  
		  
		  // recursive call 
		  removeword(child , word.substr(1)) ;
		  
		  // remove child node if it is useless
		  if(child -> isterminal == false)
		  {
		  	for(int i=0 ; i<26 ; i++)
		  	{
		  		if(child -> children[i]!=NULL)
		  		{
		  			return ;
				  }
			  }
			  
			  delete child ;
			  root -> children[index] = NULL ;
		  }
	  }
	  
	  // for user
	  void removeword(string word)
	  {
	  	removeword(root , word) ;
	  }
	  
 
};


int main()
{
	trie t ;
	t.insertword("and") ;
	t.insertword("are") ;
	
	
	cout<<t.search("and")<<endl ;
	
	t.removeword("and") ;
	cout<<t.search("and")<<endl ;
}
















