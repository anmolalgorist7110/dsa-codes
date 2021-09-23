#include<bits/stdc++.h>
using namespace std ;

class trienode{
	public:
		char data ;
		trienode** children ;
		bool isterminal ;
		
		
		trienode(char data)
		{
			this -> data = data  ;
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
			this -> count =0 ;
			root = new trienode('\0') ;
		}
		
		
		bool insertword(trienode* root ,string word)
		{
				// base case
				
				if(word.size() == 0)
				{
					if(!root -> isterminal)
					{
						root -> isterminal = true ;
						return true ;
					} else{
						return false ;
					}
				}
				
				//small calculation
				int index = word[0] - 'a' ;
				trienode* child ;
				
				if(root -> children[index] != NULL)
				{
					child = root -> children[index] ;	
				} else
				{
					child  = new trienode(word[0]) ;
					root -> children[index] = child ;
				}
				
				// recursive call
				return insertword(child , word.substr(1) ) ;
		}
		
		
		// for user 
		void insertword(string word)
		{
			if(insertword(root , word))
			{
				this -> count++ ;
			}
		}
		
		//////////////////////////////////////////////////////////////////////find node////////////////////////////////////////
		
		
		trienode* searchnode(trienode* root , string word)
		{
		    if(word.size() == 0)
			return	root  ;
			
			int index = word[0] - 'a' ;
			
			if(root -> children[index] != NULL)
			{
				return searchnode(root -> children[index] , word.substr(1)) ;
				}	
		}
		
		// for user
		trienode* searchnode(string word)
		{
			return searchnode(root , word) ;
		}
		
		///////////////////////////////////////////// if isterminal is true then print/////////////////////////////
		void search(trienode* root ,string word)
		{
			if(root == NULL)
			{
	            return ;
			}
			
			if(root -> isterminal)
			{
				cout<<word<<endl ;
			}
			
			
			for(int i=0 ; i<26 ; i++)
			{
				if(root -> children[i] != NULL)
				{
					search(root -> children[i] , word + root -> children[i] -> data) ;	 
				}
			}
		}	
		
		
		void autocomplete(vector<string> input ,string pattern)
		{
			// insert each word in trie
			for(int i=0 ; i<input.size() ; i++)
			{
				insertword(input[i]) ;

			}
			
				/////////find node of the last char of the word////////////////////
				trienode* temp = searchnode(pattern) ;
				
				//////////search all possible word from above word/////////////
				search(temp , pattern) ;
		}
};


int main()
{
	trie t ;
	int n ;
	cin>>n ;
	
	vector<string> vect ;
	
	
	for(int i=0 ; i<n ; i++)
	{
		string word ;
		cin>>word ;
		vect.push_back(word) ;
	}
	
	string pattern ;
	cin>>pattern ;
	
	
	t.autocomplete(vect , pattern) ;

}
