#include<bits/stdc++.h>
using namespace std ;

void Ksortedarray(int input[] , int n , int k)
{
	priority_queue<int> q ;
	
	for(int i=0 ; i<k ; i++)
	{
		q.push(input[i]) ;
	}
	
	int j=0 ; 
	
	for(int i=k  ; i<n ; i++)
	{
		input[j] = q.top() ;
		q.pop() ;
		q.push(input[i]) ;
		j++ ;
	}
	
	while(!q.empty())
	{
		input[j] = q.top() ;
        q.pop()	;	
	}
	
}

int main()
{
	int input[] = {10 , 12 , 6 , 7 , 9} ;
	int k=3 ;
	Ksortedarray(input , 5 , k) ;
	for(int i=0  ; i<5 ; i++)
	{
		cout<<input[i]<<" " ;
		
	}
}
















