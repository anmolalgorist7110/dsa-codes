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
  	int count ;
  	
  	trie()
  	{
  		this -> count = 0 ;
  		root = new trienode('\0') ;
	  }
	  
	  bool insertword(trienode* root , string word)
	  {
	  	// base case 
	  	if(word.size() == 0)
	  	{
	  		if(!root -> isterminal)
	  		{
	  			root -> isterminal = true ;
	  			return true;
			  } else {
			  	return false ;
			  }
		  }
		  //small calcultion
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
		  return insertword(child ,word.substr(1)) ;
	  }
	  // for user
	  void insertword(string word)
	  {
	  	if(insertword( root ,  word))
	  	{
	  		this -> count++ ;
		  }
	  }
	  
	  
	  bool search(trienode* root , string word)
	  {
	  	if(word.size() == 0)
	  	{
	  		return true ;
		  } 
		  
		  int index = word[0] -'a' ;
		  
		  if(root -> children[index] != NULL)
		  {
		  	return search(root -> children[index] , word.substr(1)) ;
		  } else 
		  {
		  	return false ;
		  }
		  
		  
	  }
	  // for user
	  bool search(string word)
	  {
	  	return search(root , word) ;
	  }
	  
	  
	  bool patternmatch(vector<string> vect , string pattern)
	  {
	  	for(int i=0 ; i<vect.size() ; i++)
	  	{
	  		for(int j=0 ; j<vect[i].size() ; j++)
	  		{
	  			insertword(vect[i].substr(j)) ;
			  }
			  
			  if(search(pattern))
			  {
			  	return true ;
			  }
			  
			  
		
		  }
		  
		  return false ;
	  }
	  
	  
	  
	  
};

int main()
{
	trie t ;
	int n ;
	cin>>n ;
	string pattern ;
	vector<string> vect ;
	
	for(int i=0 ; i<n ; i++)
	{
		string word ;
		cin>>word ;
		vect.push_back(word) ;
	}
	
	cin>>pattern ;
	
	
	cout<<(t.patternmatch(vect , pattern) ? "true" : "false") ;
}
















