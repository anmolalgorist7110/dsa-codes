#include<bits/stdc++.h>
using namespace std ;

class trienode{
	
	public:
	
	char data ;
	trienode **children ;
	bool isterminal ;
	int childcount ;
	
	
	trienode(char data)
	{
		this -> data = data ;
		children = new trienode*[26] ;
		
		for(int i=0 ; i<26 ; i++)
		{
			children[i] = NULL ;
		}
		
		isterminal = false ;
		childcount =0 ;
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
	 
	 bool add(trienode* root , string word)
	 {
	 	// base case
	 	if(word.size() == 0)
	 	{
	 		if(!root -> isterminal)
	 		{
	 			root -> isterminal = true ;
	 			return true ;
			 } else
			 {
			 	return false ;
			 }
		 }
		 
		 // small calculation
		 int index = word[0] - 'a' ;
		 trienode* child ;
		 if(root -> children[index] != NULL)
		 {
		 	child = root ->children[index] ;
		 } else
		 {
		 	child = new trienode(word[0]) ;
		 	root -> children[index] = child ;
		 	root -> childcount++ ;
		 }
		 
		 // recursive call 
		 return add(child , word.substr(1)) ;
	 }
	 
	 // for user
	 void add(string word)
	 {
	 	if(add (root , word))
	 	{
	 		this -> count++ ;
		 }
	 }
	 
	 
	 /*-----------------------------------Palindrome Pair----------------------------------------*/
	 
	 
	 
	 // for string reverse
	 
	 string reverseword(string word)
	 {
	 	string reverse ="" ;
	 	for(int i=word.size()-1 ; i>=0 ; i-- )
	 	{
	 		reverse = reverse+ word[i] ;
		 }
		 
		 return reverse ;
	 }
	 
	 bool ispalindromicpair(vector<string> words)
	 {
	 	if(words.size() == 0)
	 	{
	 		return false ;
		 }
		 
		 for(int i=0 ; i<words.size() ; i++)
		 {
		 	add(reverseword(words[i])) ;
		 }
		 
		 return ispalindromicpair(root , words) ;
	 }
	 
	 bool ispalindromicpair(trienode* root , vector<string> words)
	 {
	 	if(words.size() == 0)
	 	{
	 		return false ;
		 }
		 
		 for(int i=0 ; i<words.size() ; i++)
		 {
		 	if(doespairexistfor(root , words[i] , 0))
		 	{
		 		return true ;
			 }
		 }
		 
		 return false ;
	 }
	 
	 bool doespairexistfor(trienode* root ,string word , int startindex)
	 {
	 	if(word.length() == 0)
	 	{
	 		return true ;
		 }
		 
		 if(startindex == word.length())
		 {
		 	if(root -> isterminal)
		 	{
		 		return true ;
			 }
			 
			 return checkre(root ,"") ;
		 }
		 
		 int charindex = word[startindex] - 'a' ;
		 
		 trienode* child = root -> children[charindex] ;	
		 
		 if(child == NULL)
		 {
		 	if(root -> isterminal)
		 	{
		 		return checkwordforpalin(word.substr(startindex)) ;
			 }
			 
			 return false ;	
		 }
		 
		 doespairexistfor(child , word , startindex+1) ;
	 }
	 
	 
	 bool checkre(trienode* root , string word)
	 {
	 	if(root -> isterminal)
	 	{
	 		if(checkwordforpalin(word))
	 		{
	 			return true ;
			 }
		 }
		 
		 for(int i=0 ; i<26 ; i++)
		 {
		 		trienode* child = root -> children[i] ;
		 		
		 		if(child == NULL)
		 		{
		 			continue ;
				 }
				 
				 string fwd = word + child-> data ;
				 
				 if(checkre(child , fwd))
				 {
				 	return true ;
				 }
		 }
		 
		 return false ;
	 }
	 
	 bool checkwordforpalin(string word)
	 {
	 	int startindex =0 ;
	 	int endindex = word.length() - 1 ;
	 	
	 	while(startindex < endindex)
	 	{
	 		if(word[startindex]!= word[endindex])
	 		{
	 			return false ;	
			 }
			 
			 startindex += 1 ;
			 endindex -= 1 ;
		 }
		 
		 return true ;
	 }
};


























int main()
{
	trie t ;
	int n ;
	
	cin>>n ;
	vector<string> words(n) ;
	
	
	for(int i=0 ; i<n ; i++)
	{
		cin>>words[i] ;
	}
	
	
	cout<<(t.ispalindromicpair(words) ? "true":"false") ;
	
}
