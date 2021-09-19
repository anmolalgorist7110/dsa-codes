#include<bits/stdc++.h>
using namespace std ;


string unichar(string str)
{
	int len = str.length() ;
	if(len == 0)
	{
		char *ans = new char[1] ;
		ans[0] = '\0' ;
		return ans ;
	}
	
	char *ans = new char[len+1] ;
	unordered_map<int,int> hm ;
	int i=0 ; 
	
	for(int currindex =0 ; currindex < len ; currindex++)
	{
		char currchar = str[currindex] ;
		if(hm.count(currchar) == 0)
		{
			hm[currchar] = true ;
			ans[i++] = currchar ;
		}
	}
	
	ans[i] = '\0' ;
	return ans ;
}

int main()
{
	string str ;
	cin>>str ;
	
	cout<<unichar(str)<<endl ;	
}
