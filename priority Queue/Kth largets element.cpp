#include<bits/stdc++.h>
#include<queue>
using namespace std ;


int klarge(int* arr , int n , int k)
{
	   priority_queue<int, vector<int>, greater<int>> p;
	   
	   for(int i=0 ; i<k ; i++)
	   {
	   	p.push(arr[i]) ;
	   }
	   
	   for(int j=k ; j<n ; j++)
	   {
	   	if(p.top() < arr[j])
	   	{
	   		p.pop() ;
	   		p.push(arr[j]) ;
		   }
	   }
	   
	   return p.top() ;
}


int main()
{
	int n ;
	cin>>n ;
	
	int *arr = new int[n] ;
	
	for(int i=0 ; i<n ; i++)
	{
		cin>>arr[i] ;
	}
	
	int k ;
	cin>>k ;
	
	cout<<klarge(arr , n , k) ;
	
	delete [] arr ;
}
